//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 20

struct Exercise {
    char name[MAX_NAME_LENGTH];
    int sets;
    int reps;
    float weight;
};

struct Workout {
    char date[11]; // format: MM/DD/YYYY
    int numExercises;
    struct Exercise exercises[MAX_EXERCISES];
};


void displayWorkout(struct Workout w) {
    printf("Workout for: %s\n", w.date);
    for(int i=0; i<w.numExercises; i++) {
        struct Exercise e = w.exercises[i];
        printf("%s: %d sets of %d reps with %0.2f lbs\n", e.name, e.sets, e.reps, e.weight);
    }
    printf("\n");
}

void addExerciseToWorkout(struct Workout *w) {
    if(w->numExercises >= MAX_EXERCISES) {
        printf("You have reached the maximum number of exercises for this workout.\n");
        return;
    }

    struct Exercise e;

    printf("Enter the name of the exercise: ");
    scanf("%s", &e.name);

    printf("Enter the number of sets: ");
    scanf("%d", &e.sets);

    printf("Enter the number of reps: ");
    scanf("%d", &e.reps);

    printf("Enter the weight (in lbs): ");
    scanf("%f", &e.weight);

    w->exercises[w->numExercises] = e;
    w->numExercises++;

    printf("%s has been added to the workout.\n", e.name);
}

int main() {
    struct Workout w;
    w.numExercises = 0;

    printf("Enter the workout date (MM/DD/YYYY): ");
    scanf("%s", &w.date);

    char choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Add exercise\n");
        printf("2. Display workout\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addExerciseToWorkout(&w);
                break;
            case '2':
                displayWorkout(w);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while(choice != '3');
    
    return 0;
}