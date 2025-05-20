//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parseDate(const char* dateString, Date* date) {
    char delimiter = '-';
    char* token = strtok(dateString, &delimiter);
    date->day = atoi(token);

    token = strtok(NULL, &delimiter);
    date->month = atoi(token);

    token = strtok(NULL, &delimiter);
    date->year = atoi(token);
}

int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void formatDate(Date date, char* formattedDate) {
    sprintf(formattedDate, "%02d-%02d-%04d", date.day, date.month, date.year);
}

int main() {
    char inputDate[MAX_DATE_LENGTH];
    Date date;

    printf("Enter a date (dd-mm-yyyy): ");
    scanf("%s", inputDate);

    parseDate(inputDate, &date);

    if (isLeapYear(date.year)) {
        printf("Leap year!\n");
    }

    int daysInMonth = getDaysInMonth(date.month, date.year);

    if (date.day > daysInMonth) {
        printf("Invalid date.\n");
    } else {
        char formattedDate[MAX_DATE_LENGTH];
        formatDate(date, formattedDate);
        printf("Formatted date: %s\n", formattedDate);
    }

    return 0;
}