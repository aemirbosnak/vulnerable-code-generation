//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MONTHS 12
#define MAX_DAYS 31

typedef struct {
    char* month;
    int days;
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

int is_valid_date(int year, int month, int day) {
    if (month < 1 || month > MAX_MONTHS) {
        return 0;
    }
    if (day < 1 || day > months[month - 1].days) {
        return 0;
    }
    if (month == 2) {
        if (day > 29 &&!is_leap_year(year)) {
            return 0;
        }
    }
    return 1;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char input[100];
    int year, month, day;
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input);
    sscanf(input, "%d-%d-%d", &year, &month, &day);
    if (is_valid_date(year, month, day)) {
        printf("Valid date\n");
    } else {
        printf("Invalid date\n");
    }
    return 0;
}