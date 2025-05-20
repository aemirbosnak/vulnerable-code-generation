//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_WORKOUTS 100
#define MAX_DATE_LENGTH 11

typedef struct {
    char date[MAX_DATE_LENGTH];
    int steps;
    float distance; // in kilometers
    int caloriesBurned;
} Workout;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot add more users.\n");
        return;
    }
    
    User newUser;
    printf("Enter your name: ");
    scanf("%s", newUser.name);
    newUser.workoutCount = 0;
    users[userCount++] = newUser;
    printf("User %s added successfully!\n", newUser.name);
}

void addWorkout(char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0) {
            if (users[i].workoutCount >= MAX_WORKOUTS) {
                printf("Workout limit reached for user %s!\n", username);
                return;
            }
            
            Workout newWorkout;
            printf("Enter workout date (YYYY-MM-DD): ");
            scanf("%s", newWorkout.date);
            printf("Enter steps: ");
            scanf("%d", &newWorkout.steps);
            printf("Enter distance in kilometers: ");
            scanf("%f", &newWorkout.distance);
            printf("Enter calories burned: ");
            scanf("%d", &newWorkout.caloriesBurned);
            
            users[i].workouts[users[i].workoutCount++] = newWorkout;
            printf("Workout added successfully for user %s!\n", username);
            return;
        }
    }
    printf("User %s not found!\n", username);
}

void viewWorkouts(char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0) {
            printf("Workouts for %s:\n", username);
            for (int j = 0; j < users[i].workoutCount; j++) {
                Workout w = users[i].workouts[j];
                printf("Date: %s, Steps: %d, Distance: %.2f km, Calories: %d\n", 
                        w.date, w.steps, w.distance, w.caloriesBurned);
            }
            return;
        }
    }
    printf("User %s not found!\n", username);
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. Add Workout\n");
    printf("3. View Workouts\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char username[MAX_NAME_LENGTH];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printf("Enter your name to add workout: ");
                scanf("%s", username);
                addWorkout(username);
                break;
            case 3:
                printf("Enter your name to view workouts: ");
                scanf("%s", username);
                viewWorkouts(username);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}