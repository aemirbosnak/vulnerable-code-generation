//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define constants for menu choices
#define TRACK_CURRENT_WEIGHT 1
#define TRACK_WORKOUT 2
#define VIEW_PROGRESS 3
#define QUIT_PROGRAM 4

int main()
{
    // Declare variables
    int userChoice = 0;
    float currentWeight = 0.0f;
    int daysSinceLastWorkout = 0;
    int workoutsThisWeek = 0;

    // Welcome message
    printf("Welcome to the C Fitness Tracker!\n\n");

    // Loop until the user chooses to quit
    while (userChoice != QUIT_PROGRAM)
    {
        // Display menu options
        printf("What would you like to do?\n");
        printf("%d. Track Current Weight\n", TRACK_CURRENT_WEIGHT);
        printf("%d. Track Workout\n", TRACK_WORKOUT);
        printf("%d. View Progress\n", VIEW_PROGRESS);
        printf("%d. Quit Program\n", QUIT_PROGRAM);

        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        // Handle menu choice
        switch (userChoice)
        {
            case TRACK_CURRENT_WEIGHT:
                printf("Enter your current weight: ");
                scanf("%f", &currentWeight);
                printf("Weight tracked!\n\n");
                break;

            case TRACK_WORKOUT:
                printf("Enter how many days it's been since your last workout: ");
                scanf("%d", &daysSinceLastWorkout);

                if (daysSinceLastWorkout >= 7)
                {
                    printf("You should really go workout! ");
                }

                printf("How many workouts have you done this week? ");
                scanf("%d", &workoutsThisWeek);
                printf("Workout tracked!\n\n");
                break;

            case VIEW_PROGRESS:
                printf("Current weight: %.1f\n", currentWeight);
                printf("Workouts this week: %d\n\n", workoutsThisWeek);
                break;

            case QUIT_PROGRAM:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    }

    return 0;
}