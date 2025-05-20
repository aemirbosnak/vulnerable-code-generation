//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_HEARTRATE 200
#define MAX_SLEEP 8

typedef struct {
    int steps;
    int heartRate;
    int sleep;
} FitnessData;

void initFitnessData(FitnessData* data) {
    data->steps = 0;
    data->heartRate = 0;
    data->sleep = 0;
}

void printFitnessData(FitnessData* data) {
    printf("Steps: %d\n", data->steps);
    printf("Heart Rate: %d\n", data->heartRate);
    printf("Sleep: %d\n", data->sleep);
}

int main() {
    FitnessData fitnessData;
    initFitnessData(&fitnessData);

    int choice;
    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Record Steps\n");
        printf("2. Record Heart Rate\n");
        printf("3. Record Sleep\n");
        printf("4. View Fitness Data\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Record Steps
                break;
            case 2:
                // Record Heart Rate
                break;
            case 3:
                // Record Sleep
                break;
            case 4:
                // View Fitness Data
                printFitnessData(&fitnessData);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(true);

    return 0;
}