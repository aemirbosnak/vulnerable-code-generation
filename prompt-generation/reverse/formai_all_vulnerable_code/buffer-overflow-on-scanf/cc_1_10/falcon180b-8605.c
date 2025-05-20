//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_DURATION 1000

typedef struct {
    char name[50];
    int duration;
} workout;

typedef struct {
    char name[50];
    int calories;
} exercise;

workout workouts[MAX_WORKOUTS];
exercise exercises[MAX_EXERCISES];

int num_workouts = 0;
int num_exercises = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Max number of workouts reached.\n");
        return;
    }
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[num_workouts].duration);
    num_workouts++;
}

void add_exercise() {
    if (num_exercises >= MAX_EXERCISES) {
        printf("Max number of exercises reached.\n");
        return;
    }
    printf("Enter exercise name: ");
    scanf("%s", exercises[num_exercises].name);
    printf("Enter exercise calories burned: ");
    scanf("%d", &exercises[num_exercises].calories);
    num_exercises++;
}

void view_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d seconds\n", workouts[i].name, workouts[i].duration);
    }
}

void view_exercises() {
    printf("Exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s - %d calories\n", exercises[i].name, exercises[i].calories);
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
                add_workout();
                break;
            case 2:
                add_exercise();
                break;
            case 3:
                view_workouts();
                break;
            case 4:
                view_exercises();
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