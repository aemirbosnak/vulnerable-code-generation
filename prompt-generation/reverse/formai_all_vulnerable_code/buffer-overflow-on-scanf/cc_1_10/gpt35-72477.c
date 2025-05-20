//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of exercises the user can enter
#define MAX_EXERCISES 10

// Structure to store information about each exercise
struct Exercise {
    char name[20];
    int sets;
    int reps;
};

// Function to prompt user for input and store Exercise information
void addExercise(struct Exercise* e) {
    printf("Enter Exercise Name (20 char max): ");
    scanf("%s", e->name);

    printf("Enter Number of Sets: ");
    scanf("%d", &e->sets);

    printf("Enter Number of Reps: ");
    scanf("%d", &e->reps);
}

// Function to print information about each exercise in the list
void printExercises(struct Exercise* exercises, int numExercises) {
    printf("\nExercise List:\n");
    for (int i = 0; i < numExercises; i++) {
        printf("%d. %s - %d sets x %d reps\n", i+1, exercises[i].name, exercises[i].sets, exercises[i].reps);
    }
}

int main() {
    struct Exercise exercises[MAX_EXERCISES];
    int numExercises = 0;
    char choice;

    // Loop to allow user to add multiple exercises until the maximum is reached
    while(numExercises < MAX_EXERCISES) {
        addExercise(&exercises[numExercises]);
        numExercises++;

        // Prompt user to continue adding exercises or exit
        printf("\nDo you want to add another exercise? (y/n): ");
        scanf(" %c", &choice);
        if(choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Print the full exercise list
    printExercises(exercises, numExercises);

    return 0;
}