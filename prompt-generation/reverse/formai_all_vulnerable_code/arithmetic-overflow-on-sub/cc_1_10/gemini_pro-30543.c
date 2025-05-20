//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_FORMAT_LEN 11

typedef struct {
    int year;
    int month;
    int day;
} Date;

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int month, int year) {
    if (month == 2) {
        return 28 + is_leap_year(year);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int days_between_dates(Date d1, Date d2) {
    int days = 0;

    if (d1.year == d2.year) {
        if (d1.month == d2.month) {
            days = d2.day - d1.day;
        } else {
            for (int i = d1.month + 1; i < d2.month; i++) {
                days += days_in_month(i, d1.year);
            }
            days += d2.day;
            days -= d1.day;
        }
    } else {
        for (int i = d1.year + 1; i < d2.year; i++) {
            days += 365 + is_leap_year(i);
        }
        days += days_between_dates((Date) {d1.year, 12, 31}, (Date) {d2.year, 1, 1});
    }

    return days;
}

int main() {
    char date_str[DATE_FORMAT_LEN + 1];
    Date d1, d2;

    printf("Enter the first date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);
    sscanf(date_str, "%d-%d-%d", &d1.year, &d1.month, &d1.day);

    printf("Enter the second date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);
    sscanf(date_str, "%d-%d-%d", &d2.year, &d2.month, &d2.day);

    int days = days_between_dates(d1, d2);

    printf("The number of days between the two dates is: %d\n", days);

    return 0;
}