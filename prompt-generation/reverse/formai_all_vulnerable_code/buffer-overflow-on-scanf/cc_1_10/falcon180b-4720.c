//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_TIME 60

struct workout {
    char name[50];
    int duration;
};

void print_workout(struct workout w) {
    printf("Name: %s\nDuration: %d minutes\n\n", w.name, w.duration);
}

void add_workout(struct workout workouts[], int num_workouts, char name[], int duration) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    num_workouts++;
}

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    char input[100];
    int choice, duration;

    srand(time(NULL));

    printf("Welcome to the Post-Apocalyptic Fitness Tracker!\n\n");

    while (1) {
        printf("1. Add workout\n2. View workouts\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter workout name: ");
                scanf("%s", input);
                printf("Enter workout duration (in minutes): ");
                scanf("%d", &duration);

                if (duration > MAX_TIME) {
                    printf("Error: Workout duration must be %d minutes or less.\n", MAX_TIME);
                } else {
                    add_workout(workouts, num_workouts, input, duration);
                }
                break;

            case 2:
                printf("Workouts:\n");
                for (int i = 0; i < num_workouts; i++) {
                    print_workout(workouts[i]);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}