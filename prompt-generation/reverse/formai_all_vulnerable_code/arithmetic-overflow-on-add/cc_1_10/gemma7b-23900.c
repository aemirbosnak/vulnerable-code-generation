//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;

    printf("The current date and time is:");
    printf("\nYear: %d", year);
    printf("\nMonth: %d", month);
    printf("\nDay: %d", day);
    printf("\nHour: %d", hour);
    printf("\nMinute: %d", minute);

    printf("\nPlease enter the year you want to travel to:");
    int target_year = atoi(stdin);

    printf("\nPlease enter the month you want to travel to (1-12):");
    int target_month = atoi(stdin);

    printf("\nPlease enter the day you want to travel to:");
    int target_day = atoi(stdin);

    printf("\nPlease enter the hour you want to travel to:");
    int target_hour = atoi(stdin);

    printf("\nPlease enter the minute you want to travel to:");
    int target_minute = atoi(stdin);

    t = mktime(tm);
    t = t - 3600 * (hour - target_hour) - 60 * (minute - target_minute);
    tm = localtime(&t);
    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    minute = tm->tm_min;

    printf("\nThe date and time you have traveled to is:");
    printf("\nYear: %d", year);
    printf("\nMonth: %d", month);
    printf("\nDay: %d", day);
    printf("\nHour: %d", hour);
    printf("\nMinute: %d", minute);

    return 0;
}