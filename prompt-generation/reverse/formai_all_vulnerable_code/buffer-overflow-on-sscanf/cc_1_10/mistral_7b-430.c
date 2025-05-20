//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

// Function to calculate the number of days in a given month
int getDaysInMonth(int month, int year) {
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return -1;
    }
}

// Function to convert a given date string to Unix timestamp
long long convertDateToStringTimestamp(char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    // Check if the given date is valid
    if (day < 1 || month < 1 || month > 12 || year < 1)
        return -1;

    // Calculate the number of days from January 1, 1970 to the given date
    long long days = 0;
    for (int i = 1970; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++) {
        days += getDaysInMonth(i, year);
    }
    days += day;

    // Convert the number of days to Unix timestamp
    struct tm tm = {0};
    tm.tm_sec = 0;
    tm.tm_min = 0;
    tm.tm_hour = 0;
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    return mktime(&tm) * 1000LL;
}

int main() {
    char date[20];
    long long timestamp;

    printf("Enter a date in the format of 'dd/mm/yyyy': ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0'; // Remove newline character

    timestamp = convertDateToStringTimestamp(date);
    if (timestamp == -1) {
        printf("Invalid date.\n");
    } else {
        printf("The Unix timestamp for the given date is: %lld\n", timestamp);
    }

    return 0;
}