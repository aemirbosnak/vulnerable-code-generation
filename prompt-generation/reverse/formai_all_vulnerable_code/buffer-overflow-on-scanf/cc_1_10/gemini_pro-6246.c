//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Constants
#define STEPS_GOAL 10000
#define CALORIES_GOAL 2000

// Data structure to store fitness data
typedef struct {
    int steps;
    int calories;
} FitnessData;

// Function to get fitness data from the user
FitnessData getFitnessData() {
    FitnessData data;

    // Get steps from the user
    printf("Enter the number of steps you have taken today: ");
    scanf("%d", &data.steps);

    // Get calories from the user
    printf("Enter the number of calories you have burned today: ");
    scanf("%d", &data.calories);

    return data;
}

// Function to print fitness data
void printFitnessData(FitnessData data) {
    printf("Steps taken: %d\n", data.steps);
    printf("Calories burned: %d\n", data.calories);
}

// Function to check if the fitness goals have been met
bool goalMet(FitnessData data) {
    return data.steps >= STEPS_GOAL && data.calories >= CALORIES_GOAL;
}

// Function to main
int main() {
    // Get fitness data from the user
    FitnessData data = getFitnessData();

    // Print fitness data
    printFitnessData(data);

    // Check if the fitness goals have been met
    if (goalMet(data)) {
        printf("Congratulations! You have met your fitness goals for today.\n");
    } else {
        printf("Keep up the good work! You have not yet met your fitness goals for today.\n");
    }

    return 0;
}