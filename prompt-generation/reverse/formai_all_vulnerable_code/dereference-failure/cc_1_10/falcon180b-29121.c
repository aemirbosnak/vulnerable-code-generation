//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int length;
} Month;

Month months[] = {
    {"January", 31},
    {"February", 28},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}
};

typedef struct {
    int day;
    int month;
    int year;
} Date;

char *get_month_name(int month) {
    for (int i = 0; i < 12; i++) {
        if (months[i].length == month) {
            return months[i].name;
        }
    }
    return NULL;
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void print_date(Date date) {
    char *month_name = get_month_name(date.month);
    printf("%s %d, %d\n", month_name, date.day, date.year);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]) - 1;
    int year = atoi(argv[3]);

    if (month < 0 || month >= 12) {
        printf("Invalid month\n");
        return 1;
    }

    if (day < 1 || day > months[month].length) {
        printf("Invalid day\n");
        return 1;
    }

    Date date = {day, month, year};
    print_date(date);

    return 0;
}