//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to check if a given string is a valid date in the format "dd-mm-yyyy"
int isValidDate(char* date) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return 0;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}

// Function to convert a given date string to a Unix timestamp
long long convertDateToUnixTimestamp(char* date) {
    int day, month, year;
    long long daysInYear[101] = {0};
    int leapYear = 0;

    sscanf(date, "%d-%d-%d", &day, &month, &year);

    for (int i = 1; i < year; i++) {
        if (leapYear && i % 4 != 0)
            daysInYear[i] += 366;
        else if (i % 4 == 0 && i % 100 != 0)
            daysInYear[i] += 365;
        else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0)
            daysInYear[i] += 366;
        else
            daysInYear[i] += 365;
    }

    if (leapYear && year % 4 != 0)
        daysInYear[year] += 364;
    else if (year % 4 == 0 && year % 100 != 0)
        daysInYear[year] += 365;
    else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
        daysInYear[year] += 366;
    else
        daysInYear[year] += 365;

    long long timestamp = daysInYear[year] + day - 1;
    return timestamp * 86400LL;
}

int main() {
    char date[MAX_LEN];
    printf("Enter a date in the format 'dd-mm-yyyy': ");
    scanf("%s", date);

    if (isValidDate(date)) {
        long long timestamp = convertDateToUnixTimestamp(date);
        printf("Unix timestamp for the given date: %lld\n", timestamp);
    } else {
        printf("Invalid date format.\n");
    }

    return 0;
}