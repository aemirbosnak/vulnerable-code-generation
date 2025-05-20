//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_EXERCISES 100

// Struct to hold exercise information
typedef struct {
    char name[MAX_LENGTH];
    int duration;
    int calories;
} Exercise;

// Function to prompt user for exercise information
void getExercise(Exercise* exercise) {
    printf("Enter exercise name: ");
    scanf("%s", exercise->name);

    printf("Enter exercise duration in minutes: ");
    scanf("%d", &exercise->duration);

    printf("Enter exercise calories burned: ");
    scanf("%d", &exercise->calories);
}

// Function to print exercise information
void printExercise(Exercise exercise) {
    printf("Name: %s\n", exercise.name);
    printf("Duration: %d minutes\n", exercise.duration);
    printf("Calories burned: %d\n", exercise.calories);
}

// Function to prompt user for workout information
void getWorkout(int* numExercises, Exercise exercises[]) {
    printf("Enter number of exercises in workout: ");
    scanf("%d", numExercises);

    for (int i = 0; i < *numExercises; i++) {
        getExercise(&exercises[i]);
    }
}

// Function to calculate total workout time and calories burned
void calculateWorkout(int numExercises, Exercise exercises[], int* totalTime, int* totalCalories) {
    *totalTime = 0;
    *totalCalories = 0;

    for (int i = 0; i < numExercises; i++) {
        *totalTime += exercises[i].duration;
        *totalCalories += exercises[i].calories;
    }
}

// Function to print workout information
void printWorkout(int numExercises, Exercise exercises[]) {
    printf("Total workout time: %d minutes\n", numExercises * 5);
    printf("Total calories burned: %d\n", numExercises * 5 * 100);

    for (int i = 0; i < numExercises; i++) {
        printExercise(exercises[i]);
    }
}

// Main function
int main() {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];

    getWorkout(&numExercises, exercises);
    calculateWorkout(numExercises, exercises, &numExercises, &numExercises);
    printWorkout(numExercises, exercises);

    return 0;
}