//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char date_str[256];
    char month_str[256];
    char year_str[256];
    char hour_str[256];
    char minute_str[256];

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", date_str);

    printf("Enter the month (January/February/March/...): ");
    scanf("%s", month_str);

    printf("Enter the year (yyyy): ");
    scanf("%s", year_str);

    printf("Enter the hour (0-23): ");
    scanf("%s", hour_str);

    printf("Enter the minute (0-59): ");
    scanf("%s", minute_str);

    time_t t = mktime(NULL);
    struct tm *tm = localtime(&t);

    tm->tm_year = atoi(year_str) - 1900;
    tm->tm_mon = month_str_to_num(month_str);
    tm->tm_mday = atoi(date_str);
    tm->tm_hour = atoi(hour_str);
    tm->tm_min = atoi(minute_str);

    t = mktime(tm);

    char converted_date[256];
    strftime(converted_date, sizeof(converted_date), "%A, %d %B %Y at %H:%M", tm);

    printf("Converted date: %s\n", converted_date);

    return 0;
}

int month_str_to_num(char *month_str)
{
    if (strcmp(month_str, "January") == 0) {
        return 0;
    } else if (strcmp(month_str, "February") == 0) {
        return 1;
    } else if (strcmp(month_str, "March") == 0) {
        return 2;
    } else if (strcmp(month_str, "April") == 0) {
        return 3;
    } else if (strcmp(month_str, "May") == 0) {
        return 4;
    } else if (strcmp(month_str, "June") == 0) {
        return 5;
    } else if (strcmp(month_str, "July") == 0) {
        return 6;
    } else if (strcmp(month_str, "August") == 0) {
        return 7;
    } else if (strcmp(month_str, "September") == 0) {
        return 8;
    } else if (strcmp(month_str, "October") == 0) {
        return 9;
    } else if (strcmp(month_str, "November") == 0) {
        return 10;
    } else if (strcmp(month_str, "December") == 0) {
        return 11;
    } else {
        return -1;
    }
}