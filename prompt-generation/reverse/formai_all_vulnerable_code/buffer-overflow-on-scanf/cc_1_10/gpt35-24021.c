//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Define the variables
    int current_year = 2021;
    int traveler_year;
    int travel_count = 0;
    
    // Print the welcome message
    printf("*** Welcome to the Time Travel Simulator ***\n\n");
    
    // Get the user input
    printf("Enter the year you want to travel to: ");
    scanf("%d", &traveler_year);
    
    // Validate the user input
    if (traveler_year < current_year)
    {
        printf("\nYou cannot travel back in time!\n");
        return 0;
    }
    else if (traveler_year == current_year)
    {
        printf("\nYou are already in the present year!\n");
        return 0;
    }
    
    // Travel through time
    while (current_year < traveler_year)
    {
        // Increase the current year by a random amount between 1 and 10
        current_year += rand() % 10 + 1;
        
        // Increment the travel count
        travel_count++;
    }
    
    // Print the results
    printf("\nYou have successfully traveled through time!\n");
    printf("You traveled %d years into the future.\n", traveler_year - 2021);
    printf("You traveled %d times.\n", travel_count);
    
    return 0;
}