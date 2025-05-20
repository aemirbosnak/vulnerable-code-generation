//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>  // include standard input and output library
#include <stdlib.h> // include library for dynamic memory allocation
#include <stdbool.h> // include library for boolean values

// define a struct for storing fitness data
typedef struct {
    int stepCount;
    float distance;
    float caloriesBurned;
} FitnessData;

// declare functions
FitnessData* initFitnessData(int initialStepCount, float initialDistance, float initialCaloriesBurned);
void updateStepCount(FitnessData* data, int steps);
void updateDistance(FitnessData* data, float distance);
void updateCaloriesBurned(FitnessData* data, float calories);
void printFitnessData(FitnessData* data);

// main function
int main() {
    // initialize fitness data struct
    FitnessData* data = initFitnessData(0, 0.0, 0.0);

    // get user input and update fitness data
    int userChoice = 0;
    while (userChoice != 4) {
        printf("Choose an option:\n");
        printf("1. Update step count\n");
        printf("2. Update distance\n");
        printf("3. Update calories burned\n");
        printf("4. Quit\n");

        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                printf("Enter the number of steps taken: ");
                int stepCount;
                scanf("%d", &stepCount);
                updateStepCount(data, stepCount);
                break;
            case 2:
                printf("Enter the distance traveled in miles: ");
                float distance;
                scanf("%f", &distance);
                updateDistance(data, distance);
                break;
            case 3:
                printf("Enter the calories burned: ");
                float calories;
                scanf("%f", &calories);
                updateCaloriesBurned(data, calories);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printFitnessData(data);
        printf("\n");
    }

    // free memory allocated for fitness data struct
    free(data);

    return 0;
}

// define function for initializing fitness data struct
FitnessData* initFitnessData(int initialStepCount, float initialDistance, float initialCaloriesBurned) {
    FitnessData* data = (FitnessData*)malloc(sizeof(FitnessData));
    data->stepCount = initialStepCount;
    data->distance = initialDistance;
    data->caloriesBurned = initialCaloriesBurned;
    return data;
}

// define function for updating step count in fitness data struct
void updateStepCount(FitnessData* data, int steps) {
    data->stepCount += steps;
}

// define function for updating distance in fitness data struct
void updateDistance(FitnessData* data, float distance) {
    data->distance += distance;
}

// define function for updating calories burned in fitness data struct
void updateCaloriesBurned(FitnessData* data, float calories) {
    data->caloriesBurned += calories;
}

// define function for printing fitness data struct
void printFitnessData(FitnessData* data) {
    printf("Step count: %d\n", data->stepCount);
    printf("Distance: %.2f miles\n", data->distance);
    printf("Calories burned: %.2f\n", data->caloriesBurned);
}