//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struct to hold exercise information
struct Exercise {
    char name[20];
    float calories;
    float duration;
};

// Function to add a new exercise to the tracker
void addExercise(struct Exercise exercises[], int *numExercises) {
    char name[20];
    float calories, duration;
    printf("Enter exercise name: ");
    scanf("%s", name);
    printf("Enter calories burned: ");
    scanf("%f", &calories);
    printf("Enter duration (in minutes): ");
    scanf("%f", &duration);
    struct Exercise exercise = {name, calories, duration};
    exercises[*numExercises] = exercise;
    *numExercises += 1;
    printf("Exercise added successfully.\n");
}

// Function to display all exercises in the tracker
void displayExercises(struct Exercise exercises[], int numExercises) {
    printf("Exercise\tCalories Burned\tDuration (minutes)\n");
    for (int i = 0; i < numExercises; i++) {
        struct Exercise exercise = exercises[i];
        printf("%s\t%.2f\t\t%.2f\n", exercise.name, exercise.calories, exercise.duration);
    }
}

// Main function
int main() {
    int numExercises = 0;
    struct Exercise exercises[100];
    char option[2];
    do {
        printf("Fitness Tracker\n");
        printf("1. Add Exercise\n");
        printf("2. Display Exercises\n");
        printf("Enter option (1 or 2): ");
        scanf("%s", option);
        if (strcmp(option, "1") == 0) {
            addExercise(exercises, &numExercises);
        } else if (strcmp(option, "2") == 0) {
            displayExercises(exercises, numExercises);
        } else {
            printf("Invalid option.\n");
        }
        printf("Continue? (y/n): ");
        scanf("%s", option);
    } while (strcmp(option, "n") != 0);
    return 0;
}