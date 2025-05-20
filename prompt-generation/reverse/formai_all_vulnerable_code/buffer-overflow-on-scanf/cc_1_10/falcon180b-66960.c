//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 20
#define MAX_REPS 100
#define MAX_SETS 10
#define MAX_DURATION 1800 // 30 minutes

typedef struct {
    char name[50];
    int reps;
    int sets;
    int duration;
} Exercise;

typedef struct {
    char name[50];
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    workouts[num_workouts].num_exercises = 0;
    num_workouts++;
}

void add_exercise(int workout_index) {
    printf("Enter exercise name: ");
    scanf("%s", workouts[workout_index].exercises[workouts[workout_index].num_exercises].name);
    printf("Enter reps: ");
    scanf("%d", &workouts[workout_index].exercises[workouts[workout_index].num_exercises].reps);
    printf("Enter sets: ");
    scanf("%d", &workouts[workout_index].exercises[workouts[workout_index].num_exercises].sets);
    printf("Enter duration (in seconds): ");
    scanf("%d", &workouts[workout_index].exercises[workouts[workout_index].num_exercises].duration);
    workouts[workout_index].num_exercises++;
}

void view_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\n", workouts[i].name);
    }
}

void start_workout(int workout_index) {
    int total_duration = 0;
    for (int i = 0; i < workouts[workout_index].num_exercises; i++) {
        total_duration += workouts[workout_index].exercises[i].duration;
    }
    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < total_duration) {
        for (int i = 0; i < workouts[workout_index].num_exercises; i++) {
            printf("%s: ", workouts[workout_index].exercises[i].name);
            for (int j = 0; j < workouts[workout_index].exercises[i].sets; j++) {
                for (int k = 0; k < workouts[workout_index].exercises[i].reps; k++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    printf("Workout complete!\n");
}

int main() {
    add_workout();
    add_workout();
    add_exercise(0);
    add_exercise(0);
    add_exercise(1);
    view_workouts();
    start_workout(0);
    return 0;
}