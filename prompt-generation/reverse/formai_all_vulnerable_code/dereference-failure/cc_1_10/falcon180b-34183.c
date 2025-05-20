//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000
#define MAX_WORKOUTS 100

typedef struct {
    int steps;
    int distance;
    int calories;
} workout_t;

typedef struct {
    int num_workouts;
    workout_t workouts[MAX_WORKOUTS];
} fitness_t;

fitness_t *fitness_tracker_create() {
    fitness_t *ft = malloc(sizeof(fitness_t));
    ft->num_workouts = 0;
    return ft;
}

void fitness_tracker_destroy(fitness_t *ft) {
    free(ft);
}

void fitness_tracker_add_workout(fitness_t *ft, int steps, int distance, int calories) {
    if (ft->num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }
    workout_t w = {steps, distance, calories};
    ft->workouts[ft->num_workouts++] = w;
}

void fitness_tracker_print_workouts(fitness_t *ft) {
    printf("Workouts:\n");
    for (int i = 0; i < ft->num_workouts; i++) {
        printf("%d: Steps - %d, Distance - %d, Calories - %d\n", i+1, ft->workouts[i].steps, ft->workouts[i].distance, ft->workouts[i].calories);
    }
}

void fitness_tracker_print_stats(fitness_t *ft) {
    int total_steps = 0, total_distance = 0, total_calories = 0;
    for (int i = 0; i < ft->num_workouts; i++) {
        total_steps += ft->workouts[i].steps;
        total_distance += ft->workouts[i].distance;
        total_calories += ft->workouts[i].calories;
    }
    printf("Total Steps - %d\n", total_steps);
    printf("Total Distance - %d\n", total_distance);
    printf("Total Calories - %d\n", total_calories);
}

int main() {
    fitness_t *ft = fitness_tracker_create();
    fitness_tracker_add_workout(ft, 5000, 3000, 200);
    fitness_tracker_add_workout(ft, 6000, 3500, 250);
    fitness_tracker_print_workouts(ft);
    fitness_tracker_print_stats(ft);
    fitness_tracker_destroy(ft);
    return 0;
}