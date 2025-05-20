//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_WORKOUTS 50

typedef struct {
    char name[30];
    int age;
    float weight; // in kg
    float height; // in meters
    int workoutCount; // number of workouts logged
    float workouts[MAX_WORKOUTS]; // array to hold workout durations in minutes
} User;

typedef struct {
    User users[MAX_USERS];
    int userCount;
} FitnessTracker;

void addUser(FitnessTracker* tracker) {
    if (tracker->userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    
    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter weight (kg): ");
    scanf("%f", &newUser.weight);
    printf("Enter height (m): ");
    scanf("%f", &newUser.height);

    newUser.workoutCount = 0;
    tracker->users[tracker->userCount++] = newUser;

    printf("User %s added successfully!\n", newUser.name);
}

void logWorkout(FitnessTracker* tracker) {
    int userIndex;
    printf("Select user index (0 to %d): ", tracker->userCount - 1);
    scanf("%d", &userIndex);

    if (userIndex < 0 || userIndex >= tracker->userCount) {
        printf("Invalid user index.\n");
        return;
    }

    User* user = &tracker->users[userIndex];
    if (user->workoutCount >= MAX_WORKOUTS) {
        printf("Workout limit reached for user %s.\n", user->name);
        return;
    }

    float workoutDuration;
    printf("Enter workout duration (in minutes): ");
    scanf("%f", &workoutDuration);
    
    user->workouts[user->workoutCount++] = workoutDuration;
    printf("Logged %.2f minutes of workout for user %s.\n", workoutDuration, user->name);
}

void displayUserData(const User* user) {
    printf("\nUser: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f m\n", user->height);
    printf("Workouts logged: %d\n", user->workoutCount);
    printf("Workout durations: ");
    
    for (int i = 0; i < user->workoutCount; i++) {
        printf("%.2f ", user->workouts[i]);
    }
    printf("\n");
}

void displayAllUsers(const FitnessTracker* tracker) {
    for (int i = 0; i < tracker->userCount; i++) {
        displayUserData(&tracker->users[i]);
    }
}

void calculateTotalWorkoutTime(const User* user) {
    float total = 0.0f;
    for (int i = 0; i < user->workoutCount; i++) {
        total += user->workouts[i];
    }
    printf("Total workout time for %s: %.2f minutes\n", user->name, total);
}

void calculateAverageWorkoutTime(const User* user) {
    if (user->workoutCount == 0) {
        printf("No workouts logged for %s.\n", user->name);
        return;
    }

    float total = 0.0f;
    for (int i = 0; i < user->workoutCount; i++) {
        total += user->workouts[i];
    }
    float average = total / user->workoutCount;
    printf("Average workout time for %s: %.2f minutes\n", user->name, average);
}

int main() {
    FitnessTracker tracker;
    tracker.userCount = 0;
    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Log Workout\n");
        printf("3. Display All Users\n");
        printf("4. Calculate Total Workout Time for User\n");
        printf("5. Calculate Average Workout Time for User\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(&tracker);
                break;
            case 2:
                logWorkout(&tracker);
                break;
            case 3:
                displayAllUsers(&tracker);
                break;
            case 4: {
                int userIndex;
                printf("Select user index (0 to %d): ", tracker.userCount - 1);
                scanf("%d", &userIndex);
                
                if (userIndex >= 0 && userIndex < tracker.userCount) {
                    calculateTotalWorkoutTime(&tracker.users[userIndex]);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            }
            case 5: {
                int userIndex;
                printf("Select user index (0 to %d): ", tracker.userCount - 1);
                scanf("%d", &userIndex);
                
                if (userIndex >= 0 && userIndex < tracker.userCount) {
                    calculateAverageWorkoutTime(&tracker.users[userIndex]);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            }
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}