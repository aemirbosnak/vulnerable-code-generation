//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void parseDate(char dateString[], Date *date) {
    sscanf(dateString, "%d-%d-%d", &date->year, &date->month, &date->day);
}

void printDate(Date date) {
    printf("%d-%02d-%02d", date.year, date.month, date.day);
}

int isLeapYear(int year) {
    if (year % 4 != 0) return 0;
    else if (year % 100 != 0) return 1;
    else if (year % 400 != 0) return 0;
    else return 1;
}

int daysInMonth(int year, int month) {
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int dateToDays(Date date) {
    int days = 0;
    for (int i = 0; i < date.year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < date.month; i++) {
        days += daysInMonth(date.year, i);
    }
    days += date.day - 1;
    return days;
}

Date daysToDate(int days) {
    Date date;
    date.year = 1;
    while (days >= (isLeapYear(date.year) ? 366 : 365)) {
        days -= isLeapYear(date.year) ? 366 : 365;
        date.year++;
    }
    date.month = 1;
    while (days >= daysInMonth(date.year, date.month)) {
        days -= daysInMonth(date.year, date.month);
        date.month++;
    }
    date.day = days + 1;
    return date;
}

int main() {
    char dateString[100];
    printf("Enter a date in the format YYYY-MM-DD: ");
    fgets(dateString, 100, stdin);
    if (dateString[strlen(dateString) - 1] == '\n') {
        dateString[strlen(dateString) - 1] = '\0';
    } else {
        clearBuffer();
    }
    Date date;
    parseDate(dateString, &date);
    printf("The date %s is equal to %d days since 0001-01-01.\n", dateString, dateToDays(date));

    int days;
    printf("Enter a number of days: ");
    scanf("%d", &days);
    clearBuffer();
    Date newDate = daysToDate(days);
    printf("%d days since 0001-01-01 is equal to ", days);
    printDate(newDate);
    printf(".\n");

    return 0;
}