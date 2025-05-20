//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_DATES 100

struct Date {
    int year;
    int month;
    int day;
};

int main() {
    int numDates;
    struct Date dates[MAX_DATES];
    char input[100];
    int i;

    // Get number of dates from user
    printf("Enter the number of dates: ");
    scanf("%d", &numDates);

    // Get dates from user
    for (i = 0; i < numDates; i++) {
        printf("Enter date %d in the format YYYY-MM-DD: ", i+1);
        scanf("%s", input);
        sscanf(input, "%d-%d-%d", &dates[i].year, &dates[i].month, &dates[i].day);
    }

    // Sort dates in ascending order
    for (i = 0; i < numDates-1; i++) {
        for (int j = i+1; j < numDates; j++) {
            if (dates[i].year > dates[j].year ||
                (dates[i].year == dates[j].year && dates[i].month > dates[j].month) ||
                (dates[i].year == dates[j].year && dates[i].month == dates[j].month && dates[i].day > dates[j].day)) {
                struct Date temp = dates[i];
                dates[i] = dates[j];
                dates[j] = temp;
            }
        }
    }

    // Calculate time difference between dates
    for (i = 0; i < numDates-1; i++) {
        int diffYear = abs(dates[i+1].year - dates[i].year);
        int diffMonth = abs(dates[i+1].month - dates[i].month);
        int diffDay = abs(dates[i+1].day - dates[i].day);
        int totalDays = 0;

        if (diffYear > 0) {
            totalDays += 365 * diffYear;
        }

        if (diffMonth > 0) {
            totalDays += 30 * diffMonth;
        }

        totalDays += diffDay;

        printf("The time difference between %d-%d-%d and %d-%d-%d is %d days.\n",
               dates[i].year, dates[i].month, dates[i].day,
               dates[i+1].year, dates[i+1].month, dates[i+1].day,
               totalDays);
    }

    return 0;
}