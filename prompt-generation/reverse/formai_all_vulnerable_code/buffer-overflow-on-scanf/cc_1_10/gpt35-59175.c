//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Get current time
    time_t now = time(NULL);

    //Convert to local time
    struct tm *current_time = localtime(&now);

    //Display current time
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current time is: %s", asctime(current_time));

    int choice, years;

    //Ask user for time travel choice
    printf("\nChoose your time travel destination:\n");
    printf("1. Past\n");
    printf("2. Future\n");
    scanf("%d", &choice);

    //Ask user for number of years to travel
    printf("\nHow many years do you want to travel? ");
    scanf("%d", &years);

    //Calculate new date
    struct tm *new_time = localtime(&now);

    if (choice == 1) //Travel to the past
    {
        new_time->tm_year -= years;
    }
    else if (choice == 2) //Travel to the future
    {
        new_time->tm_year += years;  
    }
    else //Invalid choice
    {
        printf("Invalid choice. Exiting program.\n");
        exit(EXIT_FAILURE);
    }

    //Display new date and time
    printf("\nYou have arrived at your destination!\n");
    printf("The date and time is: %s", asctime(new_time));

    return 0;
}