//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert a day of the year to a date */
void convertDayToDate(int dayOfYear, int year) {
    int month, day, i;

    /* Array to store number of days in each month */
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /* Check if it's a leap year */
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        daysInMonth[1] = 29;
    }

    /* Loop through each month and subtract the number of days in that month from
    the day of the year until we find the correct month */
    for (i = 0; i < 12; i++) {
        if (dayOfYear <= daysInMonth[i]) {
            month = i + 1;
            day = dayOfYear;
            break;
        }
        dayOfYear -= daysInMonth[i];
    }

    /* Print the date in the format: MM/DD/YYYY */
    printf("%02d/%02d/%04d\n", month, day, year);
}

/* Function to convert a date to a day of the year */
int convertDateToDay(char* date) {
    int month, day, year, i;
    int dayOfYear = 0;

    /* Split the date string into month, day, and year */
    sscanf(date, "%d/%d/%d", &month, &day, &year);

    /* Array to store number of days in each month */
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /* Check if it's a leap year */
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        daysInMonth[1] = 29;
    }

    /* Add up the number of days in each month that have already passed */
    for (i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    /* Add on the number of days in the current month */
    dayOfYear += day;

    /* If it's a leap year and it's past Feb 29th, add an extra day */
    if (daysInMonth[1] == 29 && month > 2) {
        dayOfYear++;
    }

    return dayOfYear;
}

int main() {
    char inputDate[11];
    int inputDay;

    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s", inputDate);

    printf("Enter a day of the year: ");
    scanf("%d", &inputDay);

    /* Convert input date to day of the year */
    int dayOfYear = convertDateToDay(inputDate);

    /* Convert input day of the year to date */
    convertDayToDate(inputDay, atoi(strrchr(inputDate, '/') + 1));

    return 0;
}