//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 100

// Function to check if a given string is a valid date in the format "dd-mm-yyyy"
int isValidDate(char date[MAX_LEN]) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return 0;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

// Function to convert a given date string to a Unix timestamp
long long convertDateToUnixTimestamp(char date[MAX_LEN]) {
    struct tm tm;
    char format[] = " %d-%d-%d ";
    long long timestamp;

    sscanf(date, "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon--;

    memset(&tm.tm_hour, 0, sizeof(tm.tm_hour));
    memset(&tm.tm_min, 0, sizeof(tm.tm_min));
    memset(&tm.tm_sec, 0, sizeof(tm.tm_sec));

    timestamp = mktime(&tm);
    return timestamp * 1000;
}

int main() {
    char inputDate[MAX_LEN];
    long long unixTimestamp;

    printf("Enter a date in the format 'dd-mm-yyyy': ");
    fgets(inputDate, MAX_LEN, stdin);
    inputDate[strlen(inputDate) - 1] = '\0'; // Remove newline character

    if (isValidDate(inputDate)) {
        unixTimestamp = convertDateToUnixTimestamp(inputDate);
        printf("Unix timestamp for '%s': %lld\n", inputDate, unixTimestamp);
    } else {
        printf("Invalid date format. Please try again.\n");
    }

    return 0;
}