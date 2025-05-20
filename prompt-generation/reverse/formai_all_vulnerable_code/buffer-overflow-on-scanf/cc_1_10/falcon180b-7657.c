//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 1000
#define MAX_WORKOUT_CALORIES 1000

struct workout {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    int calories;
};

struct workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration, calories;

    printf("Enter workout name: ");
    scanf("%s", name);

    while (true) {
        printf("Enter workout duration (in seconds): ");
        if (scanf("%d", &duration)!= 1 || duration <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        } else {
            break;
        }
    }

    while (true) {
        printf("Enter workout calories burned: ");
        if (scanf("%d", &calories)!= 1 || calories <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        } else {
            break;
        }
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].calories = calories;

    num_workouts++;
}

void view_workouts() {
    printf("Workout Name | Duration (s) | Calories burned\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%-50s | %10d | %10d\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void main() {
    while (true) {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");

        int choice;
        if (scanf("%d", &choice)!= 1 || choice < 1 || choice > 3) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            continue;
        }

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input. Please enter a number between 1 and 3.\n");
        }
    }
}