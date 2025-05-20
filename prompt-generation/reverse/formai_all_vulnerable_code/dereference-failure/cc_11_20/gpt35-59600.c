//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_YEAR 1900
#define MAX_YEAR 2100
#define DAY_MONTHS 12
#define MONTH_DAYS 31

void time_travel(int day, int month, int year);

int main() {
    int day, month, year;

    // get current time
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    day = tm->tm_mday;
    month = tm->tm_mon + 1;
    year = tm->tm_year + 1900;

    printf("\nWelcome to the Time Travel Simulator!");
    printf("\n\nYou are currently in the year %d, month %d, day %d.\n", year, month, day);

    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Travel to a specific date\n");
        printf("2. Travel to a random date\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter a date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &day, &month, &year);
                time_travel(day, month, year);
                break;
            case 2:
                srand(time(NULL));
                day = rand() % MONTH_DAYS + 1;
                month = rand() % DAY_MONTHS + 1;
                year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
                printf("\nYou've traveled to a random date: %d/%d/%d\n", day, month, year);
                time_travel(day, month, year);
                break;
            case 3:
                printf("\nThank you for using the Time Travel Simulator!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

void time_travel(int day, int month, int year) {
    int valid_date = 1;

    // check if year is within range
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("\nError: Year out of range!\n");
        valid_date = 0;
    }

    // check if month is within range
    if (month < 1 || month > 12) {
        printf("\nError: Month out of range!\n");
        valid_date = 0;
    }

    // check if day is within range
    if (day < 1 || day > MONTH_DAYS) {
        printf("\nError: Day out of range!\n");
        valid_date = 0;
    } else if ((day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
                || (day >= 30 && month == 2)
                || (day >= 29 && month == 2 && (year % 400 != 0 && (year % 4 != 0 || year % 100 == 0)))) {
        printf("\nError: Invalid day for the given month and year!\n");
        valid_date = 0;
    }

    // if date is valid, proceed
    if (valid_date) {
        printf("\nYou have successfully traveled to the date: %d/%d/%d!\n", day, month, year);
        printf("Press any key to continue...");
        getchar();
    }
}