//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 50
#define MAX_REPS 100
#define MAX_DISTANCE 1000
#define MAX_TIME 3600

typedef struct {
    char name[50];
    int duration;
    int distance;
    int calories;
} Workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
    int weight;
} Exercise;

Workout workouts[MAX_WORKOUTS];
Exercise exercises[MAX_EXERCISES];

int num_workouts = 0;
int num_exercises = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[num_workouts].duration);
    printf("Enter workout distance (in meters): ");
    scanf("%d", &workouts[num_workouts].distance);
    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);
    num_workouts++;
}

void add_exercise() {
    printf("Enter exercise name: ");
    scanf("%s", exercises[num_exercises].name);
    printf("Enter number of reps: ");
    scanf("%d", &exercises[num_exercises].reps);
    printf("Enter number of sets: ");
    scanf("%d", &exercises[num_exercises].sets);
    printf("Enter weight (in kg): ");
    scanf("%d", &exercises[num_exercises].weight);
    num_exercises++;
}

void view_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\n", workouts[i].name);
    }
}

void view_exercises() {
    printf("Exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s\n", exercises[i].name);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Add exercise\n");
        printf("3. View workouts\n");
        printf("4. View exercises\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}