//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories;
    time_t start_time;
    time_t end_time;
} Workout;

void add_workout(Workout workouts[], int num_workouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[num_workouts].duration);
    printf("Enter calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);
    workouts[num_workouts].start_time = time(NULL);
    workouts[num_workouts].end_time = 0;
    num_workouts++;
}

void print_workout(Workout workout) {
    printf("Workout name: %s\n", workout.name);
    printf("Duration: %d seconds\n", workout.duration);
    printf("Calories burned: %d\n", workout.calories);
    printf("Start time: %s\n", ctime(&workout.start_time));
    if (workout.end_time!= 0) {
        printf("End time: %s\n", ctime(&workout.end_time));
    } else {
        printf("Workout is still in progress...\n");
    }
}

void main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add workout\n");
        printf("2. Print workouts\n");
        printf("3. Exit\n");
        scanf("%d", &num_workouts);

        switch (num_workouts) {
        case 1:
            if (num_workouts >= MAX_WORKOUTS) {
                printf("Maximum number of workouts reached.\n");
            } else {
                add_workout(workouts, num_workouts);
            }
            break;

        case 2:
            printf("\nWorkout history:\n");
            for (int i = 0; i < num_workouts; i++) {
                print_workout(workouts[i]);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }
}