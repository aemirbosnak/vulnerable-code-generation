//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STEPS 100000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 1000

typedef struct {
    int steps;
    double distance;
    int calories;
} FitnessData;

FitnessData fitnessData = {0};

void updateFitnessData() {
    fitnessData.steps++;
    fitnessData.distance += 0.01;
    fitnessData.calories += 1;
}

void printFitnessData() {
    printf("Steps: %d\n", fitnessData.steps);
    printf("Distance: %.2f km\n", fitnessData.distance);
    printf("Calories burned: %d\n", fitnessData.calories);
}

int main() {
    int choice;
    do {
        printf("1. Update fitness data\n");
        printf("2. Print fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateFitnessData();
                break;
            case 2:
                printFitnessData();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}