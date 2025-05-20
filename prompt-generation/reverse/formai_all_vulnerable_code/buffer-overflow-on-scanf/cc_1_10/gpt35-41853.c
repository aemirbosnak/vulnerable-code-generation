//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to hold workout data
typedef struct {
    char exerciseName[50];
    int reps;
    int sets;
    float weight;
} Workout;

// Function to display menu options
void displayMenu() {
    printf("\n");
    printf("1. Log a new workout\n");
    printf("2. View past workouts\n");
    printf("3. Quit\n\n");
}

int main() {
    int choice = 0, count = 0;
    Workout workouts[1000];

    printf("Hey there! Welcome to our Fitness Tracker program. I am here to help you to stay fit and healthy!\n");

    while (choice != 3) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choices
        switch (choice) {
            case 1: {
                // Log a new workout
                char exerciseName[50];
                int reps, sets;
                float weight;

                printf("\nEnter the name of the exercise: ");
                scanf("%s", exerciseName);
                printf("Enter the number of reps: ");
                scanf("%d", &reps);
                printf("Enter the number of sets: ");
                scanf("%d", &sets);
                printf("Enter the weight used: ");
                scanf("%f", &weight);

                // Add new workout to array
                Workout newWorkout;
                strcpy(newWorkout.exerciseName, exerciseName);
                newWorkout.reps = reps;
                newWorkout.sets = sets;
                newWorkout.weight = weight;

                workouts[count] = newWorkout;
                count++;

                printf("\nWorkout successfully logged!\n");
                break;
            }

            case 2: {
                // Display past workouts
                if (count == 0) {
                    printf("\nNo workouts to display. Please log a workout first!\n");
                }
                else {
                    printf("\nYour past workouts are:\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s: %d reps x %d sets with %.1f kg\n", i + 1, workouts[i].exerciseName,
                               workouts[i].reps, workouts[i].sets, workouts[i].weight);
                    }
                }
                break;
            }

            case 3: {
                // Quit program
                printf("\nGoodbye! Keep working out to get that perfect body you deserve.\n");
                break;
            }

            default: {
                printf("\nInvalid input. Please enter a valid choice.\n");
                break;
            }
        }
    }

    return 0;
}