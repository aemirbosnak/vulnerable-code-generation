//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000

typedef struct {
    int steps;
    int distance;
    int calories;
} FitnessTracker;

void initFitnessTracker(FitnessTracker* tracker) {
    tracker->steps = 0;
    tracker->distance = 0;
    tracker->calories = 0;
}

void step(FitnessTracker* tracker) {
    tracker->steps++;
    tracker->distance += 1;
    tracker->calories += 1;
    printf("Step taken! Keep going! \n");
}

void run(FitnessTracker* tracker) {
    int distance;
    printf("Enter the distance you ran in meters: ");
    scanf("%d", &distance);
    if (distance > MAX_DISTANCE) {
        printf("Sorry, you ran too far! \n");
        return;
    }
    tracker->distance += distance;
    tracker->calories += distance * 10;
    printf("You burned %d calories by running %d meters! \n", distance * 10, distance);
}

void cycle(FitnessTracker* tracker) {
    int distance;
    printf("Enter the distance you cycled in meters: ");
    scanf("%d", &distance);
    if (distance > MAX_DISTANCE) {
        printf("Sorry, you cycled too far! \n");
        return;
    }
    tracker->distance += distance;
    tracker->calories += distance * 20;
    printf("You burned %d calories by cycling %d meters! \n", distance * 20, distance);
}

void swim(FitnessTracker* tracker) {
    int distance;
    printf("Enter the distance you swam in meters: ");
    scanf("%d", &distance);
    if (distance > MAX_DISTANCE) {
        printf("Sorry, you swam too far! \n");
        return;
    }
    tracker->distance += distance;
    tracker->calories += distance * 30;
    printf("You burned %d calories by swimming %d meters! \n", distance * 30, distance);
}

void displayStats(FitnessTracker tracker) {
    printf("Steps taken: %d \n", tracker.steps);
    printf("Distance covered: %d meters \n", tracker.distance);
    printf("Calories burned: %d \n", tracker.calories);
}

int main() {
    FitnessTracker tracker;
    initFitnessTracker(&tracker);

    int choice;
    while (1) {
        printf("\nFitness Tracker Menu\n");
        printf("1. Step\n");
        printf("2. Run\n");
        printf("3. Cycle\n");
        printf("4. Swim\n");
        printf("5. Display Stats\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            step(&tracker);
            break;
        case 2:
            run(&tracker);
            break;
        case 3:
            cycle(&tracker);
            break;
        case 4:
            swim(&tracker);
            break;
        case 5:
            displayStats(tracker);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! \n");
        }
    }

    return 0;
}