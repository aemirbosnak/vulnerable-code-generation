//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} workout_t;

void add_workout(workout_t workouts[], int num_workouts, char name[MAX_WORKOUT_NAME_LENGTH]) {
    printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
    struct tm start_time;
    scanf("%d-%d-%d %d:%d:%d", &start_time.tm_year, &start_time.tm_mon, &start_time.tm_mday, &start_time.tm_hour, &start_time.tm_min, &start_time.tm_sec);
    time_t start = mktime(&start_time);

    printf("Enter the end time (YYYY-MM-DD HH:MM:SS): ");
    struct tm end_time;
    scanf("%d-%d-%d %d:%d:%d", &end_time.tm_year, &end_time.tm_mon, &end_time.tm_mday, &end_time.tm_hour, &end_time.tm_min, &end_time.tm_sec);
    time_t end = mktime(&end_time);

    int duration = difftime(end, start);

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].start_time = start;
    workouts[num_workouts].end_time = end;
    workouts[num_workouts].duration = duration;

    num_workouts++;
}

void print_workouts(workout_t workouts[], int num_workouts) {
    printf("Workout Name\tStart Time\tEnd Time\tDuration\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%-50s %-20ld %-20ld %-10d\n", workouts[i].name, workouts[i].start_time, workouts[i].end_time, workouts[i].duration);
    }
}

int main() {
    int num_workouts = 0;
    workout_t workouts[MAX_WORKOUTS];

    while (num_workouts < MAX_WORKOUTS) {
        char name[MAX_WORKOUT_NAME_LENGTH];
        printf("Enter a workout name (leave blank to finish): ");
        scanf("%s", name);

        if (name[0]!= '\0') {
            add_workout(workouts, num_workouts, name);
        }
    }

    print_workouts(workouts, num_workouts);

    return 0;
}