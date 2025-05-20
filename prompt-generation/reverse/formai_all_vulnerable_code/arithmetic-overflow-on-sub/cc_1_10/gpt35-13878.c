//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char travel_location[20];
    int travel_year;
    time_t current_time;
    struct tm * time_info;
    int current_year;
    int time_difference;

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);
    current_year = time_info->tm_year + 1900;

    // Ask for travel location and year
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Where would you like to travel to?\n");
    scanf("%s", travel_location);
    printf("And what year would you like to visit?\n");
    scanf("%d", &travel_year);

    // Calculate time difference
    time_difference = travel_year - current_year;

    // Check if time travel is possible
    if (time_difference < 0)
    {
        printf("I'm sorry, time travel to the past is not yet possible.\n");
        printf("Please try a different year.\n");
        return 0;
    }

    // Print time travel details
    printf("Preparing to travel to %s in %d...\n\n", travel_location, travel_year);
    printf("3...\n");
    printf("2...\n");
    printf("1...\n");
    printf("Blast off!!!\n\n");

    // Wait for time travel
    printf("Travelling through time...\n");
    for (int i = 0; i < 10; i++)
    {
        printf("...\n");
        sleep(1);
    }
    printf("\n");

    // Arrive at destination
    printf("Welcome to %s in %d!\n\n", travel_location, travel_year);

    // Offer some advice
    if (time_difference > 50)
    {
        printf("Wow, things are quite different here!\n");
        printf("I suggest you be careful and not change anything too drastically.\n");
    }
    else if (time_difference > 25)
    {
        printf("Things are starting to look unfamiliar here!\n");
        printf("You may want to avoid drawing attention to yourself.\n");
    }
    else
    {
        printf("Everything looks pretty normal here!\n");
        printf("Just try to blend in and enjoy your stay.\n");
    }

    printf("\n");
    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}