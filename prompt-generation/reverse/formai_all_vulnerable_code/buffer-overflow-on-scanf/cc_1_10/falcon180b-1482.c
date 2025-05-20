//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_DURATION 60 * 60 * 24 // 1 day

typedef struct {
    char name[50];
    time_t start_time;
    int duration;
    int calories_burned;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    workouts[num_workouts].start_time = time(NULL);
    workouts[num_workouts].duration = 0;
    workouts[num_workouts].calories_burned = 0;

    num_workouts++;
}

void end_workout() {
    int i;
    time_t end_time = time(NULL);

    for (i = 0; i < num_workouts; i++) {
        if (workouts[i].start_time == end_time) {
            printf("Ending workout: %s\n", workouts[i].name);
            workouts[i].duration = difftime(end_time, workouts[i].start_time);

            if (workouts[i].duration > MAX_DURATION) {
                workouts[i].duration = MAX_DURATION;
            }

            workouts[i].calories_burned = (int) ((double) workouts[i].duration / 60 * 200);

            break;
        }
    }
}

void view_workouts() {
    int i;

    printf("Workout Name | Duration (mins) | Calories Burned\n");

    for (i = 0; i < num_workouts; i++) {
        printf("%s | %d | %d\n", workouts[i].name, workouts[i].duration, workouts[i].calories_burned);
    }
}

int main() {
    int choice;

    do {
        printf("\nFitness Tracker\n");
        printf("1. Add Workout\n");
        printf("2. End Workout\n");
        printf("3. View Workouts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_workout();
            break;
        case 2:
            end_workout();
            break;
        case 3:
            view_workouts();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}