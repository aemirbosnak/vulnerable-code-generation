//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Constants
#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 200

//Structures
struct Exercise {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int sets;
    int reps;
    float weight;
};

struct Workout {
    char name[MAX_NAME_LENGTH];
    int numExercises;
    struct Exercise exercises[MAX_EXERCISES];
    float totalCaloriesBurned;
};

//Function prototypes
void addExercise(struct Exercise *newExercise);
float calculateCaloriesBurned(struct Exercise exercise);
void addWorkout(struct Workout *newWorkout);
void displayWorkoutSummary(struct Workout workout);

//Global variables
struct Workout workouts[MAX_EXERCISES];
int numWorkouts = 0;

int main() {
    int userChoice = 0;

    do {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Add workout\n");
        printf("2. View workout summary\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                printf("\nAdd New Workout:\n");
                struct Workout newWorkout;
                addWorkout(&newWorkout);
                workouts[numWorkouts] = newWorkout;
                numWorkouts++;
                printf("\nNew workout added successfully!\n");
                break;

            case 2:
                if (numWorkouts == 0) {
                    printf("\nNo workouts to display. Add a workout first!\n");
                }
                else {
                    printf("\nView Workout Summary:\n");
                    for (int i = 0; i < numWorkouts; i++) {
                        printf("\nWorkout #%d\n", i+1);
                        displayWorkoutSummary(workouts[i]);
                    }
                }
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
                break;
        }

    } while (userChoice != 3);

    return 0;
}

//Function to add a new exercise to a workout
void addExercise(struct Exercise *newExercise) {
    printf("\nEnter Exercise Details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", newExercise->name);
    printf("Description: ");
    scanf(" %[^\n]s", newExercise->description);
    printf("Sets: ");
    scanf("%d", &newExercise->sets);
    printf("Reps: ");
    scanf("%d", &newExercise->reps);
    printf("Weight (in pounds): ");
    scanf("%f", &newExercise->weight);
}

//Function to calculate calories burned for an exercise
float calculateCaloriesBurned(struct Exercise exercise) {
    //Formula to calculate calories burned per set: 0.0175 x weight x reps
    float caloriesPerSet = 0.0175 * exercise.weight * exercise.reps;
    return caloriesPerSet * exercise.sets;
}

//Function to add a new workout
void addWorkout(struct Workout *newWorkout) {
    printf("Name of workout: ");
    scanf(" %[^\n]s", newWorkout->name);
    printf("How many exercises will you do? (Maximum 10): ");
    scanf("%d", &newWorkout->numExercises);

    //Add exercises to the workout
    for (int i = 0; i < newWorkout->numExercises; i++) {
        printf("\nExercise #%d:\n", i+1);
        struct Exercise newExercise;
        addExercise(&newExercise);
        newWorkout->exercises[i] = newExercise;
        newWorkout->totalCaloriesBurned += calculateCaloriesBurned(newExercise);
        printf("\nCalories burned for this exercise: %.2f\n", calculateCaloriesBurned(newExercise));
    }
}

//Function to display summary of a workout
void displayWorkoutSummary(struct Workout workout) {
    printf("Name of workout: %s\n", workout.name);
    printf("Total exercises done: %d\n", workout.numExercises);

    //Display exercises and calories burned for each exercise
    for (int i = 0; i < workout.numExercises; i++) {
        printf("\nExercise #%d: %s\n", i+1, workout.exercises[i].name);
        printf("Description: %s\n", workout.exercises[i].description);
        printf("Sets: %d\n", workout.exercises[i].sets);
        printf("Reps: %d\n", workout.exercises[i].reps);
        printf("Weight (in pounds): %.2f\n", workout.exercises[i].weight);
        printf("Calories burned: %.2f\n", calculateCaloriesBurned(workout.exercises[i]));
    }

    printf("\nTotal calories burned in this workout: %.2f\n", workout.totalCaloriesBurned);
}