//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <time.h>

int main()
{
    // Set up the time machine
    time_t timenow = time(NULL);
    struct tm *tm_now = localtime(&timenow);
    int year_now = tm_now->tm_year + 1900;
    int month_now = tm_now->tm_mon + 1;
    int day_now = tm_now->tm_mday;

    // Choose the year, month, and day you want to travel to
    int year_target = 2023;
    int month_target = 6;
    int day_target = 21;

    // Calculate the time difference
    int years_diff = year_target - year_now;
    int months_diff = month_target - month_now;
    int days_diff = day_target - day_now;

    // Simulate the time travel
    for (int i = 0; i < years_diff; i++)
    {
        time_t timenew = time(NULL) + 365 * 24 * 60 * 60 * i;
        struct tm *tm_new = localtime(&timenew);
        int year_new = tm_new->tm_year + 1900;
        int month_new = tm_new->tm_mon + 1;
        int day_new = tm_new->tm_mday;

        printf("Year: %d, Month: %d, Day: %d\n", year_new, month_new, day_new);
    }

    for (int i = 0; i < months_diff; i++)
    {
        time_t timenew = time(NULL) + 365 * 24 * 60 * 60 * i;
        struct tm *tm_new = localtime(&timenew);
        int year_new = tm_new->tm_year + 1900;
        int month_new = tm_new->tm_mon + 1;
        int day_new = tm_new->tm_mday;

        printf("Year: %d, Month: %d, Day: %d\n", year_new, month_new, day_new);
    }

    for (int i = 0; i < days_diff; i++)
    {
        time_t timenew = time(NULL) + 365 * 24 * 60 * 60 * i;
        struct tm *tm_new = localtime(&timenew);
        int year_new = tm_new->tm_year + 1900;
        int month_new = tm_new->tm_mon + 1;
        int day_new = tm_new->tm_mday;

        printf("Year: %d, Month: %d, Day: %d\n", year_new, month_new, day_new);
    }

    return 0;
}