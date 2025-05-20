//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int steps;
    int calories;
    int distance;
} FitnessData;

void printFitnessData(FitnessData data) {
    printf("Steps: %d\n", data.steps);
    printf("Calories: %d\n", data.calories);
    printf("Distance: %d\n", data.distance);
}

int main() {
    FitnessData data = {0, 0, 0};

    int numSteps, numCalories, numDistance;
    scanf("%d %d %d", &numSteps, &numCalories, &numDistance);

    data.steps += numSteps;
    data.calories += numCalories;
    data.distance += numDistance;

    if (data.steps % 2 == 0) {
        data.calories += 10;
    } else {
        data.distance += 5;
    }

    if (data.calories > 500) {
        data.distance += 10;
    } else if (data.calories > 250) {
        data.steps += 5;
    }

    if (data.distance > 1000) {
        data.calories += 15;
    } else if (data.distance > 500) {
        data.steps += 10;
    }

    printf("\n");
    printFitnessData(data);

    return 0;
}