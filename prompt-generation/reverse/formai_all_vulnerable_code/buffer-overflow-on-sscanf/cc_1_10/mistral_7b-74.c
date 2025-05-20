//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 50

typedef struct {
    int month;
    int day;
    int year;
} Date;

void parseDate(char* str, Date* date) {
    int m, d, y;
    sscanf(str, "%d/%d/%d", &m, &d, &y);
    date->month = m;
    date->day = d;
    date->year = y;
}

void printDate(Date date) {
    int monthNames[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    char* monthNamesStr[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (isLeapYear(date.year)) {
        monthNames[1] = 29;
    } else {
        monthNames[1] = 28;
    }

    if (date.month > 12 || date.month < 0 || date.day > monthNames[date.month] || date.day < 0) {
        printf("Invalid date: %d/%d/%d\n", date.month, date.day, date.year);
        return;
    }

    printf("%d/%d/%d -> %d/%d/%d\n", date.month, date.day, date.year, date.day, monthNames[date.month], date.year);
}

int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    }

    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 1;
        }
        return 0;
    }

    return 1;
}

int main() {
    char input[MAX_STRING_LENGTH];
    Date date;

    printf("Enter date in MM/DD/YYYY format: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    parseDate(input, &date);
    printDate(date);

    return 0;
}