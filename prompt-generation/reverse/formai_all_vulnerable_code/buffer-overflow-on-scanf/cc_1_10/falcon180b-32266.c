//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int isValidDate(char* dateStr) {
    struct tm tm;
    strptime(dateStr, "%Y-%m-%d", &tm);
    return (tm.tm_year >= 1000 && tm.tm_year <= 9999 && tm.tm_mon >= 1 && tm.tm_mon <= 12 && tm.tm_mday >= 1 && tm.tm_mday <= 31);
}

// Function to convert a date string to a numerical representation
int dateToNum(char* dateStr) {
    struct tm tm;
    strptime(dateStr, "%Y-%m-%d", &tm);
    int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;
    return (year * 365) + (year / 4) - (year / 100) + (year / 400) + (month * 30) + day;
}

// Function to convert a numerical representation to a date string
void numToDate(int num, char* dateStr) {
    int year = num / 365;
    int leapYears = 0;
    int days = num % 365;

    while (days > 365) {
        if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
            days -= 366;
            leapYears++;
        } else {
            days -= 365;
        }
        year++;
    }

    sprintf(dateStr, "%04d-%02d-%02d", year, days / 30 + 1, days % 30 + 1);
}

int main() {
    char inputDate[11];
    char outputDate[11];

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", inputDate);

    if (isValidDate(inputDate)) {
        int numDate = dateToNum(inputDate);
        numToDate(numDate, outputDate);
        printf("Numerical representation of the date: %s\n", outputDate);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}