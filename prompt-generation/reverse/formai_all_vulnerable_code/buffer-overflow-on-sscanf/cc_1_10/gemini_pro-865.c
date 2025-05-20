//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Date {
    int year;
    int month;
    int day;
};

bool is_leap_year(int year) {
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return 30;
    }
}

struct Date convert_date(char *date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    return (struct Date) {year, month, day};
}

char *format_date(struct Date date) {
    char *formatted_date = malloc(11);
    sprintf(formatted_date, "%04d-%02d-%02d", date.year, date.month, date.day);
    return formatted_date;
}

int main() {
    char *date = "2023-03-08";
    struct Date converted_date = convert_date(date);
    char *formatted_date = format_date(converted_date);
    printf("The formatted date is: %s\n", formatted_date);
    free(formatted_date);
    return 0;
}