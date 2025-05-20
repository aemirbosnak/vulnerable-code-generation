//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
/*
C Fitness Tracker Example Program
This program tracks a user's fitness goals and progress.
It allows users to log their daily exercise routines and view their progress towards their goals.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for max number of exercises and max exercise name length
#define MAX_EXERCISES 10
#define MAX_EXERCISE_NAME_LENGTH 20

// Declare structures for exercise and user
typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH]; // Name of exercise
    int sets; // Number of sets
    int reps; // Number of reps per set
    float weight; // Weight lifted
} Exercise;

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH]; // Name of user
    Exercise exercises[MAX_EXERCISES]; // Array of exercises
    int numExercises; // Number of exercises logged
    float weightGoal; // User's weight goal
    float weightCurrent; // User's current weight
} User;

// Declare functions
void addExercise(User *user);
void printExercises(User *user);
float calculateProgress(User *user);

int main() {
    User user;
    char name[MAX_EXERCISE_NAME_LENGTH];
    int choice;
    
    // Prompt user to enter their name
    printf("Enter your name: ");
    scanf("%s", name);
    strcpy(user.name, name);
    
    // Initialize user's exercise count and weight as 0
    user.numExercises = 0;
    user.weightGoal = 0;
    user.weightCurrent = 0;
    
    // Display menu options until user quits
    while (1) {
        printf("\n==========MENU==========\n");
        printf("1. Add exercise\n");
        printf("2. View exercises\n");
        printf("3. View progress\n");
        printf("4. Quit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) { // Add exercise
            addExercise(&user);
        } else if (choice == 2) { // View exercises
            printExercises(&user);
        } else if (choice == 3) { // View progress
            printf("\n%s's progress is %.2f%%\n", user.name, calculateProgress(&user));
        } else if (choice == 4) { // Quit
            printf("\nThank you for using the C Fitness Tracker!");
            break;
        } else { // Invalid choice
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Function to add exercise to user's log
void addExercise(User *user) {
    if (user->numExercises < MAX_EXERCISES) { // Check if user has maxed out exercises
        Exercise exercise;
        char name[MAX_EXERCISE_NAME_LENGTH];
        
        // Prompt user to enter exercise details
        printf("\nEnter name of exercise: ");
        scanf("%s", name);
        strcpy(exercise.name, name);
        
        printf("Enter number of sets: ");
        scanf("%d", &exercise.sets);
        
        printf("Enter number of reps per set: ");
        scanf("%d", &exercise.reps);
        
        printf("Enter weight lifted: ");
        scanf("%f", &exercise.weight);
        
        // Add exercise to user's log
        user->exercises[user->numExercises] = exercise;
        user->numExercises++;
        
        printf("\nExercise added successfully!\n");
    } else { // If user has maxed out exercises
        printf("\nYou have reached the maximum number of exercises.\n");
    }
}

// Function to print exercises logged by user
void printExercises(User *user) {
    printf("\n%s's exercise log:\n", user->name);
    for (int i=0; i<user->numExercises; i++) {
        printf("%s: %d sets x %d reps @ %.2f lbs\n", user->exercises[i].name, user->exercises[i].sets,
        user->exercises[i].reps, user->exercises[i].weight);
    }
}

// Function to calculate user's progress
float calculateProgress(User *user) {
    float weightDiff = user->weightCurrent - user->weightGoal;
    float weightPercent = ((user->weightCurrent - weightDiff) / user->weightGoal) * 100;
    float exercisePercent = user->numExercises / (float)MAX_EXERCISES * 100;
    float totalPercent = (weightPercent + exercisePercent) / 2;
    return totalPercent;
}