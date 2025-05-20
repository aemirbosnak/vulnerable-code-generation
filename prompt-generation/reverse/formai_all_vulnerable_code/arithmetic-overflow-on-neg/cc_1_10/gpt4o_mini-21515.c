//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 0000

typedef struct {
    int day;
    int month;
    int year;
} Date;

void printDate(Date date) {
    printf("Current Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

int isValidDate(Date date) {
    if (date.year < MIN_YEAR || date.year > MAX_YEAR)
        return 0;
    if (date.month < 1 || date.month > 12)
        return 0;
    if (date.day < 1 || date.day > getDaysInMonth(date.month, date.year))
        return 0;
    return 1;
}

void timeTravel(Date *current_date, int years) {
    current_date->year += years;
    if (current_date->year < MIN_YEAR) {
        printf("Oops! You’ve gone too far back in time!\n");
        current_date->year = MIN_YEAR;
    } else if (current_date->year > MAX_YEAR) {
        printf("Whoa! Time travel to the future is not available!\n");
        current_date->year = MAX_YEAR;
    }

    // Adjust for end of month
    if (!isValidDate(*current_date)) {
        current_date->day = getDaysInMonth(current_date->month, current_date->year);
        printf("Adjusting to valid date: %02d/%02d/%04d\n", current_date->day, current_date->month, current_date->year);
    }
}

void displayMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Get Current Date\n");
    printf("2. Travel to a Specific Year\n");
    printf("3. Travel Ahead in Time\n");
    printf("4. Travel Back in Time\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Date current_date;
    time_t now;
    struct tm *tm_info;

    // Get the current date
    time(&now);
    tm_info = localtime(&now);
    current_date.day = tm_info->tm_mday;
    current_date.month = tm_info->tm_mon + 1; // tm_mon is 0-11
    current_date.year = tm_info->tm_year + 1900; // tm_year is years since 1900

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printDate(current_date);
                break;
            case 2:
                printf("Enter target year (YYYY): ");
                int target_year;
                scanf("%d", &target_year);
                if (target_year < MIN_YEAR || target_year > MAX_YEAR) {
                    printf("Invalid year! Choose between %d and %d.\n", MIN_YEAR, MAX_YEAR);
                } else {
                    current_date.year = target_year;
                    printf("Traveling to year %d...\n", current_date.year);
                }
                break;
            case 3:
                printf("Enter number of years to travel into the future: ");
                int future_years;
                scanf("%d", &future_years);
                timeTravel(&current_date, future_years);
                break;
            case 4:
                printf("Enter number of years to travel back in time: ");
                int past_years;
                scanf("%d", &past_years);
                timeTravel(&current_date, -past_years);
                break;
            case 5:
                printf("Exiting... Safe travels!\n");
                break;
            default:
                printf("Please choose a valid option!\n");
        }
    } while (choice != 5);
    
    return 0;
}