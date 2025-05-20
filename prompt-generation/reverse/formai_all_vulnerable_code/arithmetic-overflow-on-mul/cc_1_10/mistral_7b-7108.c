//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to validate the given date string
int isValidDate(char *date) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (month < 1 || month > 12)
        return 0;

    if (day < 1 || day > 31) {
        if (month == 2) {
            if (isLeapYear(year))
                return day < 29;
            else
                return day < 28;
        }
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return day > daysInMonth[month - 1];
    }

    return 1;
}

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

// Function to convert the given date string to Unix timestamp
long long int dateToTimestamp(char *date) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (!isValidDate(date)) {
        perror("Invalid date format"), exit(EXIT_FAILURE);
    }

    struct tm newTime;
    memset(&newTime, 0, sizeof(struct tm));
    newTime.tm_year = year - 1900;
    newTime.tm_mon = month - 1;
    newTime.tm_mday = day;

    mktime(&newTime);

    return mktime(&newTime) * 1000LL;
}

int main() {
    char date[20];
    printf("Enter date in dd-mm-yyyy format: ");
    scanf("%s", date);

    long long int timestamp = dateToTimestamp(date);
    printf("Unix timestamp for the given date: %lld\n", timestamp);

    return 0;
}