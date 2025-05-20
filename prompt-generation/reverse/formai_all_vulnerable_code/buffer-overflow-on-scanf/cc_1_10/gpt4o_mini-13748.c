//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_EXERCISES 10
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char exerciseType[MAX_EXERCISES][MAX_NAME_LEN];
    int exerciseDuration[MAX_EXERCISES];
    int recordCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Too many users. Can't add more!\n");
        return;
    }
    
    User newUser;
    printf("Enter name: ");
    fgets(newUser.name, MAX_NAME_LEN, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0;  // Remove newline character
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    getchar();  // Clear the input buffer

    newUser.recordCount = 0;
    users[userCount++] = newUser;
    printf("User added paranoia succeeded, but at what cost?\n");
}

void logExercise(User *user) {
    if (user->recordCount >= MAX_EXERCISES) {
        printf("Already logged too many exercises. Exercise resistance is futile!\n");
        return;
    }
    
    printf("What exercise did you do? ");
    fgets(user->exerciseType[user->recordCount], MAX_NAME_LEN, stdin);
    user->exerciseType[user->recordCount][strcspn(user->exerciseType[user->recordCount], "\n")] = 0;
    printf("For how long (in minutes)? ");
    scanf("%d", &user->exerciseDuration[user->recordCount]);
    getchar();

    user->recordCount++;
    printf("Exercise logged, but are you logging too much?...\n");
}

void viewRecords(User *user) {
    printf("Exercise records for %s:\n", user->name);
    for (int i = 0; i < user->recordCount; i++) {
        printf("Exercise: %s, Duration: %d minutes\n", user->exerciseType[i], user->exerciseDuration[i]);
    }
}

void viewAllUsers() {
    printf("There are %d registered users. Be wary!\n", userCount);
    for (int i = 0; i < userCount; i++) {
        printf("User %d: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
}

User* selectUser() {
    printf("Choose a user (1 to %d): ", userCount);
    int choice;
    scanf("%d", &choice);
    getchar();  // Clear buffer
    if (choice < 1 || choice > userCount) {
        printf("Invalid choice! Better check again...\n");
        return NULL;
    }
    return &users[choice - 1];
}

int main() {
    while (1) {
        printf("\nFitness Tracker System\n");
        printf("1. Add User\n");
        printf("2. Log Exercise\n");
        printf("3. View Records\n");
        printf("4. View All Users\n");
        printf("5. Exit\n");
        printf("Choose an action (1-5): ");
        
        int action;
        scanf("%d", &action);
        getchar();  // Clear buffer

        switch (action) {
            case 1:
                addUser();
                break;
            case 2: {
                User* user = selectUser();
                if (user) {
                    logExercise(user);
                }
                break;
            }
            case 3: {
                User* user = selectUser();
                if (user) {
                    viewRecords(user);
                }
                break;
            }
            case 4:
                viewAllUsers();
                break;
            case 5:
                printf("Exiting... or is it?\n");
                return 0;
            default:
                printf("Strange choice! Are they really options?\n");
                break;
        }
    }
    return 0;
}