#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date {
    int month;
    int day;
    int year;
};

int cal[12][2] = 
    {{1,31},  {2,28},  {3,31},
     {4,30},  {5,31},  {6,30},
     {7,31},  {8,31},  {9,30},
    {10,31}, {11,30}, {12,31}};

void printMenu();
void addDate();
void subDate();
void dateRange();
bool dateEquals(struct date a, struct date b);

int main(){
   int running = 1;
    int input;
    
    while(running){
        printMenu();
        scanf("%d", &input);
        
        switch (input){
            case 1: addDate(); break;
            case 2: subDate(); break;
            case 3: dateRange(); break;
            case 4: running = 0; break;
            default:
                printf("\n***           Invalid          ***\n"); break;
        }
    }
    
    //printf("%d", 2020 % 4);
    return 0;
}

void printMenu(){
    printf("\n***            Menu            ***\n");
    printf("*** 1.) Add days to a date     ***\n");
    printf("*** 2.) Subtract days from date***\n");
    printf("*** 3.) How many days in range ***\n");
    printf("*** 4.) Quit                   ***\n");
    printf("***        Selection: ");
}

void addDate(){
    struct date today;
    struct date future;
    int daysuntil, dayscounted, current;
    int monthdays;
    //int now;
    
    printf("\nStart date (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &today.month, &today.day, &today.year);
    future = today;
    
    printf("How many days to add: ");
    scanf("%d", &daysuntil);

    current = today.day;
    
    dayscounted = 0;
    while ( dayscounted < daysuntil ) {
        
        monthdays = cal[future.month-1][1];
        if (future.month == 2) { if ( future.year % 4 == 0) monthdays++; }
        
        while ( current < monthdays ) { // count until end of the month
            if (dayscounted == daysuntil) { break; }  // or EEEND OF THE LINE
            dayscounted++;
            future.day++;
            current = future.day;
        }  

        // go to next month
        if (dayscounted == daysuntil) { break; }
        future.month++;
        if (future.month > 12) { future.month = 1; future.year++; }
        future.day = 1;
        current = future.day;

        dayscounted++;
        
    }
    
    printf("Result: %d-%d-%d\n", future.month, future.day, future.year);
    
}

void subDate(){
    struct date today;
    struct date future;
    int daysuntil, dayscounted, current;
    int monthdays;
    //int now;
    
    printf("\nStart date (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &today.month, &today.day, &today.year);
    future = today;
    
    printf("How many days to subtract: ");
    scanf("%d", &daysuntil);

    current = today.day;
    
    dayscounted = 0;
    while ( dayscounted < daysuntil ) {
        
        monthdays = cal[future.month-1][1];
        if (future.month == 2) { if ( future.year % 4 == 0) monthdays++; }
        
        while ( current > 1 ) { // count until end of the month
            if (dayscounted == daysuntil) { break; }  // or EEEND OF THE LINE
            dayscounted++;
            future.day--;
            current = future.day;
        }  

        // go to next month
        if (dayscounted == daysuntil) { break; }
        future.month--;
        if (future.month < 1) { future.month = 12; future.year--; }
        future.day = cal[future.month-1][1];
        if (future.month == 2) { if ( future.year % 4 == 0) future.day++; }
        current = future.day;

        dayscounted++;
        
    }
    
    printf("Result: %d-%d-%d\n", future.month, future.day, future.year);
    
}

void dateRange(){
    struct date start;
    struct date end;
    struct date countd;
    
    int dayscounted, current;
    int monthdays;
    
    printf("\nStart date (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &start.month, &start.day, &start.year);
    countd = start;
    
    printf("End date (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &end.month, &end.day, &end.year);

    current = start.day;
    dayscounted = 0;
    int jan = 0;
    
    while ( !dateEquals(countd, end) ) {
        
        monthdays = cal[countd.month-1][1];
        if (countd.month == 2) { if ( countd.year % 4 == 0) monthdays++; }
        
        if (countd.month == 1) jan = 1;
        else jan = 0;
        
        while ( current < monthdays ) { // count until end of the month
            if ( dateEquals(countd, end)) { break; }  // or EEEND OF THE LINE
            dayscounted++;
            countd.day++;
            current = countd.day;
        }  

        // go to next month
        if ( dateEquals(countd, end) ) { break; }
        countd.month++;
        if (countd.month > 12) { countd.month = 1; countd.year++; }
        countd.day = 1;
        current = countd.day;

        dayscounted++;
        
    }
    
    printf("Result: %d\n", dayscounted);

}

bool dateEquals(struct date a, struct date b){
    return ( (a.day == b.day) && 
             (a.month == b.month) && 
             (a.year == b.year) );
}
