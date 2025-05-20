//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
    int steps;
    float distance;
    float calories;
} User;

int main() {
    // Create a new user
    User user;
    strcpy(user.name, "John Doe");
    user.age = 30;
    user.height = 1.80;
    user.weight = 75.0;
    user.steps = 0;
    user.distance = 0.0;
    user.calories = 0.0;

    // Get the current time
    time_t now = time(NULL);

    // Initialize the fitness tracker
    printf("Welcome to your Fitness Tracker, %s!\n", user.name);

    // Main loop
    while (1) {
        // Display the menu
        printf("\n[1] Start Tracking\n");
        printf("[2] Stop Tracking\n");
        printf("[3] Show Progress\n");
        printf("[4] Exit\n");
        printf("\nYour choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Start tracking
                printf("\nTracking started.\n");
                user.steps = 0;
                user.distance = 0.0;
                user.calories = 0.0;
                now = time(NULL);
                break;
            case 2:
                // Stop tracking
                printf("\nTracking stopped.\n");
                time_t now2 = time(NULL);
                float elapsed_time = difftime(now2, now);
                user.distance = user.steps * 0.75;
                user.calories = user.steps * 0.05 * user.weight;
                break;
            case 3:
                // Show progress
                printf("\nYour progress:\n");
                printf("Steps: %d\n", user.steps);
                printf("Distance: %.2f km\n", user.distance);
                printf("Calories burned: %.2f kcal\n", user.calories);
                break;
            case 4:
                // Exit
                printf("\nThank you for using your Fitness Tracker!\n");
                return 0;
            default:
                // Invalid choice
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}