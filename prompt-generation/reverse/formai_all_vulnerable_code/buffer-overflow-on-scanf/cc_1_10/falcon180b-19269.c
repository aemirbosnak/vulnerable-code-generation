//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 20
#define MAX_REPS 100
#define MAX_SETS 10

typedef struct {
    char name[50];
    int duration;
    int calories;
} workout;

typedef struct {
    char name[50];
    char muscle_group[50];
    int reps;
    int sets;
} exercise;

workout workouts[MAX_WORKOUTS];
exercise exercises[MAX_EXERCISES];
int num_workouts = 0;
int num_exercises = 0;

void add_workout() {
    num_workouts++;
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts - 1].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[num_workouts - 1].duration);
    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts - 1].calories);
}

void add_exercise() {
    num_exercises++;
    printf("Enter exercise name: ");
    scanf("%s", exercises[num_exercises - 1].name);
    printf("Enter muscle group targeted: ");
    scanf("%s", exercises[num_exercises - 1].muscle_group);
    printf("Enter reps: ");
    scanf("%d", &exercises[num_exercises - 1].reps);
    printf("Enter sets: ");
    scanf("%d", &exercises[num_exercises - 1].sets);
}

void display_workouts() {
    printf("\nWorkouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void display_exercises() {
    printf("\nExercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s - %s - %d reps - %d sets\n", exercises[i].name, exercises[i].muscle_group, exercises[i].reps, exercises[i].sets);
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add workout\n");
        printf("2. Add exercise\n");
        printf("3. Display workouts\n");
        printf("4. Display exercises\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                add_exercise();
                break;
            case 3:
                display_workouts();
                break;
            case 4:
                display_exercises();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}