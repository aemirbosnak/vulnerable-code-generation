//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t present_time;
    struct tm *local_time;

    // Get the current time
    present_time = time(NULL);

    // Convert the current time to local time
    local_time = localtime(&present_time);

    // Print the current date and time
    printf("Current date and time: %s", asctime(local_time));

    // Ask the user for the number of years they want to time travel
    int years;
    printf("Enter the number of years you want to time travel: ");
    scanf("%d", &years);

    // Calculate the number of seconds to time travel
    time_t time_travel_secs = years * 31536000;

    // Set the new date and time by adding the time travel seconds to the current time
    present_time += time_travel_secs;
    local_time = localtime(&present_time);

    // Print the new date and time
    printf("New date and time after time travel: %s", asctime(local_time));

    // Ask the user if they want to time travel again
    char choice;
    printf("Do you want to time travel again? (Y/N): ");
    scanf(" %c", &choice);

    // If the user wants to time travel again, loop through
    while (choice == 'Y' || choice == 'y')
    {
        printf("Enter the number of years you want to time travel: ");
        scanf("%d", &years);

        // Calculate the number of seconds to time travel
        time_travel_secs = years * 31536000;

        // Set the new date and time by adding the time travel seconds to the current time
        present_time += time_travel_secs;
        local_time = localtime(&present_time);

        // Print the new date and time
        printf("New date and time after time travel: %s", asctime(local_time));

        printf("Do you want to time travel again? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using our time travel simulator!");

    return 0;
}