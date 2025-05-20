//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct Date {
    int day, month, year;
} Date;

int is_leap_year(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

int get_days_in_month(int month, int year) {
    if (month == 1 && is_leap_year(year))
        return 29;
    return months[month];
}

int get_total_days(Date date) {
    int year = date.year, month = date.month, day = date.day;
    for (int i = 0; i < month - 1; i++) {
        day += get_days_in_month(i, year);
    }
    return day;
}

void print_date(Date date) {
    printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
}

Date convert_date(char *date_str) {
    char *token;
    const char delim[2] = "/";
    int date_arr[3];
    token = strtok(date_str, delim);
    int i = 0;
    while (token != NULL) {
        date_arr[i] = atoi(token);
        token = strtok(NULL, delim);
        i++;
    }
    Date date = {date_arr[0], date_arr[1], date_arr[2]};
    return date;
}

Date next_weekday(Date date) {
    int day_of_week = get_total_days(date) % 7;
    int days_until_next_weekday = (7 - day_of_week) % 7 + 1;
    date.day += days_until_next_weekday;
    if (date.day > get_days_in_month(date.month - 1, date.year)) {
        date.day -= get_days_in_month(date.month - 1, date.year);
        date.month += 1;
        if (date.month > 12) {
            date.month = 1;
            date.year += 1;
        }
    }
    return date;
}

int main() {
    char date_str[11];
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date_str);
    Date date = convert_date(date_str);
    printf("The entered date is: ");
    print_date(date);
    printf("The total number of days is: %d\n", get_total_days(date));
    Date next_wday = next_weekday(date);
    printf("The next weekday is: ");
    print_date(next_wday);
    return 0;
}