//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

int days_in_months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_days_in_month(int month, int year) {
    if (is_leap_year(year) && month == FEBRUARY) {
        return 29;
    } else {
        return days_in_months[month];
    }
}

void convert_to_date(int date) {
    int day = date % 100;
    int month = (date / 100) % 100;
    int year = date / 10000;

    printf("The date is: %d/%d/%d\n", month, day, year);
}

void convert_to_integer(char *date_string) {
    char delimiter[] = "/";
    char *ptr = strtok(date_string, delimiter);

    int month, day, year;

    if (ptr != NULL) {
        month = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    } else {
        printf("Error! Invalid date format.\n");
        return;
    }

    if (ptr != NULL) {
        day = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    } else {
        printf("Error! Invalid date format.\n");
        return;
    }

    if (ptr != NULL) {
        year = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    } else {
        printf("Error! Invalid date format.\n");
        return;
    }

    if (month < JANUARY || month > DECEMBER) {
        printf("Error! Invalid month.\n");
        return;
    }

    if (year < 1 || year > 9999) {
        printf("Error! Invalid year.\n");
        return;
    }

    if (day < 1 || day > get_days_in_month(month, year)) {
        printf("Error! Invalid day.\n");
        return;
    }

    int date = year * 10000 + month * 100 + day;

    printf("The integer date is: %d\n", date);
}

int main() {
    char date_string[11];
    int date;

    printf("Welcome to the visionary C Natural Language Date Converter.\n");
    printf("Enter a date in the format MM/DD/YYYY: ");
    fgets(date_string, sizeof(date_string), stdin);

    convert_to_integer(date_string);

    printf("Enter an integer date (YYYYMMDD): ");
    scanf("%d", &date);

    convert_to_date(date);

    return 0;
}