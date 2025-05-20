//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_LENGTH 100

typedef struct {
    char name[32];
    int duration;
    time_t timestamp;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout(char* name, int duration) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: workout limit reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].timestamp = time(NULL);

    num_workouts++;
}

void print_workouts() {
    printf("Workout history:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d minutes - %s\n", workouts[i].name, workouts[i].duration, ctime(&workouts[i].timestamp));
    }
}

int main() {
    char name[32];
    int duration;

    while (1) {
        printf("Enter workout name: ");
        scanf("%s", name);

        printf("Enter workout duration (in minutes): ");
        scanf("%d", &duration);

        add_workout(name, duration);
    }

    return 0;
}