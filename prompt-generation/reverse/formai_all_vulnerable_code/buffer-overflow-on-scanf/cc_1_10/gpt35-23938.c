//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/**
 * Define a structure for each day's fitness data
 */
typedef struct {
    int day;
    int steps;
    double distance;
    int calories;
    int exerciseTime;
} FitnessData;

/**
 * Define a recursive function to calculate the total steps and calories for the week
 */
void calculateTotal(int i, FitnessData week[], int *totalSteps, int *totalCalories) {
    // Base case: if all days have been processed, return
    if (i >= 7) {
        return;
    }

    // Recursively call the function for the next day
    calculateTotal(i+1, week, totalSteps, totalCalories);

    // Add the current day's data to the total
    *totalSteps += week[i].steps;
    *totalCalories += week[i].calories;
}

/**
 * Main program to gather fitness data for a week and calculate total steps and calories
 */
int main() {
    // Allocate memory for an array of 7 FitnessData structs (one for each day of the week)
    FitnessData week[7];

    // Gather data for each day of the week
    for (int i = 0; i < 7; i++) {
        printf("Enter data for Day %d:\n", i+1);
        printf("Steps: ");
        scanf("%d", &week[i].steps);
        printf("Distance (in kilometers): ");
        scanf("%lf", &week[i].distance);
        printf("Calories: ");
        scanf("%d", &week[i].calories);
        printf("Exercise time (in minutes): ");
        scanf("%d", &week[i].exerciseTime);
        week[i].day = i+1;
        printf("\n");
    }

    // Calculate the total steps and calories for the week using a recursive function
    int totalSteps = 0;
    int totalCalories = 0;
    calculateTotal(0, week, &totalSteps, &totalCalories);

    // Print out the total steps and calories for the week
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories: %d\n", totalCalories);

    return 0;
}