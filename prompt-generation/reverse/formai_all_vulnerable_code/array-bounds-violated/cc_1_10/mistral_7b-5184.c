//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parseDate(const char* strDate, Date* date) {
    int i, j, daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31};

    date->year = 0;
    date->month = 0;
    date->day = 0;

    i = j = 0;
    while (isdigit(strDate[i])) {
        date->day = date->day * 10 + (strDate[i] - '0');
        i++;
    }

    i = ++j;
    while (strDate[i] != ' ') {
        if (strDate[i] == '/') {
            date->month = j;
            break;
        }
        date->month = date->month * 10 + (strDate[i] - '0');
        i++;
    }

    i++;
    while (isdigit(strDate[i])) {
        date->year = date->year * 10 + (strDate[i] - '0');
        i++;
    }

    if (date->month == 2) {
        if (isValidLeapYear(date->year))
            daysInMonth[date->month] = 29;
        else
            daysInMonth[date->month] = 28;
    }

    if (date->day > daysInMonth[date->month - 1]) {
        fprintf(stderr, "Invalid date: %s\n", strDate);
        exit(EXIT_FAILURE);
    }
}

int isValidLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main(int argc, char* argv[]) {
    Date date;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date> (DD/MM/YYYY)\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseDate(argv[1], &date);
    printf("Date: %d/%d/%d\n", date.month, date.day, date.year);

    return EXIT_SUCCESS;
}