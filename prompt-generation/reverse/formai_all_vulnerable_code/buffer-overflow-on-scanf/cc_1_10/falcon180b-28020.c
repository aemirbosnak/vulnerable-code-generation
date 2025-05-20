//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000
#define MAX_DISTANCE 100000

typedef struct {
    char name[50];
    int duration;
    int steps;
    int distance;
    time_t start_time;
} Workout;

void add_workout(Workout *workouts, int num_workouts, char *name, int duration, int steps, int distance) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].steps = steps;
    workouts[num_workouts].distance = distance;
    workouts[num_workouts].start_time = time(NULL);

    printf("Workout added: %s\n", name);
}

void print_workout(Workout workout) {
    printf("Name: %s\n", workout.name);
    printf("Duration: %d seconds\n", workout.duration);
    printf("Steps: %d\n", workout.steps);
    printf("Distance: %d meters\n", workout.distance);
    printf("Start time: %s\n", ctime(&workout.start_time));
}

void print_workouts(Workout *workouts, int num_workouts) {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        print_workout(workouts[i]);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    char name[50];
    int duration, steps, distance;

    while (1) {
        printf("Enter workout name (or leave blank to finish): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter workout duration in seconds: ");
        scanf("%d", &duration);

        printf("Enter number of steps: ");
        scanf("%d", &steps);

        printf("Enter distance in meters: ");
        scanf("%d", &distance);

        add_workout(workouts, num_workouts, name, duration, steps, distance);
        num_workouts++;
    }

    print_workouts(workouts, num_workouts);

    return 0;
}