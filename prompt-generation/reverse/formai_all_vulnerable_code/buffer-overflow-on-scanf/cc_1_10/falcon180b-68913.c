//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 50

struct workout {
    char name[50];
    int duration;
};

void addWorkout(struct workout *workouts, int numWorkouts, char *name, int duration) {
    if (numWorkouts >= MAX_WORKOUTS) {
        printf("Sorry, you can only add up to %d workouts.\n", MAX_WORKOUTS);
        return;
    }
    strcpy(workouts[numWorkouts].name, name);
    workouts[numWorkouts].duration = duration;
    numWorkouts++;
}

void printWorkouts(struct workout *workouts, int numWorkouts) {
    printf("Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d minutes\n", workouts[i].name, workouts[i].duration);
    }
}

void trackFitness(struct workout *workouts, int numWorkouts) {
    int choice;
    char name[50];
    int duration;

    while (1) {
        printf("1. Add a workout\n2. Print workouts\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter workout name: ");
            scanf("%s", name);
            printf("Enter workout duration in minutes: ");
            scanf("%d", &duration);
            addWorkout(workouts, numWorkouts, name, duration);
            break;
        case 2:
            printWorkouts(workouts, numWorkouts);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    trackFitness(workouts, numWorkouts);

    return 0;
}