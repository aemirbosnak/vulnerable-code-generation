//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORKOUT_TYPES 10
#define MAX_WORKOUTS 100
#define MAX_WORKOUT_DURATION 60

typedef struct {
    char name[20];
    int duration;
} workout_t;

workout_t workouts[MAX_WORKOUTS];

int num_workouts = 0;

void add_workout(char* name, int duration) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }
    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    num_workouts++;
}

void print_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d minutes\n", workouts[i].name, workouts[i].duration);
    }
}

int main() {
    char input[100];
    int choice;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Add a workout\n");
    printf("2. Print workouts\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the workout: ");
            scanf("%s", input);
            printf("Enter the duration of the workout (in minutes): ");
            scanf("%d", &workouts[num_workouts-1].duration);
            add_workout(input, workouts[num_workouts-1].duration);
            break;
        case 2:
            print_workouts();
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}