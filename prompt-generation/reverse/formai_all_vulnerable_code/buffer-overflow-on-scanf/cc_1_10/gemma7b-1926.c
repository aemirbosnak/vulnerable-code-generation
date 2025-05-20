//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <time.h>

#define YEAR_MAX 2000
#define YEAR_MIN 1000

#define MONTH_MAX 12
#define MONTH_MIN 1

#define DAY_MAX 31
#define DAY_MIN 1

#define HOUR_MAX 23
#define HOUR_MIN 0

#define MINUTE_MAX 59
#define MINUTE_MIN 0

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    int year = tm->tm_year;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;

    printf("Current Date and Time:");
    printf("\nYear: %d", year);
    printf("\nMonth: %d", month);
    printf("\nDay: %d", day);
    printf("\nHour: %d", hour);
    printf("\nMinute: %d", minute);

    printf("\nTime Travel Simulator:");
    printf("\nEnter the year you want to travel to:");
    int target_year = GetInt();

    if (target_year < YEAR_MIN || target_year > YEAR_MAX)
    {
        printf("Error: Invalid year.");
    }
    else
    {
        printf("\nEnter the month you want to travel to (1-12):");
        int target_month = GetInt();

        if (target_month < MONTH_MIN || target_month > MONTH_MAX)
        {
            printf("Error: Invalid month.");
        }
        else
        {
            printf("\nEnter the day you want to travel to (1-31):");
            int target_day = GetInt();

            if (target_day < DAY_MIN || target_day > DAY_MAX)
            {
                printf("Error: Invalid day.");
            }
            else
            {
                printf("\nEnter the hour you want to travel to (0-23):");
                int target_hour = GetInt();

                if (target_hour < HOUR_MIN || target_hour > HOUR_MAX)
                {
                    printf("Error: Invalid hour.");
                }
                else
                {
                    printf("\nEnter the minute you want to travel to (0-59):");
                    int target_minute = GetInt();

                    if (target_minute < MINUTE_MIN || target_minute > MINUTE_MAX)
                    {
                        printf("Error: Invalid minute.");
                    }
                    else
                    {
                        t = mktime(tm);
                        tm->tm_year = target_year;
                        tm->tm_mon = target_month - 1;
                        tm->tm_mday = target_day;
                        tm->tm_hour = target_hour;
                        tm->tm_min = target_minute;

                        t = mktime(tm);
                        printf("\nDate and Time after time travel:");
                        printf("\nYear: %d", tm->tm_year);
                        printf("\nMonth: %d", tm->tm_mon + 1);
                        printf("\nDay: %d", tm->tm_mday);
                        printf("\nHour: %d", tm->tm_hour);
                        printf("\nMinute: %d", tm->tm_min);
                    }
                }
            }
        }
    }

    return 0;
}

int GetInt()
{
    int n;
    scanf("%d", &n);
    return n;
}