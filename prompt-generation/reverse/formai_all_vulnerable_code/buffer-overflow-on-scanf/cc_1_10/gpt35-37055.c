//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel to the past
void time_travel(int year, int month, int day)
{
    time_t current_time;
    struct tm * time_info;
    char time_str[25];

    // Set the current time
    current_time = time(NULL);

    // Get the time info and format it
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    printf("Current date and time: %s\n", time_str);

    // Set the time to travel to
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;

    // Create the new time
    current_time = mktime(time_info);

    // Get the new time info and format it
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    printf("Traveling back in time to: %s\n", time_str);
}

int main()
{
    // Set the time to travel to
    int year = 1985;
    int month = 10;
    int day = 26;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You will now travel back to a specific date and time.\n");
    printf("Please make sure to bring any necessary equipment and supplies with you.\n");
    printf("You will not be able to return to the present until the designated time.\n\n");
    printf("Are you ready to begin? (y/n) ");

    char response;
    scanf("%c", &response);

    if (response == 'y' || response == 'Y')
    {
        printf("\nPreparing to travel...\n\n");

        // Travel to the specified time
        time_travel(year, month, day);

        printf("\nYou have arrived at your destination.\n");
        printf("Please take the necessary precautions to avoid altering the timeline.\n");
        printf("There will be no second chances.\n");
        printf("Good luck, time traveler.\n");
    }
    else
    {
        printf("\nPerhaps another time, then.\n");
    }

    return 0;
}