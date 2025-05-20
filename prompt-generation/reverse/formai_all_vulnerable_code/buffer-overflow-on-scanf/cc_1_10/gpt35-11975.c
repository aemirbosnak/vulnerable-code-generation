//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for the random number generator
    srand(time(0));

    // Define the initial year as the current year
    int year = 2021;

    // Define a variable to hold the user's choice
    int choice;

    // Define a while loop to allow the user to make choices
    while (1)
    {
        // Print out the current year and prompt the user for a choice
        printf("Welcome to Time Travel Simulator\n\n");
        printf("It is currently %d. What would you like to do?\n", year);
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        // Handle the user's choice
        if (choice == 1)
        {
            // Generate a random number between 1 and 10 to determine the number of years to travel
            int years = rand() % 10 + 1;

            // Subtract the number of years from the current year
            year -= years;

            // Print out a message to let the user know where they have traveled to
            printf("You have traveled %d years into the past. It is now %d.\n\n", years, year);
        }
        else if (choice == 2)
        {
            // Generate a random number between 1 and 10 to determine the number of years to travel
            int years = rand() % 10 + 1;

            // Add the number of years to the current year
            year += years;

            // Print out a message to let the user know where they have traveled to
            printf("You have traveled %d years into the future. It is now %d.\n\n", years, year);
        }
        else if (choice == 3)
        {
            // Exit the program
            printf("Thanks for using Time Travel Simulator. Goodbye!\n");
            exit(0);
        }
        else
        {
            // Handle invalid choices
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}