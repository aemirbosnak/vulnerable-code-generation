//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for the random number generator
    srand(time(NULL));

    // Get the current year
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    int current_year = current_time->tm_year + 1900;

    // Set the minimum and maximum years for time travel
    int min_year = current_year - 100;
    int max_year = current_year + 100;

    // Ask the user for the year they want to travel to
    int year_to_travel = -1;
    while (year_to_travel < min_year || year_to_travel > max_year)
    {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Enter a year between %d and %d to travel to: ", min_year, max_year);
        scanf("%d", &year_to_travel);
        if (year_to_travel < min_year || year_to_travel > max_year)
        {
            printf("Invalid year entered. Please try again.\n");
        }
    }

    // Determine the amount of time travel
    int years_traveled = year_to_travel - current_year;

    // Generate a random event that occurs during time travel
    int event_chance = rand() % 100 + 1;
    if (event_chance <= 25)
    {
        // Event 1: Traveler meets a famous historical figure
        printf("Congratulations, you have met a famous historical figure!\n");
        printf("Who did you meet? ");
        char famous_person[50];
        scanf("%s", famous_person);
        printf("You traveled %d years and met %s in %d.\n", years_traveled, famous_person, year_to_travel);
    }
    else if (event_chance <= 50)
    {
        // Event 2: Traveler witnesses a significant historical event
        printf("Congratulations, you have witnessed a significant historical event!\n");
        printf("What event did you witness? ");
        char event_name[50];
        scanf("%s", event_name);
        printf("You traveled %d years and witnessed %s in %d.\n", years_traveled, event_name, year_to_travel);
    }
    else if (event_chance <= 75)
    {
        // Event 3: Traveler gets stuck in time and needs to find a way back
        printf("Oh no, you have been stuck in time and need to find a way back to the present!\n");
        // Code to find a way back to the present would go here
    }
    else
    {
        // Event 4: Traveler inadvertently changes history
        printf("Warning, you have inadvertently changed history! Please be careful with your actions.\n");
        // Code to handle changes to history would go here
    }

    return 0;
}