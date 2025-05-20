//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

struct Date {
    int day, month, year;
};

struct MonLen {
    char *mon;
    int len;
};

const struct MonLen monlen[] = {
    { "JANUARY", 7 },
    { "FEBRUARY", 8 },
    { "MARCH", 5 },
    { "APRIL", 5 },
    { "MAY", 3 },
    { "JUNE", 4 },
    { "JULY", 4 },
    { "AUGUST", 6 },
    { "SEPTEMBER", 8 },
    { "OCTOBER", 6 },
    { "NOVEMBER", 7 },
    { "DECEMBER", 7 },
};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void strToDate(const char *strDate, struct Date *date) {
    int i, len = strlen(strDate);
    int day, month, year, idx;
    char temp[3];

    sscanf(strDate, "%d%s%d", &day, temp, &month);

    for (i = 0; i < 12; i++) {
        if (strcmp(monlen[i].mon, temp) == 0) {
            month = i + 1;
            break;
        }
    }

    sscanf(&strDate[len - 4], "%d", &year);

    if (day > 30 || (month == 2 && day > 29 && isLeapYear(year))) {
        fprintf(stderr, "Invalid date: %s\n", strDate);
        exit(EXIT_FAILURE);
    }

    date->day = day;
    date->month = month;
    date->year = year;
}

void printDate(const struct Date *date) {
    int len = monlen[date->month - 1].len;

    printf("%d %s %d\n", date->day, monlen[date->month - 1].mon, date->year);
}

int main() {
    char strDate[32];
    struct Date date;

    printf("Enter date (dd mmmm yyyy): ");
    fgets(strDate, sizeof(strDate), stdin);

    strDate[strlen(strDate)] = '\0';
    strToDate(strDate, &date);

    printDate(&date);

    return EXIT_SUCCESS;
}