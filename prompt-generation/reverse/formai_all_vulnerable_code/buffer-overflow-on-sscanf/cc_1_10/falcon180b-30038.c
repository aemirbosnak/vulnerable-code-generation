//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DAYS_PER_MONTH 31
#define MONTHS_PER_YEAR 12

typedef struct {
    int day;
    char* month;
    int year;
} Date;

char* get_month_name(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

int is_valid_date(int day, int month, int year) {
    if (day < 1 || day > MAX_DAYS_PER_MONTH) {
        return 0;
    }

    if (month < 1 || month > MONTHS_PER_YEAR) {
        return 0;
    }

    if (year < 0) {
        return 0;
    }

    return 1;
}

int main() {
    char input[100];
    Date date;

    printf("Enter a date in the format 'MM/DD/YYYY': ");
    scanf("%s", input);

    int day, month, year;
    sscanf(input, "%d/%d/%d", &day, &month, &year);

    date.day = day;
    date.month = get_month_name(month);
    date.year = year;

    if (is_valid_date(day, month, year)) {
        printf("Valid date: %s %d, %d\n", date.month, day, year);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}