//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LENGTH 50
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION_MINUTES 180
#define MAX_WORKOUT_DURATION_SECONDS (MAX_WORKOUT_DURATION_MINUTES * 60)

typedef struct {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int calories_per_minute;
} Activity;

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration_minutes;
    int duration_seconds;
    Activity activity;
} Workout;

void print_workouts(Workout workouts[], int num_workouts) {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%d. %s (%d minutes, %d seconds)\n", i+1, workouts[i].name, workouts[i].duration_minutes, workouts[i].duration_seconds);
    }
}

int main() {
    int num_workouts = 0;
    Workout workouts[MAX_WORKOUTS];

    while (num_workouts < MAX_WORKOUTS) {
        printf("Enter the name of the workout (or 'done' to finish):\n");
        scanf("%s", workouts[num_workouts].name);

        if (strcmp(workouts[num_workouts].name, "done") == 0) {
            break;
        }

        printf("Enter the duration of the workout in minutes:\n");
        scanf("%d", &workouts[num_workouts].duration_minutes);

        if (workouts[num_workouts].duration_minutes > MAX_WORKOUT_DURATION_MINUTES) {
            printf("Workout duration must be less than or equal to %d minutes.\n", MAX_WORKOUT_DURATION_MINUTES);
            num_workouts--;
            continue;
        }

        workouts[num_workouts].duration_seconds = workouts[num_workouts].duration_minutes * 60;

        printf("Enter the name of the activity:\n");
        scanf("%s", workouts[num_workouts].activity.name);

        printf("Enter the calories burned per minute for the activity:\n");
        scanf("%d", &workouts[num_workouts].activity.calories_per_minute);

        if (workouts[num_workouts].activity.calories_per_minute <= 0) {
            printf("Calories burned per minute must be greater than zero.\n");
            num_workouts--;
            continue;
        }

        num_workouts++;
    }

    printf("Workouts:\n");
    print_workouts(workouts, num_workouts);

    return 0;
}