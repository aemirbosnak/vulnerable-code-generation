//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define NUM_MONTHS 12

struct {
    char *name;
    int length;
} MONTHS[NUM_MONTHS] = {
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

char *get_month_name(int month) {
    return MONTHS[month].name;
}

int get_month_length(int month) {
    return MONTHS[month].length;
}

int is_leap_year(int year) {
    if (year % 4!= 0) {
        return 0;
    }
    if (year % 100!= 0) {
        return 1;
    }
    if (year % 400!= 0) {
        return 0;
    }
    return 1;
}

int get_days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        }
        return 28;
    }
    return MONTHS[month].length;
}

int main() {
    char input[MAX_LENGTH];
    int year, month, day;
    printf("Enter date (YYYY-MM-DD): ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%d-%d-%d", &year, &month, &day);
    if (month < 1 || month > NUM_MONTHS) {
        printf("Invalid month\n");
        return 1;
    }
    if (day < 1 || day > get_month_length(month)) {
        printf("Invalid day\n");
        return 1;
    }
    printf("Date: %s %d, %d\n", get_month_name(month), day, year);
    return 0;
}