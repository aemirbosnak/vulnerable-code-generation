//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime;
    time(&currentTime);

    struct tm *timePtr = localtime(&currentTime);

    int currentYear = timePtr->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n");

    char travelDirection;
    int travelYears, newYear;

    printf("Would you like to travel forward or backward in time? (F/B)\n");
    scanf(" %c", &travelDirection);

    printf("How many years would you like to travel?\n");
    scanf("%d", &travelYears);

    // Travel forward in time
    if (travelDirection == 'F') {
        newYear = currentYear + travelYears;
        printf("You have traveled %d years into the future!\n", travelYears);
    }
    // Travel backward in time
    else if (travelDirection == 'B') {
        newYear = currentYear - travelYears;
        printf("You have traveled %d years into the past!\n", travelYears);
    }

    printf("The year is now %d.\n", newYear);

    // Check if the new year is a leap year
    int isLeapYear = 0;
    if (newYear % 4 == 0) {
        if (newYear % 100 == 0) {
            if (newYear % 400 == 0) {
                isLeapYear = 1;
            }
        }
        else {
            isLeapYear = 1;
        }
    }

    // Calculate the number of days in February based on whether it is a leap year
    int daysInFebruary = isLeapYear ? 29 : 28;

    // Calculate the number of days in each month
    int daysInMonths[] = {31, daysInFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the day of the week for January 1st of the new year
    struct tm newYearDate = {0};
    newYearDate.tm_year = newYear - 1900;
    newYearDate.tm_mday = 1;
    newYearDate.tm_mon = 0;

    time_t newYearTime = mktime(&newYearDate);
    struct tm *newYearDatePtr = localtime(&newYearTime);
    int newYearDayOfWeek = newYearDatePtr->tm_wday;

    // Print out the calendar for the new year
    printf("\n");
    printf("      %d\n", newYear);

    int month;
    for (month = 0; month < 12; month++) {
        printf("\n");

        // Print out the name of the month
        char monthName[20];
        switch (month) {
            case 0:
                sprintf(monthName, "January");
                break;
            case 1:
                sprintf(monthName, "February");
                break;
            case 2:
                sprintf(monthName, "March");
                break;
            case 3:
                sprintf(monthName, "April");
                break;
            case 4:
                sprintf(monthName, "May");
                break;
            case 5:
                sprintf(monthName, "June");
                break;
            case 6:
                sprintf(monthName, "July");
                break;
            case 7:
                sprintf(monthName, "August");
                break;
            case 8:
                sprintf(monthName, "September");
                break;
            case 9:
                sprintf(monthName, "October");
                break;
            case 10:
                sprintf(monthName, "November");
                break;
            case 11:
                sprintf(monthName, "December");
                break;
        }
        printf("%s\n", monthName);

        // Print out the days of the week
        printf("Su Mo Tu We Th Fr Sa\n");

        // Print out the days of the month
        int day;
        for (day = 1; day <= daysInMonths[month]; day++) {
            if (day == 1) {
                int i;
                for (i = 0; i < newYearDayOfWeek; i++) {
                    printf("   ");
                }
            }

            printf("%2d ", day);

            if ((day + newYearDayOfWeek) % 7 == 0) {
                printf("\n");
            }
        }

        newYearDayOfWeek = (newYearDayOfWeek + daysInMonths[month]) % 7;
    }

    printf("\n");

    return 0;
}