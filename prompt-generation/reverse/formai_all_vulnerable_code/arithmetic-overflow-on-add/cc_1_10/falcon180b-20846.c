//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 3600

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} Workout;

void print_workout(Workout *workout) {
    printf("Name: %s\n", workout->name);
    printf("Start Time: %s\n", ctime(&workout->start_time));
    printf("End Time: %s\n", ctime(&workout->end_time));
    printf("Duration: %d seconds\n\n", workout->duration);
}

int main() {
    int num_workouts = 0;
    Workout workouts[MAX_WORKOUTS];

    while (num_workouts < MAX_WORKOUTS) {
        printf("Enter workout name (up to %d characters): ", MAX_WORKOUT_NAME_LENGTH);
        scanf("%s", workouts[num_workouts].name);

        time_t start_time = time(NULL);
        workouts[num_workouts].start_time = start_time;

        printf("Workout started at %s\n", ctime(&start_time));
        printf("Enter workout duration (in seconds): ");
        scanf("%d", &workouts[num_workouts].duration);

        time_t end_time = start_time + workouts[num_workouts].duration;
        workouts[num_workouts].end_time = end_time;

        printf("Workout ended at %s\n\n", ctime(&end_time));
        num_workouts++;
    }

    printf("Workout Summary:\n");
    for (int i = 0; i < num_workouts; i++) {
        print_workout(&workouts[i]);
    }

    return 0;
}