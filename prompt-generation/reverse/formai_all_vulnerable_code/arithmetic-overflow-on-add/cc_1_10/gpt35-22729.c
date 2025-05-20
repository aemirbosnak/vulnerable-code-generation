//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
// C Time Travel Simulator Example Program
// By Donald Knuth

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Set the starting year to 2021
    int year = 2021;

    // Print out a welcome message
    printf("Welcome to the Time Travel Simulator!\n\n");

    // Loop until the user decides to quit
    while(1)
    {
        // Prompt the user for input
        printf("Enter a number of years to travel (or 0 to quit): ");

        // Get the user's input
        int input;
        scanf("%d", &input);

        // Check if the user wants to quit
        if(input == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }

        // Generate a random event that occurred during the time jump
        int event = rand() % 3;

        // Perform the time jump
        year += input;

        // Print out the results of the time jump
        printf("\nYou have traveled %d years into the future!\n\n", input);
        printf("Year: %d\n", year);

        // Print out the event that occurred during the time jump
        switch(event)
        {
            case 0:
                printf("Nothing of note happened during your time jump.\n");
                break;
            case 1:
                printf("You were attacked by a group of time bandits during your time jump!\n");
                break;
            case 2:
                printf("You stumbled upon a rare artifact during your time jump!\n");
                break;
        }

        // Print out a blank line to separate this jump from the next one
        printf("\n");
    }

    return 0;
}