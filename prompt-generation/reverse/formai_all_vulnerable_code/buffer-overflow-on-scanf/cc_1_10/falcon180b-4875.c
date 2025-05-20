//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 50
#define MAX_EXERCISES 50

typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

Workout workouts[MAX_WORKOUTS];
Exercise exercises[MAX_EXERCISES];

void addWorkout() {
    int i;
    for (i = 0; i < MAX_WORKOUTS; i++) {
        if (workouts[i].name[0] == '\0') {
            printf("Enter workout name: ");
            scanf("%s", workouts[i].name);
            printf("Enter workout duration (in minutes): ");
            scanf("%d", &workouts[i].duration);
            printf("Enter workout calories burned: ");
            scanf("%d", &workouts[i].calories);
            return;
        }
    }
    printf("Max workouts reached.\n");
}

void addExercise() {
    int i;
    for (i = 0; i < MAX_EXERCISES; i++) {
        if (exercises[i].name[0] == '\0') {
            printf("Enter exercise name: ");
            scanf("%s", exercises[i].name);
            printf("Enter exercise duration (in minutes): ");
            scanf("%d", &exercises[i].duration);
            printf("Enter exercise calories burned: ");
            scanf("%d", &exercises[i].calories);
            return;
        }
    }
    printf("Max exercises reached.\n");
}

void viewWorkouts() {
    int i;
    for (i = 0; i < MAX_WORKOUTS; i++) {
        if (workouts[i].name[0]!= '\0') {
            printf("%s - %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
        }
    }
}

void viewExercises() {
    int i;
    for (i = 0; i < MAX_EXERCISES; i++) {
        if (exercises[i].name[0]!= '\0') {
            printf("%s - %d minutes - %d calories\n", exercises[i].name, exercises[i].duration, exercises[i].calories);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Add exercise\n");
        printf("3. View workouts\n");
        printf("4. View exercises\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                addExercise();
                break;
            case 3:
                viewWorkouts();
                break;
            case 4:
                viewExercises();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}