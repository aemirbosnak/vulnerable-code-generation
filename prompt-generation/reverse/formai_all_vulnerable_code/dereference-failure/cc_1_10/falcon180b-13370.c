//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_LENGTH 20
#define MAX_YEAR_LENGTH 20

enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

struct date {
    char month[MAX_MONTH_LENGTH];
    int day;
    int year;
};

char* get_month_name(int month) {
    switch (month) {
        case JANUARY:
            return "January";
        case FEBRUARY:
            return "February";
        case MARCH:
            return "March";
        case APRIL:
            return "April";
        case MAY:
            return "May";
        case JUNE:
            return "June";
        case JULY:
            return "July";
        case AUGUST:
            return "August";
        case SEPTEMBER:
            return "September";
        case OCTOBER:
            return "October";
        case NOVEMBER:
            return "November";
        case DECEMBER:
            return "December";
        default:
            return "Invalid month";
    }
}

struct date parse_date(char* str) {
    struct date date;
    char* token;
    int i;

    token = strtok(str, " ");
    strcpy(date.month, token);

    token = strtok(NULL, " ");
    date.day = atoi(token);

    token = strtok(NULL, " ");
    date.year = atoi(token);

    return date;
}

void print_date(struct date date) {
    printf("%s %d, %d\n", get_month_name(date.month[0] - '0'), date.day, date.year);
}

int main() {
    char* input;
    struct date date;

    printf("Enter a date in the format month day, year: ");
    scanf("%s", input);

    date = parse_date(input);
    print_date(date);

    return 0;
}