//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000

typedef struct {
    char name[50];
    int steps;
    double distance;
    int calories;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter number of steps: ");
    scanf("%d", &workouts[num_workouts].steps);

    printf("Enter distance in meters: ");
    scanf("%lf", &workouts[num_workouts].distance);

    printf("Enter calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    num_workouts++;
}

void display_workouts() {
    printf("\nWorkout Summary:\n");
    printf("------------------\n");

    if (num_workouts == 0) {
        printf("No workouts recorded.\n");
        return;
    }

    printf("Name\tSteps\tDistance (m)\tCalories\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t%d\t%.2lf\t%d\n", workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
}

void clear_workouts() {
    num_workouts = 0;
    printf("\nAll workouts cleared.\n");
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("\nFitness Tracker\n");
        printf("-----------------\n");
        printf("1. Add workout\n");
        printf("2. Display summary\n");
        printf("3. Clear all workouts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_workouts();
                break;
            case 3:
                clear_workouts();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}