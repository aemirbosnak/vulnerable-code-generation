//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int current_year = 2021;
    int target_year;
    int years_to_travel;
    int year_difference;
    
    // obtain user input
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the year you wish to travel to: ");
    scanf("%d", &target_year);

    // validate target year
    if (target_year < current_year) {
        printf("\nWe cannot go back in time!\n");
        return 1;
    } else if (target_year == current_year) {
        printf("\nYou are already in the present year!\n");
        return 1;
    }

    // calculate years to travel
    years_to_travel = target_year - current_year;
    year_difference = abs(years_to_travel);
    
    printf("\nTravelling %d years into the future...\n\n", year_difference);
    
    // simulate time travel
    int i;
    for (i = 0; i <= year_difference; i++) {
        printf("Year: %d\n", current_year + i);
        printf("Event: ");
        srand(time(0) + i);
        int event = (rand() % 4) + 1;

        // randomly generate event
        switch(event) {
            case 1:
                printf("World peace achieved!\n\n");
                break;
            case 2:
                printf("Alien invasion defeated!\n\n");
                break;
            case 3: 
                printf("Robot uprising suppressed!\n\n");
                break;
            case 4:
                printf("Asteroid impact avoided!\n\n");
                break;
            default:
                printf("No significant events.\n\n");
        }
    }

    printf("Time travel complete!\n");
    return 0;
}