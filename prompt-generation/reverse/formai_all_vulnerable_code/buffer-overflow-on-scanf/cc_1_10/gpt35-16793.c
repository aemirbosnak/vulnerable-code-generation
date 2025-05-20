//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LEN 20  // maximum password length
#define MAX_USERS 10      // maximum number of users
#define MAX_ATTEMPTS 3    // maximum login attempts

// User structure
typedef struct user {
    char username[MAX_PASS_LEN];  // username
    char password[MAX_PASS_LEN];  // password
} User;

// Function prototypes
int createUser();
int enterUser();
void showMenu();
void changePassword(User *u);
void viewPassword(User *u);

// Global variables
User users[MAX_USERS];  // array of users
int numUsers = 0;       // number of users

int main() {
    int choice;
    int loggedIn = 0;      // 1 if user is logged in, 0 otherwise
    int current_user = -1; // index of the current user
    
    // Main loop
    while (1) {
        showMenu();  // show menu options
        
        // Get choice from user
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  // Create user
                createUser();
                break;
            case 2:  // Enter user
                current_user = enterUser();
                if (current_user >= 0) {
                    loggedIn = 1;  // login successful
                }
                break;
            case 3:  // Change password
                if (loggedIn) {
                    changePassword(&users[current_user]);
                } else {
                    printf("You must first log in to change your password.\n");
                }
                break;
            case 4:  // View password
                if (loggedIn) {
                    viewPassword(&users[current_user]);
                } else {
                    printf("You must first log in to view your password.\n");
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}

// Create a new user
int createUser() {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
    
    // Check if there is room for another user
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return -1;
    }
    
    // Get username and password from user
    printf("Enter username (up to %d characters): ", MAX_PASS_LEN);
    scanf("%s", username);
    printf("Enter password (up to %d characters): ", MAX_PASS_LEN);
    scanf("%s", password);
    
    // Create new user and add to array
    User u = {0};
    strncpy(u.username, username, MAX_PASS_LEN);
    strncpy(u.password, password, MAX_PASS_LEN);
    users[numUsers++] = u;
    
    printf("User created successfully!\n");
    return numUsers - 1;
}

// Enter existing user
int enterUser() {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
    
    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    // Check if username and password match
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            printf("Welcome, %s!\n", username);
            return i;
        }
    }
    
    printf("Username or password incorrect.\n");
    return -1;
}

// Show menu options
void showMenu() {
    printf("\nWelcome to Password Manager!\n");
    printf("----------------------------------\n");
    printf("1 - Create user\n");
    printf("2 - Enter user\n");
    printf("3 - Change password\n");
    printf("4 - View password\n");
}

// Change user's password
void changePassword(User *u) {
    char password[MAX_PASS_LEN];
    printf("Enter new password: ");
    scanf("%s", password);
    strncpy(u->password, password, MAX_PASS_LEN);
    printf("Password changed successfully!\n");
}

// View user's password
void viewPassword(User *u) {
    printf("Your password is: %s\n", u->password);
}