//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fitnessTracker {
    int steps;
    float distance;
    float calories;
};

void recordSteps(struct fitnessTracker *tracker, int newSteps);
void computeDistance(struct fitnessTracker *tracker, float strideLength);
void computeCalories(struct fitnessTracker *tracker, float weightInKilograms);

int main() {
    struct fitnessTracker myTracker = {0, 0.0, 0.0};
    float myStrideLength = 0.8;
    float myWeightInKilograms = 72.5;
    bool programRunning = true;
    char userInput;

    printf("Welcome to the Fitness Tracker Program!\n\n");

    while (programRunning) {
        printf("MENU:\n");
        printf("1: Record Steps\n");
        printf("2: Compute Distance\n");
        printf("3: Compute Calories\n");
        printf("Q: Quit Program\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &userInput);

        switch (userInput) {
            case '1':
                printf("\nEnter number of steps: ");
                int newSteps;
                scanf("%d", &newSteps);
                recordSteps(&myTracker, newSteps);
                break;
            case '2':
                printf("\nComputing distance...\n");
                computeDistance(&myTracker, myStrideLength);
                printf("Total Distance: %.2f kilometers\n", myTracker.distance);
                break;
            case '3':
                printf("\nComputing calories...\n");
                computeCalories(&myTracker, myWeightInKilograms);
                printf("Total Calories: %.2f kcal\n", myTracker.calories);
                break;
            case 'q':
            case 'Q':
                printf("\nExiting program...\n");
                programRunning = false;
                break;
            default:
                printf("\nERROR: Invalid input\n");
                break;
        }
    }

    return 0;
}

void recordSteps(struct fitnessTracker *tracker, int newSteps) {
    tracker->steps += newSteps;
    printf("Total Steps: %d\n", tracker->steps);
}

void computeDistance(struct fitnessTracker *tracker, float strideLength) {
    tracker->distance = strideLength * tracker->steps / 1000.0;
}

void computeCalories(struct fitnessTracker *tracker, float weightInKilograms) {
    tracker->calories = 0.05 * weightInKilograms * tracker->distance * 1000.0;
}