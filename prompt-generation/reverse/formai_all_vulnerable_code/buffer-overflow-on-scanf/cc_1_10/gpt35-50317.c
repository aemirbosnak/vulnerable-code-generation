//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm *current_date_time;
    int year, month, day, hour, minute, second;
    char am_pm[3];

    current_time = time(NULL);
    current_date_time = localtime(&current_time);

    printf("Welcome to Time Travel Simulator! \n");
    printf("Please enter your destination date and time (yyyy-mm-dd hh:mm:ss am/pm): ");
    scanf("%d-%d-%d %d:%d:%d %s", &year, &month, &day, &hour, &minute, &second, am_pm);

    if (hour == 12) {
        hour = 0;
    }
    if (strcmp(am_pm, "pm") == 0) {
        hour += 12;
    }

    current_date_time->tm_year = year - 1900;
    current_date_time->tm_mon = month - 1;
    current_date_time->tm_mday = day;
    current_date_time->tm_hour = hour;
    current_date_time->tm_min = minute;
    current_date_time->tm_sec = second;

    time_t destination_time = mktime(current_date_time);

    double seconds_difference = difftime(destination_time, current_time);

    if (seconds_difference < 0) {
        printf("Time travel in reverse is not possible! \n");
        return 1;
    }

    printf("You are now traveling through time! \n");

    for (int i = 1; i <= seconds_difference; i++) {
        printf("%d seconds have passed. \n", i);
    }

    printf("Arrived at destination time and date! \n");

    return 0;
}