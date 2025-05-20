//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
// Password Management System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define user struct
typedef struct {
    char username[20];
    char password[20];
} User;

// Define function prototypes
void login(User [], int);
void registerUser(User [], int*);
void changePassword(User []);

int main() {
    int choice, numUsers=0, i;
    User users[50]; // Maximum of 50 users allowed in the system

    while (true) {
        printf("\nPassword Management System\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                login(users, numUsers);
                break;
            case 2: 
                registerUser(users, &numUsers);
                break;
            case 3: 
                changePassword(users);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to allow user login
void login(User users[], int numUsers) {
    char username[20], password[20];
    int i;

    printf("\n--- Login ---\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (i=0; i<numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Welcome, %s!\n", username);
            return;
        }
    }

    printf("Incorrect username or password. Please try again.\n");
}

// Function to register a new user
void registerUser(User users[], int *numUsers) {
    char username[20], password[20];

    printf("\n--- Register ---\n");
    printf("Enter username: ");
    scanf("%s", username);

    // Check if username already exists
    for (int i=0; i<*numUsers; i++) {
        if (strcmp(username, users[i].username) == 0) {
            printf("Username already exists. Please choose another.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    // Add new user to array
    strcpy(users[*numUsers].username, username);
    strcpy(users[*numUsers].password, password);
    (*numUsers)++;

    printf("New user registered!\n");
}

// Function to allow user to change password
void changePassword(User users[]) {
    char username[20], oldPassword[20], newPassword[20];
    int i;

    printf("\n--- Change Password ---\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter current password: ");
    scanf("%s", oldPassword);

    for (i=0; i<50; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(oldPassword, users[i].password) == 0) {
            printf("Enter new password: ");
            scanf("%s", newPassword);
            strcpy(users[i].password, newPassword);
            printf("Password updated!\n");
            return;
        }
    }

    printf("Incorrect username or password. Please try again.\n");
}