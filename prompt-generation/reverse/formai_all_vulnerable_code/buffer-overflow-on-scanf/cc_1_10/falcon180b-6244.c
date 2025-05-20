//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10

typedef struct {
    char name[50];
    int duration;
    time_t start_time;
    time_t end_time;
} Workout;

void add_workout(Workout workouts[], int num_workouts) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Sorry, you can only track up to %d workouts.\n", MAX_WORKOUTS);
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[num_workouts].duration);

    time(&workouts[num_workouts].start_time);

    workouts[num_workouts].end_time = workouts[num_workouts].start_time + workouts[num_workouts].duration;

    printf("Workout added successfully.\n");
}

void view_workouts(Workout workouts[], int num_workouts) {
    printf("Workout Name | Duration | Start Time | End Time\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s | %d seconds | %s | %s\n", workouts[i].name, workouts[i].duration, ctime(&workouts[i].start_time), ctime(&workouts[i].end_time));
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_workout(workouts, num_workouts);
            break;

        case 2:
            view_workouts(workouts, num_workouts);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}