//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP_GOAL_DEFAULT 5000
#define CALORIES_PER_STEP 0.02
#define KM_PER_MILE 1.60934

typedef struct {
    int steps;
    int calories;
    int distance;
    int goal;
} FitnessTracker;

void print_menu() {
    printf("\nFitness Tracker\n");
    printf("------------------\n");
    printf("1. Record steps and calculate calories\n");
    printf("2. Set daily step goal\n");
    printf("3. View current progress\n");
    printf("4. Exit\n");
}

void record_steps(FitnessTracker *tracker) {
    int steps;
    printf("Enter number of steps taken today: ");
    scanf("%d", &steps);

    tracker->steps += steps;
    tracker->calories += steps * CALORIES_PER_STEP;

    double distance = steps * (1.0 / KM_PER_MILE);
    tracker->distance += (int)(distance + 0.5);
}

void set_goal(FitnessTracker *tracker) {
    int goal;

    if (tracker->goal > 0) {
        printf("Current goal: %d steps\n", tracker->goal);
        return;
    }

    printf("Enter daily step goal: ");
    scanf("%d", &goal);

    if (goal > 0) {
        tracker->goal = goal;
        printf("Goal set to %d steps.\n", goal);
    } else {
        printf("Invalid goal. Please enter a positive value.\n");
    }
}

void view_progress(FitnessTracker *tracker) {
    int progress = (tracker->steps * 100) / tracker->goal;

    printf("\nCurrent Progress:\n");
    printf("------------------\n");
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Distance: %.2f miles\n", tracker->distance / 1609.34);
    printf("Goal: %d steps\n", tracker->goal);
    printf("Progress: %d%%\n", progress);
}

int main() {
    FitnessTracker tracker = {0, 0, 0, STEP_GOAL_DEFAULT};
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_steps(&tracker);
                break;
            case 2:
                set_goal(&tracker);
                break;
            case 3:
                view_progress(&tracker);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 4.\n");
        }
    }

    return 0;
}