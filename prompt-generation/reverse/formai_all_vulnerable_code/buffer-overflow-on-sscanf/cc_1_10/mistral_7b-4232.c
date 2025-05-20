//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Function to check if a given string is a valid date
int isValidDate(char* date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) {
        if (month == 2) {
            if (isLeapYear(year)) day <= 29;
            else day <= 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) day <= 30;
        else return 0;
    }

    return 1;
}

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Function to convert a given date to a Unix timestamp
long dateToTimestamp(char* date) {
    int day, month, year;
    struct tm tm;

    sscanf(date, "%d/%d/%d", &day, &month, &year);
    memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    return mktime(&tm);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <date in MM/DD/YYYY format>\n", argv[0]);
        return 1;
    }

    if (!isValidDate(argv[1])) {
        printf("Invalid date format.\n");
        return 1;
    }

    long timestamp = dateToTimestamp(argv[1]);
    char* dt = ctime(&timestamp);
    printf("Date: %s\nTimestamp: %ld\n", argv[1], timestamp);
    printf("Converted date: %s", dt + 4);

    return 0;
}