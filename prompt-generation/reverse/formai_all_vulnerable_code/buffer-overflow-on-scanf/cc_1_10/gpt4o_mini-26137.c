//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned per minute
} Workout;

void addWorkout(Workout workouts[], int *workoutCount);
void displayWorkouts(Workout workouts[], int workoutCount);
void displayStatistics(Workout workouts[], int workoutCount);
int calculateTotalCalories(Workout workouts[], int workoutCount);

int main() {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount = 0;
    int choice;

    printf("Welcome to the Curious C Fitness Tracker!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a Workout\n");
        printf("2. Display Workouts\n");
        printf("3. Display Statistics\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(workouts, &workoutCount);
                break;
            case 2:
                displayWorkouts(workouts, workoutCount);
                break;
            case 3:
                displayStatistics(workouts, workoutCount);
                break;
            case 4:
                printf("Thank you for using the Curious C Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addWorkout(Workout workouts[], int *workoutCount) {
    if (*workoutCount >= MAX_WORKOUTS) {
        printf("Oh no! You've reached the maximum number of workouts. Can't add more.\n");
        return;
    }
    
    printf("What workout are you adding? (e.g., Running, Cycling): ");
    scanf(" %[^\n]", workouts[*workoutCount].name); // Take input with spaces
    printf("How long (in minutes) did you do this workout? ");
    scanf("%d", &workouts[*workoutCount].duration);
    printf("What is the estimated calories burned per minute for this workout? ");
    scanf("%d", &workouts[*workoutCount].calories);

    (*workoutCount)++;
    printf("Your workout has been added! Keep up the good work!\n");
}

void displayWorkouts(Workout workouts[], int workoutCount) {
    if (workoutCount == 0) {
        printf("Oh dear! You haven't logged any workouts yet. Let's get moving!\n");
        return;
    }

    printf("\nHere are your logged workouts:\n");
    for (int i = 0; i < workoutCount; i++) {
        printf("%d. %s - Duration: %d minutes, Calories/min: %d\n", 
               i + 1, workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void displayStatistics(Workout workouts[], int workoutCount) {
    if (workoutCount == 0) {
        printf("No workouts logged yet! You can start working out at any time!\n");
        return;
    }

    int totalCalories = calculateTotalCalories(workouts, workoutCount);
    printf("You've logged %d workouts.\n", workoutCount);
    printf("Total calories burned: %d calories. Keep pushing those limits!\n", totalCalories);
}

int calculateTotalCalories(Workout workouts[], int workoutCount) {
    int totalCalories = 0;
    for (int i = 0; i < workoutCount; i++) {
        totalCalories += workouts[i].duration * workouts[i].calories;
    }
    return totalCalories;
}