//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 50
#define MAX_REPS 1000

// Define structures for workouts and exercises
typedef struct {
    char name[50];
    int duration;
} Workout;

typedef struct {
    char name[50];
    int reps;
} Exercise;

// Function prototypes
void add_workout(Workout *workout);
void add_exercise(Exercise *exercise);
void print_workouts(Workout *workouts, int num_workouts);
void print_exercises(Exercise *exercises, int num_exercises);

int main() {
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];
    int num_workouts = 0, num_exercises = 0;

    while (1) {
        printf("Enter 1 to add a workout, 2 to add an exercise, 3 to print workouts, 4 to print exercises, or 0 to quit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout(&workouts[num_workouts]);
                num_workouts++;
                break;
            case 2:
                add_exercise(&exercises[num_exercises]);
                num_exercises++;
                break;
            case 3:
                print_workouts(workouts, num_workouts);
                break;
            case 4:
                print_exercises(exercises, num_exercises);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add_workout(Workout *workout) {
    printf("Enter the name of the workout: ");
    scanf("%s", workout->name);
    printf("Enter the duration of the workout (in minutes): ");
    scanf("%d", &workout->duration);
}

void add_exercise(Exercise *exercise) {
    printf("Enter the name of the exercise: ");
    scanf("%s", exercise->name);
    printf("Enter the number of reps: ");
    scanf("%d", &exercise->reps);
}

void print_workouts(Workout *workouts, int num_workouts) {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s (%d minutes)\n", workouts[i].name, workouts[i].duration);
    }
}

void print_exercises(Exercise *exercises, int num_exercises) {
    printf("Exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s (%d reps)\n", exercises[i].name, exercises[i].reps);
    }
}