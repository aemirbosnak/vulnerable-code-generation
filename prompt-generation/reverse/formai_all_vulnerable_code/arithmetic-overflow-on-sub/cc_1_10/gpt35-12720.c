//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    int year, month, day, hour, min, sec;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter day: ");
    scanf("%d", &day);

    printf("Enter hour: ");
    scanf("%d", &hour);

    printf("Enter minute: ");
    scanf("%d", &min);

    printf("Enter second: ");
    scanf("%d", &sec);

    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    travel_time.tm_hour = hour;
    travel_time.tm_min = min;
    travel_time.tm_sec = sec;

    time_t travel_seconds = mktime(&travel_time);
    double time_diff_seconds = difftime(travel_seconds, now);

    if (time_diff_seconds >= 0)
    {
        printf("Time travel successful! You travelled %f seconds into the future!\n", time_diff_seconds);
    }
    else
    {
        printf("Time travel successful! You travelled %f seconds into the past!\n", abs(time_diff_seconds));
    }

    return 0;
}