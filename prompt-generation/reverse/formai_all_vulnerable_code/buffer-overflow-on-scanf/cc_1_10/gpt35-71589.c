//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LEARNING_DAYS 21
#define TARGET_STEPS 10000

// Function to generate random number within a range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int total_days = 0; // keeps track of the total days tracked
    int learning_days = 0; // keeps track of the number of days user has tracked
    int current_steps = 0; // keeps track of the current day's steps taken
    int total_steps = 0; // keeps track of the total steps taken in all tracked days
    bool goal_met = false; // keeps track of whether the target steps goal has been met
    float average_steps = 0.0; // holds the average steps taken per day

    printf("Welcome to C Fitness Tracker!\n");

    while(total_days < LEARNING_DAYS) {
        printf("\nDay %d\n", total_days+1);

        // User input for current day's steps
        printf("Enter the steps taken today: ");
        scanf("%d", &current_steps);

        // Validate input
        while(current_steps < 0) {
            printf("Please enter a valid number of steps taken today: ");
            scanf("%d", &current_steps);
        }

        // Update the total steps
        total_steps += current_steps;

        // Check if goal has been met
        if(total_steps >= TARGET_STEPS && !goal_met) {
            goal_met = true;
            printf("Congratulations! You Have Met Your Goal!\n");
        }

        // Increment learning days and total days
        learning_days++;
        total_days++;

        // Display intermediate results
        printf("Total Steps: %d\n", total_steps);
        printf("Learning Days: %d\n", learning_days);
        
    }

    // Calculate average steps
    average_steps = total_steps / (float)LEARNING_DAYS;

    // Display final results
    printf("\nTotal steps taken in %d days: %d\n", LEARNING_DAYS, total_steps);
    printf("Average steps taken per day: %.2f\n", average_steps);

    return 0;
}