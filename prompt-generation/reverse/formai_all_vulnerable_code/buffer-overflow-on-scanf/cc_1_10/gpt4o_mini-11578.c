//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char exercise[NAME_LENGTH];
    float duration; // in minutes
    float caloriesBurned; // calories burned during the workout
} Workout;

typedef struct {
    int id;
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} User;

// Function prototypes
void logWorkout(User *user);
void viewWorkouts(const User *user);
void calculateTotalCalories(const User *user);
void displayMenu(User *user);

int main() {
    User user;
    user.id = 1; // For simplicity, user ID is hardcoded
    user.workoutCount = 0;

    displayMenu(&user);

    return 0;
}

void displayMenu(User *user) {
    int choice;

    do {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Log Workout\n");
        printf("2. View Workouts\n");
        printf("3. Calculate Total Calories Burned\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logWorkout(user);
                break;
            case 2:
                viewWorkouts(user);
                break;
            case 3:
                calculateTotalCalories(user);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 4);
}

void logWorkout(User *user) {
    if (user->workoutCount >= MAX_WORKOUTS) {
        printf("Workout log is full! Cannot log more workouts.\n");
        return;
    }

    Workout newWorkout;
    printf("Enter exercise name: ");
    scanf("%s", newWorkout.exercise);
    printf("Enter duration (in minutes): ");
    scanf("%f", &newWorkout.duration);
    
    // Simple model for calories burned (e.g., 5 calories per minute)
    newWorkout.caloriesBurned = newWorkout.duration * 5;

    user->workouts[user->workoutCount] = newWorkout;
    user->workoutCount++;

    printf("Workout logged successfully!\n");
}

void viewWorkouts(const User *user) {
    if (user->workoutCount == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("\n=== Workout History ===\n");
    for (int i = 0; i < user->workoutCount; i++) {
        printf("Workout %d: %s | Duration: %.2f minutes | Calories burned: %.2f\n",
               i + 1, user->workouts[i].exercise, user->workouts[i].duration,
               user->workouts[i].caloriesBurned);
    }
}

void calculateTotalCalories(const User *user) {
    float totalCalories = 0.0;

    for (int i = 0; i < user->workoutCount; i++) {
        totalCalories += user->workouts[i].caloriesBurned;
    }

    printf("Total calories burned from workouts: %.2f calories\n", totalCalories);
}