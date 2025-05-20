//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_REPS 100

struct workout {
    char name[50];
    int reps;
    time_t timestamp;
};

void add_workout(struct workout *workouts, int num_workouts) {
    char input[100];
    printf("Enter workout name: ");
    scanf("%s", input);
    strcpy(workouts[num_workouts].name, input);
    printf("Enter number of reps: ");
    scanf("%d", &workouts[num_workouts].reps);
    workouts[num_workouts].timestamp = time(NULL);
    num_workouts++;
}

void display_workouts(struct workout *workouts, int num_workouts) {
    printf("Workout log:\n");
    printf("-------------------\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d reps - %s\n", workouts[i].name, workouts[i].reps, ctime(&workouts[i].timestamp));
    }
}

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (num_workouts < MAX_WORKOUTS) {
        printf("Enter 1 to add a workout or 0 to quit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_workout(workouts, num_workouts);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Workout log:\n");
    printf("-------------------\n");
    display_workouts(workouts, num_workouts);

    return 0;
}