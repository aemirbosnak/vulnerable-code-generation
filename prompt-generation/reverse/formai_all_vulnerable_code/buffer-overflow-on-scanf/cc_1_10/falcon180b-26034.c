//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} Workout;

void add_workout(Workout* workouts, int num_workouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter workout description: ");
    scanf("%s", workouts[num_workouts].description);
    workouts[num_workouts].start_time = time(NULL);
    printf("Workout started.\n");
}

void end_workout(Workout* workouts, int num_workouts) {
    workouts[num_workouts].end_time = time(NULL);
    workouts[num_workouts].duration = difftime(workouts[num_workouts].end_time, workouts[num_workouts].start_time);
    printf("Workout ended. Duration: %d seconds.\n", workouts[num_workouts].duration);
}

void print_workouts(Workout* workouts, int num_workouts) {
    printf("Workout summary:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("Name: %s\nDescription: %s\nDuration: %d seconds\n\n", workouts[i].name, workouts[i].description, workouts[i].duration);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (num_workouts < MAX_WORKOUTS) {
        int choice;
        printf("1. Add workout\n2. End workout\n3. Print summary\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_workouts >= MAX_WORKOUTS) {
                printf("Maximum number of workouts reached.\n");
            } else {
                add_workout(workouts, num_workouts);
                num_workouts++;
            }
            break;
        case 2:
            if (num_workouts == 0) {
                printf("No workout in progress.\n");
            } else {
                end_workout(workouts, num_workouts - 1);
                num_workouts--;
            }
            break;
        case 3:
            print_workouts(workouts, num_workouts);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}