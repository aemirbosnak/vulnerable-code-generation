//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of exercises and the length of the exercise name
#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 20

// Define a struct for an exercise
struct Exercise {
    char name[MAX_NAME_LENGTH];
    int reps;
    int sets;
};

// Define a function to add an exercise to the tracker
int addExercise(struct Exercise *tracker, int numExercises)
{
    // Check if the tracker is full
    if (numExercises >= MAX_EXERCISES) {
        printf("The tracker is full! No new exercises can be added.\n");
        return numExercises;
    }

    // Ask for the name, reps, and sets of the exercise
    printf("What exercise would you like to add?\n");
    scanf("%s", tracker[numExercises].name);
    printf("How many reps did you do?\n");
    scanf("%d", &tracker[numExercises].reps);
    printf("How many sets did you do?\n");
    scanf("%d", &tracker[numExercises].sets);

    // Increment the number of exercises in the tracker and return the new value
    printf("You have added %s to the tracker.\n", tracker[numExercises].name);
    return numExercises + 1;
}

// Define a function to display the exercises in the tracker
void displayExercises(struct Exercise *tracker, int numExercises)
{
    // Check if the tracker is empty
    if (numExercises == 0) {
        printf("The tracker is empty! No exercises to display.\n");
        return;
    }

    // Print the header of the table
    printf("Exercise\tReps\tSets\n");

    // Loop through each exercise and print its name, reps, and sets
    for (int i = 0; i < numExercises; i++) {
        printf("%s\t\t%d\t%d\n", tracker[i].name, tracker[i].reps, tracker[i].sets);
    }
}

int main()
{
    printf("Welcome to the C Fitness Tracker.\n");
    printf("Please use the following options:\n\n");

    // Define the tracker and the number of exercises in it
    struct Exercise tracker[MAX_EXERCISES];
    int numExercises = 0;

    // Loop through the options until the user decides to quit
    while (1) {
        printf("\n1. Add an exercise to the tracker\n");
        printf("2. Display the exercises in the tracker\n");
        printf("3. Quit\n\n");

        // Ask for the user's choice
        int choice = 0;
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Add an exercise to the tracker
                numExercises = addExercise(tracker, numExercises);
                break;
            case 2:
                // Display the exercises in the tracker
                displayExercises(tracker, numExercises);
                break;
            case 3:
                // Quit the program
                printf("Thank you for using the C Fitness Tracker.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}