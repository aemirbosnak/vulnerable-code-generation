//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_REPS 100
#define MAX_SETS 100
#define MAX_DURATION 100

typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

typedef struct {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
    Exercise exercises[MAX_EXERCISES];
} Workout;

void add_workout(Workout* workouts, int num_workouts) {
    printf("Enter workout name: ");
    scanf("%s", (*workouts).name);
    printf("Enter workout duration (in seconds): ");
    scanf("%d", &((*workouts).duration));
    (*workouts).start_time = time(NULL);
}

void add_exercise(Workout* workouts, int num_workouts, int workout_index) {
    printf("Enter exercise name: ");
    scanf("%s", (*workouts).exercises[workout_index].name);
    printf("Enter number of reps: ");
    scanf("%d", &((*workouts).exercises[workout_index].reps));
    printf("Enter number of sets: ");
    scanf("%d", &((*workouts).exercises[workout_index].sets));
}

void print_workout(Workout workout) {
    printf("Workout name: %s\n", workout.name);
    printf("Duration: %d seconds\n", workout.duration);
    printf("Start time: %s\n", ctime(&workout.start_time));
    printf("End time: %s\n", ctime(&workout.end_time));
    printf("Exercises:\n");
    for (int i = 0; i < workout.duration; i++) {
        printf("\t%s - %d reps, %d sets\n", workout.exercises[i].name, workout.exercises[i].reps, workout.exercises[i].sets);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (num_workouts < MAX_WORKOUTS) {
        printf("Enter 1 to add a workout, 0 to exit: ");
        scanf("%d", &num_workouts);
        if (num_workouts == 1) {
            add_workout(workouts, num_workouts);
            num_workouts++;
        }
    }

    printf("Enter 1 to view all workouts, 0 to exit: ");
    scanf("%d", &num_workouts);
    if (num_workouts == 1) {
        for (int i = 0; i < num_workouts; i++) {
            print_workout(workouts[i]);
        }
    }

    return 0;
}