//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[10];
    int length;
    int start;
    int end;
    int leap;
} Month;

Month months[] = {
    {"January", 7, 31, 31, 1},
    {"February", 29, 28, 29, 1},
    {"March", 31, 31, 30, 0},
    {"April", 30, 30, 30, 0},
    {"May", 31, 30, 31, 0},
    {"June", 30, 31, 30, 0},
    {"July", 31, 31, 31, 0},
    {"August", 31, 31, 31, 0},
    {"September", 30, 31, 30, 0},
    {"October", 31, 31, 31, 0},
    {"November", 30, 31, 30, 0},
    {"December", 31, 30, 31, 1}
};

void extract_date(const char* input, Date* date) {
    int day = 0, month = 0, year = 0;
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        switch (input[i]) {
            case '/': {
                if (month && day) {
                    month++;
                    day = 0;
                    if (month > 12) {
                        year += month / 12;
                        month %= 12;
                    }
                }
                break;
            }
            case '-': {
                if (day || month) {
                    year++;
                    month = 0;
                    day = 0;
                }
                break;
            }
            default: {
                if (month && day) {
                    if (isdigit(input[i])) {
                        day = 10 * day + (input[i] - '0');
                        if (month_valid(month, day)) {
                            date->day = day;
                            date->month = month;
                            date->year = year;
                            return;
                        }
                    }
                }
                if (!month) {
                    if (isdigit(input[i])) {
                        year = 10 * year + (input[i] - '0');
                    }
                }
                if (isdigit(input[i])) {
                    day = input[i] - '0';
                }
                break;
            }
        }
    }
    date->day = day;
    date->month = month;
    date->year = year;
}

int month_valid(int month, int day) {
    Month* m = months + month - 1;
    if (m->leap && day > 29) return 0;
    if (!m->leap && day > 30) return 0;
    return m->end >= day;
}

void print_date(const Date* date) {
    Month* m = months + date->month - 1;
    printf("%d %s %d", date->day, m->name, date->year);
}

int main() {
    char input[100];
    Date date;
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    extract_date(input, &date);
    print_date(&date);
    return 0;
}