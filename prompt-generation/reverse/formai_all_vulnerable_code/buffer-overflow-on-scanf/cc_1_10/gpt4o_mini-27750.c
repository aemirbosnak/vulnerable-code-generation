//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 10000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date currentDate;
} TimeMachine;

void initializeTimeMachine(TimeMachine* tm, int year, int month, int day) {
    tm->currentDate.year = year;
    tm->currentDate.month = month;
    tm->currentDate.day = day;
}

void displayDate(const Date* date) {
    printf("Current Date: %04d-%02d-%02d\n", date->year, date->month, date->day);
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

void travelToYear(TimeMachine* tm, int year) {
    if (year < 0 || year > MAX_YEARS) {
        printf("Invalid year. Please choose a year between 0 and %d.\n", MAX_YEARS);
        return;
    }
    tm->currentDate.year = year;
    tm->currentDate.month = 1;  // Default to January
    tm->currentDate.day = 1;     // Default to day 1
    printf("Traveling to the year %d...\n", year);
}

void travelToDate(TimeMachine* tm, int year, int month, int day) {
    if (year < 0 || year > MAX_YEARS || month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month)) {
        printf("Invalid date.\n");
        return;
    }
    tm->currentDate.year = year;
    tm->currentDate.month = month;
    tm->currentDate.day = day;
    printf("Traveling to date %04d-%02d-%02d...\n", year, month, day);
}

void printMenu() {
    printf("\nTime Travel Simulator\n");
    printf("1. Travel to specific year\n");
    printf("2. Travel to specific date\n");
    printf("3. Display current date\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    TimeMachine tm;
    initializeTimeMachine(&tm, 2023, 10, 1); // Starting date

    int choice, year, month, day;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter year to travel to: ");
                scanf("%d", &year);
                travelToYear(&tm, year);
                break;
            case 2:
                printf("Enter date to travel to (YYYY MM DD): ");
                scanf("%d %d %d", &year, &month, &day);
                travelToDate(&tm, year, month, day);
                break;
            case 3:
                displayDate(&tm.currentDate);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}