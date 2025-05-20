//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // duration in minutes
    int caloriesBurned;
} Exercise;

typedef struct {
    char username[MAX_NAME_LENGTH];
    int age;
    int weight; // weight in kg
    int height; // height in cm
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User registration limit reached.\n");
        return;
    }
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter weight (in kg): ");
    scanf("%d", &newUser.weight);
    printf("Enter height (in cm): ");
    scanf("%d", &newUser.height);
    newUser.exerciseCount = 0;
    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

void addExercise(User *user) {
    if (user->exerciseCount >= MAX_EXERCISES) {
        printf("Maximum number of exercises reached.\n");
        return;
    }

    Exercise newExercise;
    printf("Enter exercise name: ");
    scanf("%s", newExercise.name);
    printf("Enter duration (in minutes): ");
    scanf("%d", &newExercise.duration);
    
    // Simple calculation for calories burned (rough estimate)
    newExercise.caloriesBurned = (newExercise.duration * 5); // 5 calories per minute
    user->exercises[user->exerciseCount++] = newExercise;

    printf("Exercise added successfully!\n");
}

void viewExercises(User *user) {
    if (user->exerciseCount == 0) {
        printf("No exercises recorded.\n");
        return;
    }
    printf("Exercises for user %s:\n", user->username);
    for (int i = 0; i < user->exerciseCount; i++) {
        printf("%d. %s - %d minutes, Calories burned: %d\n", 
               i + 1, 
               user->exercises[i].name, 
               user->exercises[i].duration, 
               user->exercises[i].caloriesBurned);
    }
}

void viewUserInfo(User *user) {
    printf("User Info:\n");
    printf("Username: %s\n", user->username);
    printf("Age: %d\n", user->age);
    printf("Weight: %d kg\n", user->weight);
    printf("Height: %d cm\n", user->height);
    
    int totalCalories = 0;
    for (int i = 0; i < user->exerciseCount; i++) {
        totalCalories += user->exercises[i].caloriesBurned;
    }
    printf("Total calories burned: %d\n", totalCalories);
}

void menu() {
    printf("\n--------- Fitness Tracker ---------\n");
    printf("1. Register User\n");
    printf("2. Add Exercise\n");
    printf("3. View Exercises\n");
    printf("4. View User Info\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char username[MAX_NAME_LENGTH];

    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("Enter username to add exercise: ");
                scanf("%s", username);
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(users[i].username, username) == 0) {
                        addExercise(&users[i]);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter username to view exercises: ");
                scanf("%s", username);
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(users[i].username, username) == 0) {
                        viewExercises(&users[i]);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter username to view user info: ");
                scanf("%s", username);
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(users[i].username, username) == 0) {
                        viewUserInfo(&users[i]);
                        break;
                    }
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}