//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>

typedef struct {
    int calories;
    int steps;
    float distance;
} FitnessTracker;

int main() {
    FitnessTracker tracker;
    tracker.calories = 0;
    tracker.steps = 0;
    tracker.distance = 0.0;

    printf("Welcome to the Fitness Tracker!\n");
    printf("What activity did you perform? (1 for walking, 2 for running, 3 for cycling)\n");
    int activity = 1; // Default activity is walking

    while (1) {
        printf("Enter the number of calories burned: ");
        scanf("%d", &tracker.calories);
        printf("Enter the number of steps taken: ");
        scanf("%d", &tracker.steps);
        printf("Enter the distance covered in meters: ");
        scanf("%f", &tracker.distance);

        if (activity == 1) {
            printf("Walking activity. Calories: %d, Steps: %d, Distance: %.2f\n", tracker.calories, tracker.steps, tracker.distance);
        } else if (activity == 2) {
            printf("Running activity. Calories: %d, Steps: %d, Distance: %.2f\n", tracker.calories, tracker.steps, tracker.distance);
        } else if (activity == 3) {
            printf("Cycling activity. Calories: %d, Steps: %d, Distance: %.2f\n", tracker.calories, tracker.steps, tracker.distance);
        } else {
            printf("Invalid activity. Please try again.\n");
        }

        printf("Do you want to continue? (Y/N): ");
        char response;
        scanf(" %c", &response);

        if (response == 'Y' || response == 'y') {
            printf("\n");
            continue;
        } else if (response == 'N' || response == 'n') {
            printf("\nThank you for using the Fitness Tracker!\n");
            break;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}