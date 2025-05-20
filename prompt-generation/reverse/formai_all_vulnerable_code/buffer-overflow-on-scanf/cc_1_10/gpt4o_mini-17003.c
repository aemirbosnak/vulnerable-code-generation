//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_EXERCISES 20
#define NAME_LENGTH 50
#define EXERCISE_NAME_LENGTH 30

typedef struct {
    char name[EXERCISE_NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned
} Exercise;

typedef struct {
    char username[NAME_LENGTH];
    int totalExercises;
    Exercise exercises[MAX_EXERCISES];
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser();
void logExercise(int userIndex);
void viewExercises(int userIndex);
void listUsers();

int main() {
    int choice, userIndex;

    while(1) {
        printf("\nFitness Tracker\n");
        printf("1. Add User\n");
        printf("2. Log Exercise\n");
        printf("3. View Exercises\n");
        printf("4. List Users\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printf("Select user (0 - %d): ", userCount - 1);
                scanf("%d", &userIndex);
                if(userIndex >= 0 && userIndex < userCount) {
                    logExercise(userIndex);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 3:
                printf("Select user (0 - %d): ", userCount - 1);
                scanf("%d", &userIndex);
                if(userIndex >= 0 && userIndex < userCount) {
                    viewExercises(userIndex);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 4:
                listUsers();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addUser() {
    if(userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }
    printf("Enter username (max %d characters): ", NAME_LENGTH - 1);
    scanf("%s", users[userCount].username);
    users[userCount].totalExercises = 0;
    userCount++;
    printf("User %s added successfully.\n", users[userCount - 1].username);
}

void logExercise(int userIndex) {
    if(users[userIndex].totalExercises >= MAX_EXERCISES) {
        printf("Maximum exercises limit reached for %s.\n", users[userIndex].username);
        return;
    }
    
    Exercise *exercise = &users[userIndex].exercises[users[userIndex].totalExercises];
    
    printf("Enter exercise name (max %d characters): ", EXERCISE_NAME_LENGTH - 1);
    scanf("%s", exercise->name);
    
    printf("Enter duration (in minutes): ");
    scanf("%d", &exercise->duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &exercise->calories);
    
    users[userIndex].totalExercises++;
    printf("Exercise logged successfully for %s.\n", users[userIndex].username);
}

void viewExercises(int userIndex) {
    User user = users[userIndex];
    printf("\nExercises for %s:\n", user.username);
    for(int i = 0; i < user.totalExercises; i++) {
        Exercise e = user.exercises[i];
        printf("Exercise %d: %s, Duration: %d minutes, Calories: %d\n",
               i + 1, e.name, e.duration, e.calories);
    }
    if(user.totalExercises == 0) {
        printf("No exercises logged yet.\n");
    }
}

void listUsers() {
    if(userCount == 0) {
        printf("No users available.\n");
        return;
    }
    printf("List of users:\n");
    for(int i = 0; i < userCount; i++) {
        printf("%d: %s\n", i, users[i].username);
    }
}