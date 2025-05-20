//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the struct for the fitness tracker
struct fitnessTracker {
    int steps;
    float distance;
    int caloriesBurned;
};

// Function to get input from the user and update the tracker
void updateTracker(struct fitnessTracker* tracker) {
    int steps, calories;
    float distance;

    printf("Enter number of steps: ");
    scanf("%d", &steps);
    printf("Enter distance (in miles): ");
    scanf("%f", &distance);
    printf("Enter calories burned: ");
    scanf("%d", &calories);

    // Update the tracker's values
    tracker->steps += steps;
    tracker->distance += distance;
    tracker->caloriesBurned += calories;

    printf("Tracker updated successfully.\n");
}

// Function to display the current status of the tracker
void displayTracker(struct fitnessTracker* tracker) {
    printf("Today's fitness tracker status:\n");
    printf("Steps taken: %d\n", tracker->steps);
    printf("Distance covered: %.2f miles\n", tracker->distance);
    printf("Calories burned: %d\n", tracker->caloriesBurned);
}

int main() {
    // Initialize the tracker with default values
    struct fitnessTracker tracker = {0, 0.0, 0};

    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Update the fitness tracker\n");
        printf("2. Display the fitness tracker status\n");
        printf("3. Exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: updateTracker(&tracker);
                    break;
            case 2: displayTracker(&tracker);
                    break;
            case 3: printf("Goodbye!\n");
                    exit(0);
            default: printf("Invalid choice. Try again.\n");
                     break;
        }
    } while(choice != 3);

    return 0;
}