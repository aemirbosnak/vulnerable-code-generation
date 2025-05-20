//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing random number generator
    srand(time(NULL));

    // Setting date and time variables
    int day, month, year, hour, minute;
    int current_day, current_month, current_year, current_hour, current_minute;

    // Asking user for current date and time
    printf("Please enter the current date and time in the format: dd-mm-yyyy hh:mm\n");
    scanf("%d-%d-%d %d:%d", &current_day, &current_month, &current_year, &current_hour, &current_minute);

    // Displaying current date and time
    printf("\nYou are currently in the year %d, on the month %d, on the day %d, at %02d:%02d.\n", current_year, current_month, current_day, current_hour, current_minute);

    // Asking user for date and time to travel to
    printf("\nPlease enter a future date and time to travel to in the format: dd-mm-yyyy hh:mm\n");
    scanf("%d-%d-%d %d:%d", &day, &month, &year, &hour, &minute);

    // Displaying chosen date and time
    printf("\nYou have chosen to travel to the year %d, on the month %d, on the day %d, at %02d:%02d.\n\n", year, month, day, hour, minute);

    // Calculating time difference
    int year_diff = year - current_year;
    int month_diff = month - current_month;
    int day_diff = day - current_day;
    int hour_diff = hour - current_hour;
    int minute_diff = minute - current_minute;

    // Displaying time difference
    printf("You will need to travel %d years, %d months, %d days, %d hours and %d minutes into the future.\n\n", year_diff, month_diff, day_diff, hour_diff, minute_diff);

    // Waiting for time travel sequence to initiate
    printf("Initiating time travel sequence...\n");
    printf("3...\n");
    printf("2...\n");
    printf("1...\n");
    printf("Blast off!\n");

    // Displaying travel progress
    for (int i = 0; i <= 100; i += rand() % 5)
    {
        printf("Travel progress: %d%%\n", i);
    }

    // Arriving at destination time
    printf("\nYou have arrived at your destination time!\n");
    printf("It is now the year %d, on the month %d, on the day %d, at %02d:%02d.\n", year, month, day, hour, minute);

    return 0;
}