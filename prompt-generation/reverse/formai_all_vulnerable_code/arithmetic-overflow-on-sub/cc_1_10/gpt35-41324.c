//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>

// Define constants for weight and daily steps goals
#define WEIGHT_GOAL 70.0
#define STEPS_GOAL 10000

// Define a struct to store fitness data
struct FitnessData {
    float weight;
    int steps;
};

// Define a function to input fitness data from the user
void inputFitnessData(struct FitnessData *data) {
    printf("Enter weight in kilograms: ");
    scanf("%f", &data->weight);

    printf("Enter number of steps: ");
    scanf("%d", &data->steps);
}

// Define a function to display the user's progress
void displayProgress(struct FitnessData data) {
    printf("Weight goal:\t%.1f kg\n", WEIGHT_GOAL);
    printf("Current weight:\t%.1f kg\n", data.weight);

    printf("Steps goal:\t%d\n", STEPS_GOAL);
    printf("Current steps:\t%d\n", data.steps);
}

int main() {
    // Declare a FitnessData variable to store the user's data
    struct FitnessData myData;
    // Initialize the struct with input from the user
    inputFitnessData(&myData);

    // Display the user's progress
    displayProgress(myData);

    // Check if the user has met the weight goal
    if (myData.weight <= WEIGHT_GOAL) {
        printf("Congratulations, you have reached your weight goal!\n");
    } else {
        printf("You still need to lose %.1f kg to reach your weight goal.\n", myData.weight - WEIGHT_GOAL);
    }

    // Check if the user has met the steps goal
    if (myData.steps >= STEPS_GOAL) {
        printf("Congratulations, you have reached your steps goal!\n");
    } else {
        printf("You still need to walk %d steps to reach your steps goal.\n", STEPS_GOAL - myData.steps);
    }

    return 0;
}