//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of exercises and sets
#define MAX_EXERCISES 10
#define MAX_SETS 5

// Define the structure for an exercise
typedef struct {
    char name[50];
    int reps;
    int sets;
    int calories;
} Exercise;

// Function to calculate calories burned based on exercise type and duration
int calculateCalories(char exerciseType[], int duration) {
    int caloriesBurned = 0;

    if (strcmp(exerciseType, "Running") == 0) {
        caloriesBurned = duration * 10;
    } else if (strcmp(exerciseType, "Cycling") == 0) {
        caloriesBurned = duration * 8;
    } else if (strcmp(exerciseType, "Swimming") == 0) {
        caloriesBurned = duration * 12;
    } else if (strcmp(exerciseType, "Weightlifting") == 0) {
        caloriesBurned = duration * 6;
    }

    return caloriesBurned;
}

// Function to print the total calories burned for a specific exercise
void printTotalCalories(Exercise exercise, int totalCalories) {
    printf("\nTotal calories burned for %s: %d\n", exercise.name, totalCalories);
}

int main() {
    // Initialize variables
    int i, j;
    char exerciseType[50];
    Exercise exercises[MAX_EXERCISES];

    // Prompt the user to enter the date
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", exercises[0].name);

    // Prompt the user to enter the exercises
    for (i = 0; i < MAX_EXERCISES; i++) {
        printf("Enter exercise %d: ", i + 1);
        scanf("%s", exercises[i].name);

        // Prompt the user to enter the number of reps and sets for each exercise
        printf("Enter the number of reps: ");
        scanf("%d", &exercises[i].reps);

        printf("Enter the number of sets: ");
        scanf("%d", &exercises[i].sets);

        // Calculate the calories burned for each exercise
        exercises[i].calories = calculateCalories(exercises[i].name, exercises[i].reps * exercises[i].sets);
    }

    // Print the total calories burned for each exercise
    for (i = 0; i < MAX_EXERCISES; i++) {
        printTotalCalories(exercises[i], exercises[i].calories);
    }

    return 0;
}