//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_STEPS 1000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 1000

typedef struct {
    char name[50];
    int steps;
    int distance;
    int calories;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Cannot add more workouts.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter number of steps: ");
    scanf("%d", &workouts[num_workouts].steps);

    printf("Enter distance in meters: ");
    scanf("%d", &workouts[num_workouts].distance);

    printf("Enter calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    num_workouts++;
}

void display_workouts() {
    if (num_workouts == 0) {
        printf("No workouts yet.\n");
        return;
    }

    for (int i = 0; i < num_workouts; i++) {
        printf("%s: Steps - %d, Distance - %d meters, Calories burned - %d\n",
               workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
}

int main() {
    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}