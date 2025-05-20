//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

static const char *months[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

static const char *weekdays[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

static const int days_in_month[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

static bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static int day_of_week(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
}

static void print_calendar(int year, int month)
{
    printf("%s %d\n", months[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int first_day = day_of_week(year, month, 1);
    for (int i = 0; i < first_day; i++) {
        printf("   ");
    }

    int days_in_this_month = days_in_month[month - 1];
    if (month == FEB && is_leap_year(year)) {
        days_in_this_month++;
    }

    for (int i = 1; i <= days_in_this_month; i++) {
        printf("%2d ", i);
        if ((i + first_day) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(void)
{
    int year, month;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    print_calendar(year, month);

    return 0;
}