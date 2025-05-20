//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 30
#define MAX_WORKOUTS 50

typedef struct {
    char date[11];
    char workoutType[30];
    int duration; // in minutes
} Workout;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int weight; // in kg
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} User;

void displayWelcomeMessage() {
    printf("=========================================\n");
    printf("       Welcome to the Fitness Tracker!  \n");
    printf("=========================================\n");
    printf("   Let's make your fitness journey fun! \n");
}

int addUser(User *users, int *userCount) {
    if (*userCount >= MAX_USERS) {
        printf("User limit reached, cannot add more users.\n");
        return -1;
    }

    User newUser;
    printf("Enter your name: ");
    scanf("%s", newUser.name);
    printf("Enter your age: ");
    scanf("%d", &newUser.age);
    printf("Enter your weight (in kg): ");
    scanf("%d", &newUser.weight);
    newUser.workoutCount = 0;

    users[*userCount] = newUser;
    (*userCount)++;
    printf("Welcome, %s! You are now registered.\n", newUser.name);
    return 0;
}

void addWorkout(User *user) {
    if (user->workoutCount >= MAX_WORKOUTS) {
        printf("Workout limit reached, cannot add more workouts.\n");
        return;
    }

    Workout newWorkout;
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newWorkout.date);
    printf("Enter workout type: ");
    scanf("%s", newWorkout.workoutType);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &newWorkout.duration);
    
    user->workouts[user->workoutCount] = newWorkout;
    user->workoutCount++;
    
    printf("Great job, %s! You added a %s workout for %d minutes on %s!\n", user->name, newWorkout.workoutType, newWorkout.duration, newWorkout.date);
}

void displayUserStats(const User *user) {
    printf("\n--- Your Fitness Stats ---\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d kg\n", user->weight);
    printf("Total Workouts: %d\n", user->workoutCount);
    
    for (int i = 0; i < user->workoutCount; i++) {
        printf("Workout %d: Date: %s, Type: %s, Duration: %d min\n", 
            i + 1, user->workouts[i].date, user->workouts[i].workoutType, user->workouts[i].duration);
    }
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add User\n");
    printf("2. Add Workout\n");
    printf("3. Display User Stats\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int choice;
    int currentUserIndex = -1;

    displayWelcomeMessage();

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                if (currentUserIndex == -1) {
                    printf("Please register a user first!\n");
                } else {
                    addWorkout(&users[currentUserIndex]);
                }
                break;
            case 3:
                if (currentUserIndex == -1) {
                    printf("Please register a user first!\n");
                } else {
                    displayUserStats(&users[currentUserIndex]);
                }
                break;
            case 4:
                printf("Thank you for using the Fitness Tracker! Stay healthy and happy!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}