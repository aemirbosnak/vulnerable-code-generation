//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store user's daily activity data
typedef struct {
    char activity[20];
    int calories;
    int steps;
} DailyActivity;

// Global variables for tracking total calories and steps
int total_calories = 0;
int total_steps = 0;

// Function to add user's daily activity to the total
void add_daily_activity(DailyActivity activity) {
    total_calories += activity.calories;
    total_steps += activity.steps;
    printf("\nYou've logged: %s, %d calories, and %d steps.", activity.activity, activity.calories, activity.steps);
}

int main() {
    char activity[20];
    int calories, steps;

    // Welcome message
    printf("\n*************************************************\n");
    printf("*              Welcome to FitBuddy!              *\n");
    printf("*                                               *\n");
    printf("*             A simple C fitness tracker           *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");

    // Main loop for user to input daily activities
    while (1) {
        printf("\nEnter today's activity (or type 'quit' to exit): ");
        scanf("%s", activity);

        if (strcmp(activity, "quit") == 0) {
            break;
        }

        printf("How many calories did you burn during this activity?: ");
        scanf("%d", &calories);

        printf("How many steps did you take during this activity?: ");
        scanf("%d", &steps);

        // Create a DailyActivity struct and add it to the total
        DailyActivity new_activity = {"", calories, steps};
        strcpy(new_activity.activity, activity);
        add_daily_activity(new_activity);
    }

    // Display user's total calories burned and steps taken
    printf("\n*************************************************\n");
    printf("*                Your Stats                       *\n");
    printf("*                                               *\n");
    printf("* Total calories burned: %d                       *\n", total_calories);
    printf("* Total steps taken: %d                          *\n", total_steps);
    printf("*************************************************\n");

    return 0;
}