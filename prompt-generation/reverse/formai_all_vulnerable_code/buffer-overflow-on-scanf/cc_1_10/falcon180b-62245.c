//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 100000
#define MAX_CALORIES 10000

typedef struct {
    int steps;
    int distance;
    int calories;
    time_t start_time;
    time_t end_time;
} workout_t;

void start_workout(workout_t *workout) {
    workout->start_time = time(NULL);
    printf("Workout started at %s.\n", ctime(&workout->start_time));
}

void end_workout(workout_t *workout) {
    workout->end_time = time(NULL);
    printf("Workout ended at %s.\n", ctime(&workout->end_time));
    printf("Steps: %d\n", workout->steps);
    printf("Distance: %d meters\n", workout->distance);
    printf("Calories burned: %d\n", workout->calories);
}

int main() {
    workout_t workout;
    int choice;
    int steps = 0;
    int distance = 0;
    int calories = 0;

    do {
        printf("Sherlock's Fitness Tracker\n");
        printf("1. Start workout\n");
        printf("2. End workout\n");
        printf("3. View workout history\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_workout(&workout);
                break;
            case 2:
                end_workout(&workout);
                break;
            case 3:
                printf("Workout history:\n");
                for (int i = 0; i < MAX_STEPS; i++) {
                    printf("Workout #%d:\n", i+1);
                    printf("Steps: %d\n", workout.steps);
                    printf("Distance: %d meters\n", workout.distance);
                    printf("Calories burned: %d\n", workout.calories);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}