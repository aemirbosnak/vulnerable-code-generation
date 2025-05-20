//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date currentDate;
    Date timeMachineDate;
} TimeMachine;

void displayDate(Date date) {
    printf("Date: %04d-%02d-%02d\n", date.year, date.month, date.day);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

void addDays(Date *date, int days) {
    date->day += days;
    while (date->day > daysInMonth(date->year, date->month)) {
        date->day -= daysInMonth(date->year, date->month);
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

void subtractDays(Date *date, int days) {
    date->day -= days;
    while (date->day < 1) {
        date->month--;
        if (date->month < 1) {
            date->month = 12;
            date->year--;
        }
        date->day += daysInMonth(date->year, date->month);
    }
}

void travelInTime(TimeMachine *tm) {
    int choice, days;
    printf("\nTime Travel Menu:\n");
    printf("1. Travel to a Future Date\n");
    printf("2. Travel to a Past Date\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter number of days: ");
    scanf("%d", &days);

    if (choice == 1) {
        addDays(&tm->timeMachineDate, days);
    } else if (choice == 2) {
        subtractDays(&tm->timeMachineDate, days);
    } else {
        printf("Invalid choice!\n");
        return;
    }

    printf("\nYou have traveled to:\n");
    displayDate(tm->timeMachineDate);
}

void showCurrentDate(TimeMachine *tm) {
    printf("\nCurrent Date:\n");
    displayDate(tm->currentDate);
}

void initializeTimeMachine(TimeMachine *tm) {
    time_t t = time(NULL);
    struct tm *tmStruct = localtime(&t);

    tm->currentDate.year = tmStruct->tm_year + 1900;
    tm->currentDate.month = tmStruct->tm_mon + 1;
    tm->currentDate.day = tmStruct->tm_mday;

    tm->timeMachineDate = tm->currentDate;
}

void runTimeTravelSimulator() {
    TimeMachine tm;
    initializeTimeMachine(&tm);
    int exit = 0;

    while (!exit) {
        printf("\nTime Travel Simulator Main Menu:\n");
        showCurrentDate(&tm);
        printf("1. Travel in Time\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &exit);
        
        if (exit == 1) {
            travelInTime(&tm);
        } else if (exit != 2) {
            printf("Invalid option! Please choose again.\n");
            exit = 0; // Reset exit for repeat loop
        } 
    }

    printf("Exiting Time Travel Simulator. Goodbye!\n");
}

int main() {
    runTimeTravelSimulator();
    return 0;
}