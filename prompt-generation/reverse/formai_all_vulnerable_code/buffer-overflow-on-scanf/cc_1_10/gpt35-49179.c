//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct FitnessTracker {
    int steps;
    int caloriesBurned;
    float distance;
};

void initialize(struct FitnessTracker *tracker) {
    tracker->steps = 0;
    tracker->caloriesBurned = 0;
    tracker->distance = 0.0;
}

void addSteps(struct FitnessTracker *tracker, int steps) {
    tracker->steps += steps;
    tracker->caloriesBurned += (int)(steps * 0.04);
    tracker->distance += steps * 0.000762;
}

void display(struct FitnessTracker *tracker) {
    printf("Total Steps: %d\n", tracker->steps);
    printf("Total Distance: %.2f miles\n", tracker->distance);
    printf("Total Calories Burned: %d\n", tracker->caloriesBurned);
}

int main() {
    struct FitnessTracker tracker;
    initialize(&tracker);

    printf("Welcome to Fitness Tracker!\n\n");

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add steps\n");
        printf("2. Display stats\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps: ");
                int steps;
                scanf("%d", &steps);
                addSteps(&tracker, steps);
                break;
            case 2:
                printf("\n---STATS---\n");
                display(&tracker);
                printf("-----------\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}