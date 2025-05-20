//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10

struct workout {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
};

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    char choice;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter's' to start a workout, 'e' to end a workout, 'l' to list workouts, or 'q' to quit:\n");

    while (choice!= 'q') {
        scanf("%c", &choice);

        switch (choice) {
            case's':
                if (num_workouts >= MAX_WORKOUTS) {
                    printf("Maximum number of workouts reached. Please end a workout first.\n");
                } else {
                    printf("Enter workout name: ");
                    scanf("%s", workouts[num_workouts].name);
                    workouts[num_workouts].start_time = time(NULL);
                    num_workouts++;
                }
                break;

            case 'e':
                if (num_workouts == 0) {
                    printf("No workout in progress.\n");
                } else {
                    workouts[num_workouts - 1].end_time = time(NULL);
                    workouts[num_workouts - 1].duration = difftime(workouts[num_workouts - 1].end_time, workouts[num_workouts - 1].start_time);
                }
                break;

            case 'l':
                printf("List of workouts:\n");
                for (int i = 0; i < num_workouts; i++) {
                    printf("%s - Duration: %d seconds\n", workouts[i].name, workouts[i].duration);
                }
                break;

            case 'q':
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}