//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_DURATION 3600 // 1 hour

typedef struct {
    char name[20];
    int duration;
    time_t start_time;
} workout_t;

int main() {
    int num_workouts = 0;
    workout_t workouts[MAX_WORKOUTS];

    while (1) {
        printf("Enter 1 to start a workout, 2 to view history, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            if (num_workouts >= MAX_WORKOUTS) {
                printf("Sorry, you have reached the maximum number of workouts.\n");
            } else {
                printf("Enter workout name: ");
                scanf("%s", workouts[num_workouts].name);
                printf("Enter workout duration (in seconds): ");
                scanf("%d", &workouts[num_workouts].duration);
                time(&workouts[num_workouts].start_time);
                num_workouts++;
            }
        } else if (choice == 2) {
            if (num_workouts == 0) {
                printf("No workouts to display.\n");
            } else {
                printf("Workout history:\n");
                for (int i = 0; i < num_workouts; i++) {
                    printf("%s: %d seconds\n", workouts[i].name, workouts[i].duration);
                    printf("Start time: %s\n", ctime(&workouts[i].start_time));
                    printf("\n");
                }
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}