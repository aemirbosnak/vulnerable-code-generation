//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Exercise {
    char name[50];
    int duration;
    int caloriesBurned;
};

struct Exercise createExercise(char *name, int duration, int caloriesBurned) {
    struct Exercise exercise;
    strcpy(exercise.name, name);
    exercise.duration = duration;
    exercise.caloriesBurned = caloriesBurned;
    return exercise;
}

void printExercise(struct Exercise exercise) {
    printf("Name: %s\nDuration: %d seconds\nCalories burned: %d\n", exercise.name, exercise.duration, exercise.caloriesBurned);
}

int main() {
    int choice;
    struct Exercise *exercises = NULL;
    int numExercises = 0;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Add exercise\n2. View exercises\n3. Exit\n");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter the name of the exercise: ");
                char name[50];
                scanf("%s", name);
                printf("Enter the duration of the exercise in seconds: ");
                int duration;
                scanf("%d", &duration);
                printf("Enter the number of calories burned during the exercise: ");
                int caloriesBurned;
                scanf("%d", &caloriesBurned);
                exercises = realloc(exercises, sizeof(struct Exercise) * ++numExercises);
                exercises[numExercises - 1] = createExercise(name, duration, caloriesBurned);
                break;
            case 2:
                printf("Exercises:\n");
                for (int i = 0; i < numExercises; i++) {
                    printExercise(exercises[i]);
                }
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\nPlease choose an option:\n");
        printf("1. Add exercise\n2. View exercises\n3. Exit\n");
        scanf("%d", &choice);
    }

    free(exercises);
    return 0;
}