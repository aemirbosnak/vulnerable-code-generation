//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_WORKOUTS 50
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    int calories;
    int workouts;
} User;

typedef struct {
    char activity[NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned; // calories burned in this workout
} Workout;

User users[MAX_USERS];
Workout workouts[MAX_WORKOUTS];

int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Can't add more users.\n");
        return;
    }
    
    printf("Enter the name of the user: ");
    scanf("%s", users[userCount].name);
    users[userCount].steps = 0;
    users[userCount].calories = 0;
    users[userCount].workouts = 0;
    
    printf("User %s added successfully.\n", users[userCount].name);
    userCount++;
}

void addWorkout(int userIndex) {
    if (users[userIndex].workouts >= MAX_WORKOUTS) {
        printf("Workout limit reached for user %s.\n", users[userIndex].name);
        return;
    }
    
    Workout newWorkout;
    printf("Enter activity name: ");
    scanf("%s", newWorkout.activity);
    
    printf("Enter duration in minutes: ");
    scanf("%d", &newWorkout.duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.caloriesBurned);
    
    workouts[users[userIndex].workouts++] = newWorkout;
    users[userIndex].calories += newWorkout.caloriesBurned;
    
    printf("Workout added for user %s.\n", users[userIndex].name);
}

void viewUserData(int userIndex) {
    printf("\nUser: %s\n", users[userIndex].name);
    printf("Steps today: %d\n", users[userIndex].steps);
    printf("Total calories burned: %d\n", users[userIndex].calories);
    printf("Workouts:\n");
    
    for (int i = 0; i < users[userIndex].workouts; i++) {
        printf("  %d. %s - Duration: %d min, Calories Burned: %d\n",
               i + 1, workouts[i].activity,
               workouts[i].duration, workouts[i].caloriesBurned);
    }
}

void updateSteps(int userIndex) {
    int steps;
    printf("Enter number of steps taken today: ");
    scanf("%d", &steps);
    users[userIndex].steps += steps;
}

int main() {
    int choice, userIndex;
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Add Workout\n");
        printf("3. View User Data\n");
        printf("4. Update Steps\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                if (userIndex >= 0 && userIndex < userCount) {
                    addWorkout(userIndex);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 3:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                if (userIndex >= 0 && userIndex < userCount) {
                    viewUserData(userIndex);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 4:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                if (userIndex >= 0 && userIndex < userCount) {
                    updateSteps(userIndex);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}