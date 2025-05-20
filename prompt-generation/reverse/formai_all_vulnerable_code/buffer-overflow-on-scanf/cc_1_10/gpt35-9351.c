//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants
#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EXERCISES 10

// define struct for each exercise
struct Exercise {
    char name[MAX_NAME_LENGTH];
    int sets;
    int reps;
    int weight;
};

// define struct for each workout
struct Workout {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int numExercises;
    struct Exercise exercises[MAX_EXERCISES];
};

// initialize global variables
struct Workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

// function prototypes
void addWorkout();
void viewWorkout(int index);
void viewAllWorkouts();

int main() {
    int menuChoice = 0;
    while (menuChoice != 4) {
        // display menu options
        printf("Welcome to C Fitness Tracker!\n");
        printf("1. Add a workout\n");
        printf("2. View a workout\n");
        printf("3. View all workouts\n");
        printf("4. Quit\n");
        printf("Please enter a number: ");
        scanf("%d", &menuChoice);
        
        switch (menuChoice) {
            case 1:
                addWorkout();
                break;
            case 2:
                printf("Please enter the index of the workout you want to view: ");
                int index;
                scanf("%d", &index);
                viewWorkout(index);
                break;
            case 3:
                viewAllWorkouts();
                break;
            case 4:
                printf("Thanks for using C Fitness Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}

void addWorkout() {
    // create new workout and prompt user for details
    struct Workout newWorkout;
    printf("Enter workout name: ");
    scanf("%s", newWorkout.name);
    printf("Enter workout date (DD MM YYYY): ");
    scanf("%d %d %d", &newWorkout.day, &newWorkout.month, &newWorkout.year);
    printf("Enter number of exercises: ");
    scanf("%d", &newWorkout.numExercises);
    for (int i = 0; i < newWorkout.numExercises; i++) {
        printf("Exercise %d name: ", i+1);
        scanf("%s", newWorkout.exercises[i].name);
        printf("Enter number of sets: ");
        scanf("%d", &newWorkout.exercises[i].sets);
        printf("Enter number of reps: ");
        scanf("%d", &newWorkout.exercises[i].reps);
        printf("Enter weight (lbs): ");
        scanf("%d", &newWorkout.exercises[i].weight);
    }
    
    // add new workout to array and increment count
    workouts[numWorkouts++] = newWorkout;
    printf("\nNew workout added successfully!\n");
}

void viewWorkout(int index) {
    if (index >= 0 && index < numWorkouts) {
        // display workout details
        printf("\nWorkout %d - %s\n", index+1, workouts[index].name);
        printf("Date: %d/%d/%d\n", workouts[index].day, workouts[index].month, workouts[index].year);
        printf("Exercises:\n");
        for (int i = 0; i < workouts[index].numExercises; i++) {
            printf("%d. %s: %d sets x %d reps x %d lbs\n", i+1, workouts[index].exercises[i].name, workouts[index].exercises[i].sets, workouts[index].exercises[i].reps, workouts[index].exercises[i].weight);
        }
    } else {
        printf("\nInvalid workout index. Please try again.\n");
    }
}

void viewAllWorkouts() {
    if (numWorkouts == 0) {
        printf("\nNo workouts found.\n");
    } else {
        // display all workouts
        printf("\nAll Workouts:\n");
        for (int i = 0; i < numWorkouts; i++) {
            viewWorkout(i);
        }
    }
}