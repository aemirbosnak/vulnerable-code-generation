//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 10

// Struct for the user info
struct UserInfo {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Struct for the game state
struct GameState {
    int numUsers;
    struct UserInfo users[MAX_USERS];
};

// Function to check if a username already exists
int usernameExists(char* username, struct GameState* gameState) {
    for (int i = 0; i < gameState->numUsers; i++) {
        if (strcmp(gameState->users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Initialize the game state
    struct GameState gameState;
    gameState.numUsers = 0;

    // Loop to add users
    while (1) {
        // Get the username
        char username[MAX_PASSWORD_LENGTH];
        printf("Enter a username: ");
        scanf("%s", username);

        // Check if the user already exists
        if (usernameExists(username, &gameState)) {
            printf("ERROR: Username already exists\n");
            continue;
        }

        // Get the password
        char password[MAX_PASSWORD_LENGTH];
        printf("Enter a password: ");
        scanf("%s", password);

        // Add the user to the game state
        struct UserInfo newUser;
        strncpy(newUser.username, username, MAX_PASSWORD_LENGTH);
        strncpy(newUser.password, password, MAX_PASSWORD_LENGTH);

        if (gameState.numUsers < MAX_USERS) {
            gameState.users[gameState.numUsers] = newUser;
            gameState.numUsers++;
        } else {
            printf("ERROR: Maximum number of users reached\n");
            break;
        }

        // Ask the user if they want to add another user
        char another[MAX_PASSWORD_LENGTH];
        printf("Add another user? (y/n): ");
        scanf("%s", another);
        if (strcmp(another, "y") != 0) {
            break;
        }
    }

    // Loop to authenticate users
    while (1) {
        // Get the username
        char username[MAX_PASSWORD_LENGTH];
        printf("Enter your username: ");
        scanf("%s", username);

        // Get the password
        char password[MAX_PASSWORD_LENGTH];
        printf("Enter your password: ");
        scanf("%s", password);

        // Check if the user exists and the password matches
        int authenticated = 0;
        for (int i = 0; i < gameState.numUsers; i++) {
            if (strcmp(gameState.users[i].username, username) == 0 &&
                strcmp(gameState.users[i].password, password) == 0) {
                authenticated = 1;
            }
        }

        // Print the result of the authentication
        if (authenticated) {
            printf("Authenticated!\n");
        } else {
            printf("Not authenticated. Please try again.\n");
        }

        // Ask the user if they want to quit
        char quit[MAX_PASSWORD_LENGTH];
        printf("Quit? (y/n): ");
        scanf("%s", quit);
        if (strcmp(quit, "y") == 0) {
            break;
        }
    }

    return 0;
}