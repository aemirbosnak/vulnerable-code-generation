//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEP_COUNT 100
#define MAX_CALORIES_BURNED 100
#define MAX_DISTANCE_TRAVELED 100

typedef struct {
    int steps;
    int calories;
    float distance;
} FitnessData;

FitnessData fitnessData[MAX_STEP_COUNT];
int currentIndex = 0;

void addFitnessData(int steps, int calories, float distance) {
    if (currentIndex >= MAX_STEP_COUNT) {
        fprintf(stderr, "Error: Maximum number of fitness data exceeded.\n");
        return;
    }

    fitnessData[currentIndex].steps = steps;
    fitnessData[currentIndex].calories = calories;
    fitnessData[currentIndex].distance = distance;

    currentIndex++;
}

void displayFitnessData() {
    printf("Steps: %d\n", fitnessData[0].steps);
    printf("Calories: %d\n", fitnessData[0].calories);
    printf("Distance: %f\n", fitnessData[0].distance);
}

int main() {
    int steps, calories, distance;

    while (1) {
        printf("Enter steps (0-99): ");
        scanf("%d", &steps);

        if (steps == 0) {
            break;
        }

        printf("Enter calories burned (0-99): ");
        scanf("%d", &calories);

        printf("Enter distance traveled (0-99.99): ");
        scanf("%f", &distance);

        addFitnessData(steps, calories, distance);
    }

    displayFitnessData();

    return 0;
}