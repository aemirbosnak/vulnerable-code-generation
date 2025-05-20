//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 1000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 1000
#define MAX_WORKOUT_NAME 50

typedef struct {
    char name[MAX_WORKOUT_NAME];
    int steps;
    float distance;
    int calories;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter number of steps: ");
    scanf("%d", &workouts[num_workouts].steps);

    printf("Enter distance in meters: ");
    scanf("%f", &workouts[num_workouts].distance);

    printf("Enter number of calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    num_workouts++;
}

void display_workouts() {
    printf("\nWorkout summary:\n");
    printf("==================\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%s: %d steps, %.2f meters, %d calories\n", workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a workout\n");
        printf("2. Display workout summary\n");
        printf("3. Exit\n");

        int choice;
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
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}