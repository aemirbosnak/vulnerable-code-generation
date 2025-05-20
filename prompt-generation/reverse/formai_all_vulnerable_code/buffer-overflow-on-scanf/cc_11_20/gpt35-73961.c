//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time periods as constants
#define ANCIENT_TIME 0
#define MEDIEVAL_TIME 1
#define MODERN_TIME 2
#define FUTURE_TIME 3

int main()
{
    // Declare variables
    int current_time_period;
    int target_time_period;
    int time_travel_years;
    int random_num;
    time_t t;

    // Initialize random number generator
    srand((unsigned) time(&t));

    // Initialize current time period to modern time
    current_time_period = MODERN_TIME;

    // Print current time period
    printf("You are currently in the ");

    switch(current_time_period) {
        case ANCIENT_TIME:
            printf("ancient time period.\n");
            break;
        case MEDIEVAL_TIME:
            printf("medieval time period.\n");
            break;
        case MODERN_TIME:
            printf("modern time period.\n");
            break;
        case FUTURE_TIME:
            printf("future time period.\n");
            break;
    }

    // Prompt for target time period
    printf("Enter the time period you want to travel to (0 = Ancient, 1 = Medieval, 2 = Modern, 3 = Future): ");
    scanf("%d", &target_time_period);

    // Prompt for years to time travel
    printf("Enter the number of years you want to travel through time: ");
    scanf("%d", &time_travel_years);

    // Simulate time travel
    printf("You have traveled %d years into the future.\n", time_travel_years);

    // Update current time period
    current_time_period += target_time_period - MODERN_TIME;

    // Account for going back in time
    if (time_travel_years < 0) {
        random_num = rand() % 100;
        if (random_num < 50) {
            current_time_period--;
        }
    }

    // Print new time period
    printf("You are now in the ");

    switch(current_time_period) {
        case ANCIENT_TIME:
            printf("ancient time period.\n");
            break;
        case MEDIEVAL_TIME:
            printf("medieval time period.\n");
            break;
        case MODERN_TIME:
            printf("modern time period.\n");
            break;
        case FUTURE_TIME:
            printf("future time period.\n");
            break;
    }

    // Exit program
    return 0;
}