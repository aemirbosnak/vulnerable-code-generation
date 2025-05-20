//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 32

// User structure definition
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Array of users
User users[MAX_USERS];

// Number of registered users
int numUsers = 0;

// Function prototypes
void registerUser();
void loginUser();

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to register a new user
void registerUser() {
    char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("\nEnter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);
    if (numUsers < MAX_USERS) {
        strcpy(users[numUsers].username, username);
        strcpy(users[numUsers].password, password);
        numUsers++;
        printf("Registration successful!\n");
    } else {
        printf("Maximum number of users reached!\n");
    }
}

// Function to login a user
void loginUser() {
    char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    int userFound = 0;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            userFound = 1;
            break;
        }
    }
    if (!userFound) {
        printf("Invalid username or password!\n");
    }
}