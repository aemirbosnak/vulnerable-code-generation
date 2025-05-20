//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int year;
    char month[12];
    int day;
    time_t timestamp;
    struct tm *tm_ptr;

    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);

    printf("Enter the month you want to travel to (January-December): ");
    scanf("%s", month);

    printf("Enter the day you want to travel to: ");
    scanf("%d", &day);

    timestamp = mktime(&tm_ptr);
    tm_ptr->tm_year = year;
    tm_ptr->tm_mon = month_to_tm_mon(month) - 1;
    tm_ptr->tm_mday = day;

    printf("Your simulated time travel destination: %d %s %d, %d", tm_ptr->tm_year, tm_ptr->tm_mon, tm_ptr->tm_mday, tm_ptr->tm_hour);

    return 0;
}

int month_to_tm_mon(char *month)
{
    int mon;

    if (strcmp(month, "January") == 0)
    {
        mon = 0;
    }
    else if (strcmp(month, "February") == 0)
    {
        mon = 1;
    }
    else if (strcmp(month, "March") == 0)
    {
        mon = 2;
    }
    else if (strcmp(month, "April") == 0)
    {
        mon = 3;
    }
    else if (strcmp(month, "May") == 0)
    {
        mon = 4;
    }
    else if (strcmp(month, "June") == 0)
    {
        mon = 5;
    }
    else if (strcmp(month, "July") == 0)
    {
        mon = 6;
    }
    else if (strcmp(month, "August") == 0)
    {
        mon = 7;
    }
    else if (strcmp(month, "September") == 0)
    {
        mon = 8;
    }
    else if (strcmp(month, "October") == 0)
    {
        mon = 9;
    }
    else if (strcmp(month, "November") == 0)
    {
        mon = 10;
    }
    else if (strcmp(month, "December") == 0)
    {
        mon = 11;
    }

    return mon;
}