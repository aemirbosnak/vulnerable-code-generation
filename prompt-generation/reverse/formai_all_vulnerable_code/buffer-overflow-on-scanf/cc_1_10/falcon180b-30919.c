//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 1000

// Struct for tracking fitness data
typedef struct {
    int steps;
    double distance;
    int calories;
} FitnessData;

// Function for initializing fitness data
void initFitnessData(FitnessData *data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
}

// Function for updating fitness data
void updateFitnessData(FitnessData *data, int steps) {
    data->steps += steps;
    data->distance += steps / 10.0; // Assume each step is 10 cm
    data->calories += steps * 0.1; // Assume each step burns 0.1 calories
}

// Function for displaying fitness data
void displayFitnessData(FitnessData data) {
    printf("Steps: %d\n", data.steps);
    printf("Distance: %.2f km\n", data.distance / 1000.0);
    printf("Calories: %d\n", data.calories);
}

int main() {
    FitnessData data;
    initFitnessData(&data);

    int choice, steps;

    do {
        printf("\nFitness Tracker\n");
        printf("1. Update steps\n");
        printf("2. Display fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of steps: ");
            scanf("%d", &steps);
            if (steps > 0 && steps <= MAX_STEPS) {
                updateFitnessData(&data, steps);
                printf("Fitness data updated!\n");
            } else {
                printf("Invalid input.\n");
            }
            break;
        case 2:
            displayFitnessData(data);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}