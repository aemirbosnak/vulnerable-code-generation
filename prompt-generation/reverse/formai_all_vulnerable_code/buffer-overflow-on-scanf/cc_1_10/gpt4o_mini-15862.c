//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User userDatabase[MAX_USERS];
int userCount = 0;

void registerUser();
void loginUser();
void displayMenu();
void handleError(const char *message);

int main() {
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input! Please enter a number.");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                handleError("Invalid choice! Please try again.");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== User Registration and Login ===\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        handleError("User limit reached. Cannot register more users.");
        return;
    }

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(userDatabase[i].username, username) == 0) {
            handleError("Username already exists. Please choose another.");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    strncpy(userDatabase[userCount].username, username, MAX_LENGTH);
    strncpy(userDatabase[userCount].password, password, MAX_LENGTH);
    userCount++;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(userDatabase[i].username, username) == 0 && 
            strcmp(userDatabase[i].password, password) == 0) {
            printf("Login successful! Welcome, %s.\n", username);
            return;
        }
    }

    handleError("Invalid username or password.");
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}