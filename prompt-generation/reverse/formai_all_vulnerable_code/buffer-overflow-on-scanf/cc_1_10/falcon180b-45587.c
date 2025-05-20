//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of exercises that can be tracked
#define MAX_EXERCISES 10

// Define the structure for an exercise
typedef struct {
    char name[50];
    int sets;
    int reps;
    int weight;
} Exercise;

// Declare an array of exercises
Exercise exercises[MAX_EXERCISES];

// Declare a function to add an exercise
void addExercise(Exercise* exercise) {
    int i = 0;

    // Loop through the array of exercises to find an empty slot
    while (i < MAX_EXERCISES && exercises[i].name[0]!= '\0') {
        i++;
    }

    // Copy the exercise data into the empty slot
    strcpy(exercises[i].name, exercise->name);
    exercises[i].sets = exercise->sets;
    exercises[i].reps = exercise->reps;
    exercises[i].weight = exercise->weight;
}

// Declare a function to display all exercises
void displayExercises() {
    int i = 0;

    // Loop through the array of exercises and print each one
    while (i < MAX_EXERCISES && exercises[i].name[0]!= '\0') {
        printf("Exercise %d:\n", i+1);
        printf("Name: %s\n", exercises[i].name);
        printf("Sets: %d\n", exercises[i].sets);
        printf("Reps: %d\n", exercises[i].reps);
        printf("Weight: %d lbs\n\n", exercises[i].weight);
        i++;
    }
}

// Declare a function to calculate the total weight lifted for a given exercise
int calculateTotalWeight(Exercise exercise) {
    return exercise.sets * exercise.reps * exercise.weight;
}

// Declare a function to calculate the total weight lifted for all exercises
int calculateTotalWeightAll() {
    int totalWeight = 0;
    int i = 0;

    // Loop through the array of exercises and add up the total weight for each one
    while (i < MAX_EXERCISES && exercises[i].name[0]!= '\0') {
        totalWeight += calculateTotalWeight(exercises[i]);
        i++;
    }

    return totalWeight;
}

int main() {
    int choice;
    Exercise exercise;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add Exercise\n");
        printf("2. Display Exercises\n");
        printf("3. Calculate Total Weight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter exercise name: ");
                scanf("%s", exercise.name);
                printf("Enter sets: ");
                scanf("%d", &exercise.sets);
                printf("Enter reps: ");
                scanf("%d", &exercise.reps);
                printf("Enter weight: ");
                scanf("%d", &exercise.weight);
                addExercise(&exercise);
                break;
            case 2:
                displayExercises();
                break;
            case 3:
                printf("Total weight lifted: %d lbs\n", calculateTotalWeightAll());
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}