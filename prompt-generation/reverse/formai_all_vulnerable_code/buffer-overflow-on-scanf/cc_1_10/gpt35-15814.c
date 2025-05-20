//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to calculate if the year is a leap year or not
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert the day of the month and month number to day of the year
int toDayOfYear(int day, int month, int year) {
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int dayOfYear = 0;

    for (int i = 1; i < month; i++) {
        dayOfYear += daysInMonth[i];

        if (i == 2) { // February
            if (isLeapYear(year)) {
                dayOfYear++;
            }
        }
    }

    dayOfYear += day;

    return dayOfYear;
}

// Function to convert the day of the year to day of the month and month number
void fromDayOfYear(int dayOfYear, int year, int *pMonth, int *pDay) {
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month = 1;
    int day = dayOfYear;

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    while (day > daysInMonth[month]) {
        day -= daysInMonth[month];
        month++;
    }

    *pDay = day;
    *pMonth = month;
}

int main() {
    int day, month, year;
    char date[12];
    char option;

    printf("Welcome to the Natural Language Date Converter!\n");

    do {
        printf("\nPlease enter a date in the following format: DD/MM/YYYY\n");
        scanf("%s", date);

        // Extract each component of the date
        char *token = strtok(date, "/");
        int count = 0;

        while (token != NULL) {
            if (count == 0) {
                day = atoi(token);
            } else if (count == 1) {
                month = atoi(token);
            } else {
                year = atoi(token);
            }
            token = strtok(NULL, "/");
            count++;
        }

        // Convert to day of year
        int dayOfYear = toDayOfYear(day, month, year);

        printf("The date %02d/%02d/%04d is day %d of the year %04d.\n", day, month, year, dayOfYear, year);

        // Convert back to day of month and month number
        int pDay, pMonth;
        fromDayOfYear(dayOfYear, year, &pMonth, &pDay);

        printf("%dth day of year %d is converted into date: %02d/%02d/%04d\n", dayOfYear, year, pDay, pMonth, year);

        printf("Would you like to enter another date? (y/n): ");
        scanf(" %c", &option);
    } while(option == 'y' || option == 'Y');

    printf("\nThank you for using the Natural Language Date Converter!");

    return 0;
}