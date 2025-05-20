//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_WORKOUT_LENGTH 100

typedef struct {
    char name[MAX_SIZE];
    int length;
    int caloriesBurned;
} Workout;

Workout workouts[MAX_SIZE];
int numWorkouts;

void addWorkout() {
    printf("Enter the name of the workout: ");
    scanf("%s", workouts[numWorkouts].name);

    printf("Enter the length of the workout in minutes: ");
    scanf("%d", &workouts[numWorkouts].length);

    printf("Enter the number of calories burned during the workout: ");
    scanf("%d", &workouts[numWorkouts].caloriesBurned);

    numWorkouts++;
}

void viewWorkouts() {
    printf("\nWorkout log:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s\nLength: %d minutes\nCalories burned: %d\n", workouts[i].name, workouts[i].length, workouts[i].caloriesBurned);
    }
}

void deleteWorkout() {
    printf("Enter the name of the workout you want to delete: ");
    char name[MAX_SIZE];
    scanf("%s", name);

    for (int i = 0; i < numWorkouts; i++) {
        if (strcmp(workouts[i].name, name) == 0) {
            for (int j = i; j < numWorkouts - 1; j++) {
                strcpy(workouts[j].name, workouts[j + 1].name);
                workouts[j].length = workouts[j + 1].length;
                workouts[j].caloriesBurned = workouts[j + 1].caloriesBurned;
            }
            numWorkouts--;
            break;
        }
    }
}

int main() {
    numWorkouts = 0;

    while (true) {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n2. View workout log\n3. Delete workout\n4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addWorkout();
            break;
        case 2:
            viewWorkouts();
            break;
        case 3:
            deleteWorkout();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}