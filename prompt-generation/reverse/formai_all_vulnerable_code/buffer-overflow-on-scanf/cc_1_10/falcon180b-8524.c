//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 10000

typedef struct {
    char name[50];
    int steps;
    int distance;
    int calories;
} Workout;

int main() {
    int choice;
    char input[100];
    char name[50];
    int steps = 0;
    int distance = 0;
    int calories = 0;
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    printf("Welcome to the Fitness Tracker 3000!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Start workout\n");
        printf("2. End workout\n");
        printf("3. View workout history\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Starting workout...\n");
            printf("Enter workout name:\n");
            scanf("%s", input);
            strcpy(workouts[num_workouts].name, input);
            num_workouts++;
            break;
        case 2:
            printf("Ending workout...\n");
            printf("Enter workout name:\n");
            scanf("%s", input);
            for (int i = 0; i < num_workouts; i++) {
                if (strcmp(workouts[i].name, input) == 0) {
                    printf("Workout ended: %s\n", workouts[i].name);
                    workouts[i].steps = steps;
                    workouts[i].distance = distance;
                    workouts[i].calories = calories;
                    break;
                }
            }
            break;
        case 3:
            printf("Workout history:\n");
            for (int i = 0; i < num_workouts; i++) {
                printf("%s: %d steps, %d distance, %d calories\n", workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
            }
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}