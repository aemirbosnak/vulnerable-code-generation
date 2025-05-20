//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10
#define MAX_DURATION 1000 // in seconds
#define MAX_CALORIES 10000

typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

typedef struct {
    char name[50];
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

int main() {
    char choice;
    int num_workouts = 0;
    Workout workouts[MAX_WORKOUTS];

    do {
        printf("\n");
        printf("Welcome to the Fitness Tracker!\n");
        printf("Please choose an option:\n");
        printf("1. Create a new workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the name of the workout: ");
            scanf("%s", workouts[num_workouts].name);
            printf("Enter the number of exercises: ");
            scanf("%d", &workouts[num_workouts].num_exercises);

            for (int i = 0; i < workouts[num_workouts].num_exercises; i++) {
                printf("Enter the name of exercise %d: ", i + 1);
                scanf("%s", workouts[num_workouts].exercises[i].name);
                printf("Enter the duration of exercise %d (in seconds): ", i + 1);
                scanf("%d", &workouts[num_workouts].exercises[i].duration);
                printf("Enter the calories burned during exercise %d: ", i + 1);
                scanf("%d", &workouts[num_workouts].exercises[i].calories);
            }

            num_workouts++;
            printf("Workout created successfully!\n");
            break;

        case '2':
            printf("Workout Name\t\tDuration\tCalories\n");

            for (int i = 0; i < num_workouts; i++) {
                printf("%s\t\t", workouts[i].name);

                for (int j = 0; j < workouts[i].num_exercises; j++) {
                    printf("%d secs\t%d cals\t", workouts[i].exercises[j].duration, workouts[i].exercises[j].calories);
                }

                printf("\n");
            }

            break;

        case '3':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '3');

    return 0;
}