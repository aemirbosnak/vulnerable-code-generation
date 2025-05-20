//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_SETS 100
#define MAX_REPS 100
#define MAX_DURATION 60 * 60 * 24 // 1 day

typedef struct {
    char name[50];
    int sets;
    int reps;
} Exercise;

typedef struct {
    char name[50];
    int duration;
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    num_workouts++;
    workouts[num_workouts - 1].num_exercises = 0;
}

void add_exercise(Workout *workout) {
    char input[100];
    printf("Enter exercise name: ");
    scanf("%s", input);
    strcpy(workout->exercises[workout->num_exercises].name, input);
    printf("Enter sets: ");
    scanf("%d", &workout->exercises[workout->num_exercises].sets);
    printf("Enter reps: ");
    scanf("%d", &workout->exercises[workout->num_exercises].reps);
    workout->num_exercises++;
}

void view_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\n", workouts[i].name);
    }
}

void view_exercises(Workout *workout) {
    printf("Exercises:\n");
    for (int i = 0; i < workout->num_exercises; i++) {
        printf("%s - Sets: %d, Reps: %d\n", workout->exercises[i].name, workout->exercises[i].sets, workout->exercises[i].reps);
    }
}

int main() {
    srand(time(NULL));
    add_workout();
    view_workouts();

    int choice;
    do {
        printf("\nChoose an option:\n1. Add workout\n2. View workouts\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_workout();
            view_workouts();
            break;
        case 2:
            view_workouts();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}