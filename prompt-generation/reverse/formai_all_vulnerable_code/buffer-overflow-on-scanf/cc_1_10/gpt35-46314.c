//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaring global variables
int days = 1;
int totalCaloriesBurned = 0;
int totalStepsTaken = 0;
float totalDistanceCovered = 0.0;

int main()
{
    // Display welcome message and instructions
    printf("Welcome to your Fitness Tracker!\n");
    printf("Instructions:\n");
    printf("Enter the number of steps taken and the distance covered in kilometers for each day.\n");
    printf("The program will calculate the total calories burned based on your input.\n");
    printf("Press 0 to exit the program.\n\n");

    // Loop through each day until user enters 0 to exit
    while (1)
    {
        // Declare local variables for the current day
        int steps, caloriesBurned;
        float distance;

        // Display the day number and prompt the user for input
        printf("Day %d - \n", days);
        printf("Number of steps taken: ");
        scanf("%d", &steps);

        if (steps == 0)
        {
            // If user enters 0, break out of the loop and end program
            printf("\nThank you for using the Fitness Tracker!\n\n");
            break;
        }

        printf("Distance covered (in km): ");
        scanf("%f", &distance);

        // Calculate calories burned based on number of steps taken
        caloriesBurned = steps / 20;

        // Display the calories burned for the day and add to the total
        printf("Calories burned: %d\n\n", caloriesBurned);
        totalCaloriesBurned += caloriesBurned;

        // Add the steps, distance, and calories burned to their respective totals
        totalStepsTaken += steps;
        totalDistanceCovered += distance;

        // Increment the day counter
        days++;
    }

    // Display the total steps taken, distance covered, and calories burned
    printf("Total steps taken: %d\n", totalStepsTaken);
    printf("Total distance covered: %.2f km\n", totalDistanceCovered);
    printf("Total calories burned: %d\n\n", totalCaloriesBurned);

    return 0;
}