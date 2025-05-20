//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int steps;
    int distance;
    int calories;
} FitnessData;

FitnessData userData;

void initialize() {
    userData.steps = 0;
    userData.distance = 0;
    userData.calories = 0;
}

void stepCounter() {
    userData.steps++;
    userData.distance += 0.762; // Distance covered per step in meters
    userData.calories += 0.0425; // Calories burned per step
}

void calculateFitness() {
    userData.calories = (userData.steps * 0.0425) + ((userData.distance - (userData.steps * 0.762)) * 0.005);
}

void displayFitnessData() {
    printf("Steps: %d\n", userData.steps);
    printf("Distance: %d meters\n", userData.distance);
    printf("Calories burned: %d\n", userData.calories);
}

int main() {
    initialize();
    int choice;
    while(true) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Step Counter\n");
        printf("2. Calculate Fitness\n");
        printf("3. Display Fitness Data\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                stepCounter();
                break;
            case 2:
                calculateFitness();
                break;
            case 3:
                displayFitnessData();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}