//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SHAPE_SHIFT 5

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date string_to_date(const char* str) {
    Date date;
    sscanf(str, "%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

long int date_to_unix(const Date date) {
    struct tm time = {0};
    time.tm_mday = date.day;
    time.tm_mon = date.month - 1;
    time.tm_year = date.year - 1900;
    time_t unix_timestamp = mktime(&time);
    return unix_timestamp;
}

Date unix_to_date(long int unix_timestamp) {
    struct tm* time = localtime(&unix_timestamp);
    Date date = {time->tm_mday, time->tm_mon + 1, time->tm_year + 1900};
    return date;
}

void print_date(const Date date) {
    printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
}

int main() {
    char input_str[30];
    int num_days;
    Date original_date, new_date;
    long int original_unix_timestamp, new_unix_timestamp;

    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", input_str);

    original_date = string_to_date(input_str);
    original_unix_timestamp = date_to_unix(original_date);

    printf("Original date: ");
    print_date(original_date);

    printf("Enter the number of days to shift the date by: ");
    scanf("%d", &num_days);

    new_unix_timestamp = original_unix_timestamp + (num_days * SHAPE_SHIFT);

    new_date = unix_to_date(new_unix_timestamp);

    printf("New date (after %d days): ", num_days);
    print_date(new_date);

    return 0;
}