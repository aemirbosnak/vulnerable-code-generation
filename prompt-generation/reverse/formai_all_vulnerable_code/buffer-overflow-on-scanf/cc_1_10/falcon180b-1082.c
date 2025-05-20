//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DAYS 365

typedef struct {
    char name[20];
    int steps;
    int distance;
    int calories;
    int activeTime;
    int heartRate;
} FitnessData;

typedef struct {
    FitnessData data[MAX_DAYS];
    int dayCount;
} FitnessTracker;

void initFitnessTracker(FitnessTracker* tracker) {
    tracker->dayCount = 0;
}

void addFitnessData(FitnessTracker* tracker, FitnessData data) {
    if (tracker->dayCount >= MAX_DAYS) {
        printf("Error: Maximum number of days reached.\n");
        return;
    }
    tracker->data[tracker->dayCount++] = data;
}

void printFitnessData(FitnessData data) {
    printf("Name: %s\n", data.name);
    printf("Steps: %d\n", data.steps);
    printf("Distance: %d meters\n", data.distance);
    printf("Calories burned: %d\n", data.calories);
    printf("Active time: %d minutes\n", data.activeTime);
    printf("Heart rate: %d bpm\n\n", data.heartRate);
}

void printFitnessSummary(FitnessTracker tracker) {
    printf("Fitness summary for the last %d days:\n", tracker.dayCount);
    for (int i = 0; i < tracker.dayCount; i++) {
        printFitnessData(tracker.data[i]);
    }
}

int main() {
    FitnessTracker tracker;
    initFitnessTracker(&tracker);

    FitnessData data;
    while (true) {
        printf("Enter your name (or type 'quit' to exit):\n");
        scanf("%s", data.name);
        if (strcmp(data.name, "quit") == 0) {
            break;
        }

        printf("Enter the number of steps taken today:\n");
        scanf("%d", &data.steps);

        printf("Enter the distance covered today in meters:\n");
        scanf("%d", &data.distance);

        printf("Enter the number of calories burned today:\n");
        scanf("%d", &data.calories);

        printf("Enter the active time in minutes today:\n");
        scanf("%d", &data.activeTime);

        printf("Enter your heart rate in bpm:\n");
        scanf("%d", &data.heartRate);

        addFitnessData(&tracker, data);
    }

    printFitnessSummary(tracker);

    return 0;
}