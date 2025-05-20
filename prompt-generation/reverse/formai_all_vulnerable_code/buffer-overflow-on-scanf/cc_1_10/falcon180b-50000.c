//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 50
#define MAX_REPS 100
#define MAX_SETS 50
#define MAX_DURATION 1000 // in seconds

typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

typedef struct {
    char name[50];
    int duration; // in seconds
} Workout;

typedef struct {
    int num_workouts;
    Workout workouts[MAX_WORKOUTS];
} FitnessPlan;

void print_workout(Workout w) {
    printf("Workout: %s\n", w.name);
    printf("Duration: %d seconds\n", w.duration);
}

void print_fitness_plan(FitnessPlan fp) {
    printf("Fitness Plan:\n");
    for (int i = 0; i < fp.num_workouts; i++) {
        print_workout(fp.workouts[i]);
    }
}

int main() {
    FitnessPlan fp;
    fp.num_workouts = 0;

    char input[100];
    while (1) {
        printf("Enter a command (add_workout/print_plan/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add_workout") == 0) {
            Workout w;
            printf("Enter workout name: ");
            scanf("%s", w.name);
            printf("Enter workout duration (in seconds): ");
            scanf("%d", &w.duration);
            fp.workouts[fp.num_workouts++] = w;
        } else if (strcmp(input, "print_plan") == 0) {
            print_fitness_plan(fp);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}