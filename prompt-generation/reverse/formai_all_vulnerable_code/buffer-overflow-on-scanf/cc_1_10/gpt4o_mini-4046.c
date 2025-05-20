//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EXERCISES 10

typedef enum { CARDIO, STRENGTH, FLEXIBILITY } ExerciseType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    ExerciseType type;
    int duration;  // Duration in minutes
    int caloriesBurned;
} Exercise;

typedef struct {
    char username[MAX_NAME_LENGTH];
    float weight;  // weight in kg
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser();
void logExercise();
void displayUserStats();
void displayAllUsers();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Log Exercise\n");
        printf("3. Display User Stats\n");
        printf("4. Display All Users\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                logExercise();
                break;
            case 3:
                displayUserStats();
                break;
            case 4:
                displayAllUsers();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot add more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, MAX_NAME_LENGTH, stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';  // Remove newline character

    printf("Enter weight (in kg): ");
    scanf("%f", &newUser.weight);
    clearInputBuffer();

    newUser.exerciseCount = 0;
    users[userCount] = newUser;
    userCount++;
    printf("User %s added successfully!\n", newUser.username);
}

void logExercise() {
    char username[MAX_NAME_LENGTH];
    printf("Enter username to log exercise: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].exerciseCount >= MAX_EXERCISES) {
                printf("Maximum exercise log reached for user %s!\n", username);
                return;
            }

            Exercise newExercise;
            printf("Enter exercise name: ");
            fgets(newExercise.name, MAX_NAME_LENGTH, stdin);
            newExercise.name[strcspn(newExercise.name, "\n")] = 0;

            printf("Select exercise type (0 - Cardio, 1 - Strength, 2 - Flexibility): ");
            int type;
            scanf("%d", &type);
            newExercise.type = (ExerciseType)type;

            printf("Enter duration (in minutes): ");
            scanf("%d", &newExercise.duration);
            clearInputBuffer();

            newExercise.caloriesBurned = (int)(newExercise.duration * (type == CARDIO ? 8 : (type == STRENGTH ? 5 : 3)));  // Simple calorie calculation
            
            users[i].exercises[users[i].exerciseCount] = newExercise;
            users[i].exerciseCount++;
            printf("Exercise logged successfully for %s!\n", username);
            return;
        }
    }

    printf("User %s not found!\n", username);
}

void displayUserStats() {
    char username[MAX_NAME_LENGTH];
    printf("Enter username to display stats: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username: %s\n", users[i].username);
            printf("Weight: %.2f kg\n", users[i].weight);
            printf("Exercises logged: %d\n", users[i].exerciseCount);
            printf("Exercise Details:\n");
            for (int j = 0; j < users[i].exerciseCount; j++) {
                Exercise ex = users[i].exercises[j];
                printf("  %s (Type: %d, Duration: %d min, Calories Burned: %d)\n", 
                       ex.name, ex.type, ex.duration, ex.caloriesBurned);
            }
            return;
        }
    }

    printf("User %s not found!\n", username);
}

void displayAllUsers() {
    if (userCount == 0) {
        printf("No users available.\n");
        return;
    }

    printf("All Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s, Weight: %.2f kg, Exercises Logged: %d\n", 
               users[i].username, users[i].weight, users[i].exerciseCount);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}