//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>

// declare struct for fitness tracker data
struct fitness_tracker {
    int steps;
    float distance;
    int calories_burned;
};

int main() {
    // declare variables
    int user_choice;
    struct fitness_tracker user_data = {0, 0.0, 0};

    // display menu and get user choice
    printf("Welcome to the Fitness Tracker Program!\n");
    printf("1. Record Steps\n2. Record Distance\n3. Record Calories Burned\n4. View Data\n5. Exit\n");

    do {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &user_choice);

        // perform action based on user choice
        switch (user_choice) {
            case 1:
                printf("\nEnter number of steps: ");
                scanf("%d", &user_data.steps);
                printf("Steps recorded!\n");
                break;
            case 2:
                printf("\nEnter distance in miles: ");
                scanf("%f", &user_data.distance);
                printf("Distance recorded!\n");
                break;
            case 3:
                printf("\nEnter number of calories burned: ");
                scanf("%d", &user_data.calories_burned);
                printf("Calories burned recorded!\n");
                break;
            case 4:
                printf("\nFitness Tracker Data:\n");
                printf("Steps: %d\nDistance: %.2f miles\nCalories Burned: %d\n", user_data.steps, user_data.distance, user_data.calories_burned);
                break;
            case 5:
                printf("\nExiting Fitness Tracker Program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (user_choice != 5);

    return 0;
}