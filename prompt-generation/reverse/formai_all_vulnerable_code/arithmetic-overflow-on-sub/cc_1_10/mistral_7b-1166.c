//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void convertDateToTimestamp(char date[11]) {
    int month, day, year, tmp;
    struct tm newtime;

    sscanf(date, "%d/%d/%d", &month, &day, &year);

    // Check for valid date
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date format. Please enter a valid date in the format MM/DD/YYYY.\n");
        return;
    }

    // Calculate number of days in the month
    if (month == 2) {
        if (isLeapYear(year)) {
            newtime.tm_mday = 29;
        } else {
            newtime.tm_mday = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        newtime.tm_mday = 30;
    } else {
        newtime.tm_mday = 31;
    }

    // Set other fields
    newtime.tm_year = year - 1900;
    newtime.tm_mon = month - 1;
    newtime.tm_mday = day;
    newtime.tm_hour = 0;
    newtime.tm_min = 0;
    newtime.tm_sec = 0;

    // Convert date to Unix timestamp
    time_t timestamp = mktime(&newtime);

    // Print Unix timestamp in seconds
    printf("Unix timestamp for %s/%d/%d is %ld seconds.\n", month < 10 ? "0" : "", month, day, year, (long)timestamp);
    printf("Number of seconds elapsed since January 1, 1970 is %ld.\n", (long)timestamp);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main() {
    char date[11];

    printf("Enter a date in the format MM/DD/YYYY: ");
    scanf("%s", date);

    convertDateToTimestamp(date);

    return 0;
}