//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if the given year is a leap year
int is_leap_year(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        return 1;
    } else {
        return 0;
    }
}

// Convert a date in the format "dd/mm/yyyy" to the number of days since the beginning of the Gregorian calendar
long long date_to_days(char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    long long days = 0;

    // Add the days in the previous years
    for (int i = 1; i < year; i++) {
        if (is_leap_year(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    // Add the days in the current year up to the given month
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 2:
                if (is_leap_year(year)) {
                    days += 29;
                } else {
                    days += 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
        }
    }

    // Add the days in the given month up to the given day
    days += day;

    return days;
}

// Convert a number of days since the beginning of the Gregorian calendar to a date in the format "dd/mm/yyyy"
char *days_to_date(long long days) {
    int year = 1;

    // Find the year
    while (days >= 365) {
        if (is_leap_year(year)) {
            days -= 366;
        } else {
            days -= 365;
        }
        year++;
    }

    // Find the month
    int month = 1;
    while (days >= 31) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days -= 31;
                break;
            case 2:
                if (is_leap_year(year)) {
                    days -= 29;
                } else {
                    days -= 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days -= 30;
                break;
        }
        month++;
    }

    // Find the day
    int day = days + 1;

    // Create the date string
    char *date = malloc(11);
    sprintf(date, "%02d/%02d/%04d", day, month, year);

    return date;
}

int main() {
    // Get the date from the user
    char date[11];
    printf("Enter a date in the format \"dd/mm/yyyy\": ");
    scanf("%s", date);

    // Convert the date to the number of days since the beginning of the Gregorian calendar
    long long days = date_to_days(date);

    // Print the number of days
    printf("The number of days since the beginning of the Gregorian calendar is: %lld\n", days);

    // Convert the number of days back to a date
    char *new_date = days_to_date(days);

    // Print the new date
    printf("The new date is: %s\n", new_date);

    // Free the memory allocated for the new date
    free(new_date);

    return 0;
}