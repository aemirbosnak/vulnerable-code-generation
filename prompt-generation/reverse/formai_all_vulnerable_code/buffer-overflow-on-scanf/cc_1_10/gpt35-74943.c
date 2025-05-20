//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int year, month, day, hour, minute, second;

    // Get current time
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    // Set simulation time to current time
    year = local->tm_year + 1900;
    month = local->tm_mon + 1;
    day = local->tm_mday;
    hour = local->tm_hour;
    minute = local->tm_min;
    second = local->tm_sec;

    // Print current time
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n\n", year, month, day, hour, minute, second);

    // Ask user for time travel destination
    printf("Where would you like to travel to?\n");
    printf("Please enter the year: ");
    scanf("%d", &year);
    printf("Please enter the month (1-12): ");
    scanf("%d", &month);
    printf("Please enter the day (1-31): ");
    scanf("%d", &day);
    printf("Please enter the hour (0-23): ");
    scanf("%d", &hour);
    printf("Please enter the minute (0-59): ");
    scanf("%d", &minute);
    printf("Please enter the second (0-59): ");
    scanf("%d", &second);

    // Calculate difference between current time and time travel destination
    int year_diff = year - (local->tm_year + 1900);
    int month_diff = month - (local->tm_mon + 1);
    int day_diff = day - local->tm_mday;
    int hour_diff = hour - local->tm_hour;
    int minute_diff = minute - local->tm_min;
    int second_diff = second - local->tm_sec;

    // Convert difference to seconds
    time_t diff = second_diff +
            60 * minute_diff +
            60 * 60 * hour_diff +
            60 * 60 * 24 * day_diff +
            60 * 60 * 24 * 365 * year_diff;

    // Set simulation time to time travel destination
    time_t sim_time = now + diff;
    struct tm *sim_local = localtime(&sim_time);

    // Print time travel destination
    printf("\n\nYou have arrived at your destination!\n\n");
    printf("Destination time: %d-%02d-%02d %02d:%02d:%02d\n\n", year, month, day, hour, minute, second);

    // Print time difference
    printf("Time difference: %d year(s), %d month(s), %d day(s), %d hour(s), %d minute(s), %d second(s)\n\n",
            year_diff, month_diff, day_diff, hour_diff, minute_diff, second_diff);

    // Ask user if they would like to continue time traveling
    char continue_travel;
    printf("Would you like to continue time traveling? (Y/N) ");
    scanf(" %c", &continue_travel);

    while (continue_travel == 'Y' || continue_travel == 'y') {
        // Ask user for time travel destination
        printf("\nWhere would you like to travel to?\n");
        printf("Please enter the year: ");
        scanf("%d", &year);
        printf("Please enter the month (1-12): ");
        scanf("%d", &month);
        printf("Please enter the day (1-31): ");
        scanf("%d", &day);
        printf("Please enter the hour (0-23): ");
        scanf("%d", &hour);
        printf("Please enter the minute (0-59): ");
        scanf("%d", &minute);
        printf("Please enter the second (0-59): ");
        scanf("%d", &second);

        // Calculate difference between current time and time travel destination
        year_diff = year - (sim_local->tm_year + 1900);
        month_diff = month - (sim_local->tm_mon + 1);
        day_diff = day - sim_local->tm_mday;
        hour_diff = hour - sim_local->tm_hour;
        minute_diff = minute - sim_local->tm_min;
        second_diff = second - sim_local->tm_sec;

        // Convert difference to seconds
        diff = second_diff +
                60 * minute_diff +
                60 * 60 * hour_diff +
                60 * 60 * 24 * day_diff +
                60 * 60 * 24 * 365 * year_diff;

        // Set simulation time to time travel destination
        sim_time += diff;
        sim_local = localtime(&sim_time);

        // Print time travel destination
        printf("\n\nYou have arrived at your destination!\n\n");
        printf("Destination time: %d-%02d-%02d %02d:%02d:%02d\n\n", year, month, day, hour, minute, second);

        // Print time difference
        printf("Time difference: %d year(s), %d month(s), %d day(s), %d hour(s), %d minute(s), %d second(s)\n\n",
                year_diff, month_diff, day_diff, hour_diff, minute_diff, second_diff);

        // Ask user if they would like to continue time traveling
        printf("Would you like to continue time traveling? (Y/N) ");
        scanf(" %c", &continue_travel);
    }

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}