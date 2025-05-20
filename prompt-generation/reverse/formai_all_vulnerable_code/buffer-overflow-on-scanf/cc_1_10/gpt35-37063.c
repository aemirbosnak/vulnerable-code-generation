//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t current_time;
    struct tm * time_info;
    int year, month, day, hour, minute;

    printf("Welcome to the Time Travel Simulator!\n\n");

    /* Get current time */
    time(&current_time);
    time_info = localtime(&current_time);

    /* Display current time */
    printf("Current time: %s", asctime(time_info));

    /* Get user input for year */
    printf("Enter the year you'd like to travel to: ");
    scanf("%d", &year);

    /* Get user input for month */
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    /* Get user input for day */
    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    /* Get user input for hour */
    printf("Enter the hour (0-23): ");
    scanf("%d", &hour);

    /* Get user input for minute */
    printf("Enter the minute (0-59): ");
    scanf("%d", &minute);

    /* Set time to user input */
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    time_info->tm_hour = hour;
    time_info->tm_min = minute;
    time_info->tm_sec = 0;

    /* Convert time to epoch time */
    current_time = mktime(time_info);

    /* Display travel date and time */
    printf("\nTraveling to: %s", asctime(time_info));

    /* Wait for 5 seconds */
    printf("\n5");
    sleep(1);
    printf("\n4");
    sleep(1);
    printf("\n3");
    sleep(1);
    printf("\n2");
    sleep(1);
    printf("\n1");
    sleep(1);
    printf("\n0");

    /* Set time to travel time */
    time(&current_time);
    time_info = localtime(&current_time);

    /* Display travel time */
    printf("\n\nYou have arrived at: %s", asctime(time_info));

    return 0;
}