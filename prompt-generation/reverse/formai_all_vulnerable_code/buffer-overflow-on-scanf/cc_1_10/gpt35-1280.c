//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 50
#define MAX_USERS 10

struct User {
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
};

// Function prototypes
void printMenu();
void createAccount(struct User users[], int *numUsers);
void login(struct User users[], int numUsers);
void changePassword(struct User users[], int numUsers);
int isValidUsername(char *username);
int isValidPassword(char *password);

int main() {
    struct User users[MAX_USERS];
    int numUsers = 0;
    int choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(users, &numUsers);
                break;
            case 2:
                login(users, numUsers);
                break;
            case 3:
                changePassword(users, numUsers);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Prints the main menu
void printMenu() {
    printf("\nPassword Management System\n\n");
    printf("1. Create account\n");
    printf("2. Login\n");
    printf("3. Change password\n");
    printf("4. Quit\n");
    printf("\nEnter your choice: ");
}

// Creates a new user account
void createAccount(struct User users[], int *numUsers) {
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
    
    // Get input from user
    printf("Enter a username (up to %d characters): ", MAX_USERNAME_LEN);
    scanf("%s", username);
    printf("Enter a password (up to %d characters): ", MAX_PASSWORD_LEN);
    scanf("%s", password);
    
    // Validate username and password
    if (!isValidUsername(username)) {
        printf("Invalid username. Usernames can only contain letters, numbers, and underscores.\n");
        return;
    }
    
    if (!isValidPassword(password)) {
        printf("Invalid password. Passwords must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n");
        return;
    }
    
    // Check if username already exists
    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }
    
    // Add new user to array
    struct User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    users[*numUsers] = newUser;
    *numUsers += 1;
    
    printf("Account created successfully.\n");
}

// Logs in a user
void login(struct User users[], int numUsers) {
    char username[MAX_USERNAME_LEN+1];
    char password[MAX_PASSWORD_LEN+1];
    
    // Get input from user
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    // Find user in array and check password
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                printf("Login successful!\n");
                return;
            } else {
                printf("Incorrect password. Please try again.\n");
                return;
            }
        }
    }
    
    printf("Username not found. Please try again.\n");
}

// Allows a user to change their password
void changePassword(struct User users[], int numUsers) {
    char username[MAX_USERNAME_LEN+1];
    char oldPassword[MAX_PASSWORD_LEN+1];
    char newPassword[MAX_PASSWORD_LEN+1];
    
    // Get input from user
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your old password: ");
    scanf("%s", oldPassword);
    printf("Enter a new password (up to %d characters): ", MAX_PASSWORD_LEN);
    scanf("%s", newPassword);
    
    // Find user in array and check password
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, oldPassword) == 0) {
                // Validate new password
                if (!isValidPassword(newPassword)) {
                    printf("Invalid password. Passwords must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n");
                    return;
                }
                
                // Update password
                strcpy(users[i].password, newPassword);
                printf("Password changed successfully!\n");
                return;
            } else {
                printf("Incorrect password. Please try again.\n");
                return;
            }
        }
    }
    
    printf("Username not found. Please try again.\n");
}

// Returns 1 if username is valid, 0 otherwise
int isValidUsername(char *username) {
    for (int i = 0; i < strlen(username); i++) {
        if (!isalnum(username[i]) && username[i] != '_') {
            return 0;
        }
    }
    
    return 1;
}

// Returns 1 if password is valid, 0 otherwise
int isValidPassword(char *password) {
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    
    if (strlen(password) < 8) {
        return 0;
    }
    
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        }
        if (islower(password[i])) {
            hasLower = 1;
        }
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }
    
    if (hasUpper && hasLower && hasDigit) {
        return 1;
    } else {
        return 0;
    }
}