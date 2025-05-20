//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int get_days_in_month(int month, int year) {
    int days = days_in_month[month];
    if (month == 1 && is_leap_year(year)) {
        days++;
    }
    return days;
}

struct date convert_date(char* date_string) {
    struct date result;
    char* token;
    token = strtok(date_string, "/");
    result.day = atoi(token);
    token = strtok(NULL, "/");
    result.month = atoi(token);
    token = strtok(NULL, "/");
    result.year = atoi(token);
    return result;
}

int get_day_of_year(struct date date) {
    int i;
    int days = 0;
    for (i = 0; i < date.month - 1; i++) {
        days += get_days_in_month(i, date.year);
    }
    days += date.day;
    return days;
}

void print_date(struct date date) {
    printf("%s %d, %d", month_names[date.month - 1], date.day, date.year);
}

int main() {
    printf("Enter a date in the format MM/DD/YYYY: ");
    char date_string[10];
    fgets(date_string, 10, stdin);
    date_string[strcspn(date_string, "\n")] = 0;
    struct date date = convert_date(date_string);
    int day_of_year = get_day_of_year(date);
    printf("Day of year: %d\n", day_of_year);
    printf("Date: ");
    print_date(date);
    return 0;
}