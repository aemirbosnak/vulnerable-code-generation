//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 30;
    }
}

Date parseDate(const char *str) {
    Date date;
    sscanf(str, "%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

void printDate(const Date *date) {
    printf("%d-%d-%d\n", date->day, date->month, date->year);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Date date = parseDate(argv[1]);
    printDate(&date);

    return EXIT_SUCCESS;
}