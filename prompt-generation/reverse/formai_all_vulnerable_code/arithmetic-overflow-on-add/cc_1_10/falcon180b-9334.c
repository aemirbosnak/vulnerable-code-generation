//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int steps;
    int distance;
    int calories;
    int heartRate;
    time_t timestamp;
} FitnessData;

void addFitnessData(FitnessData *data) {
    data->steps++;
    data->distance += 3; // assuming 3 meters per step
    data->calories += 1; // assuming 1 calorie per step
    data->heartRate = rand() % 100;
    data->timestamp = time(NULL);
}

void printFitnessData(FitnessData data) {
    printf("Steps: %d\n", data.steps);
    printf("Distance: %d meters\n", data.distance);
    printf("Calories burned: %d\n", data.calories);
    printf("Heart rate: %d bpm\n", data.heartRate);
    printf("Timestamp: %s", ctime(&data.timestamp));
}

int main() {
    FitnessData fitnessData;
    int choice;

    do {
        printf("1. Add fitness data\n");
        printf("2. Print fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFitnessData(&fitnessData);
                break;
            case 2:
                printFitnessData(fitnessData);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}