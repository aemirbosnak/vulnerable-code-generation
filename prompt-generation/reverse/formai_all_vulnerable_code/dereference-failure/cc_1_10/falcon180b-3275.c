//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_WORKOUTS 100
#define MAX_ACTIVITIES 20
#define MAX_ACTIVITY_DURATION 24*60*60
#define MAX_ACTIVITY_STEPS 100000

typedef struct {
    char name[100];
    int duration;
    int steps;
} Activity;

typedef struct {
    int num_workouts;
    Activity workouts[MAX_WORKOUTS];
} FitnessTracker;

FitnessTracker* ft;

void ft_init() {
    ft = malloc(sizeof(FitnessTracker));
    ft->num_workouts = 0;
}

void ft_add_workout(char* name, int duration, int steps) {
    if(ft->num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    Activity a;
    strcpy(a.name, name);
    a.duration = duration;
    a.steps = steps;

    ft->workouts[ft->num_workouts++] = a;
}

void ft_print_workouts() {
    if(ft->num_workouts == 0) {
        printf("No workouts recorded.\n");
        return;
    }

    for(int i=0; i<ft->num_workouts; i++) {
        printf("%s (%d minutes, %d steps)\n", ft->workouts[i].name, ft->workouts[i].duration, ft->workouts[i].steps);
    }
}

void ft_destroy() {
    free(ft);
}

int main() {
    ft_init();

    ft_add_workout("Running", 30, 5000);
    ft_add_workout("Cycling", 60, 10000);
    ft_add_workout("Swimming", 45, 3000);

    ft_print_workouts();

    ft_destroy();

    return 0;
}