//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} date_t;

void print_date(date_t date) {
    printf("%d-%02d-%02d\n", date.year, date.month, date.day);
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1 || day > 31) {
        return 0;
    }

    if (month == 2) {
        if (day > 29 &&!(year % 4 == 0 && year % 100!= 0 || year % 400 == 0)) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    if (!is_valid_date(day, month, year)) {
        printf("Invalid date\n");
        return 1;
    }

    date_t date = {day, month, year};
    print_date(date);

    return 0;
}