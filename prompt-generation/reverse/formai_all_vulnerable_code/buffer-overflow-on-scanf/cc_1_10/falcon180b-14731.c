//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50

typedef struct workout {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    int calories;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts == MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[num_workouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    num_workouts++;
}

void display_workouts() {
    printf("\nWorkout summary:\n");
    printf("-----------------\n");

    if (num_workouts == 0) {
        printf("No workouts recorded.\n");
        return;
    }

    for (int i = 0; i < num_workouts; i++) {
        printf("Workout %d: %s\n", i + 1, workouts[i].name);
        printf("Duration: %d minutes\n", workouts[i].duration);
        printf("Calories burned: %d\n", workouts[i].calories);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    add_workout();
    add_workout();
    add_workout();

    display_workouts();

    return 0;
}