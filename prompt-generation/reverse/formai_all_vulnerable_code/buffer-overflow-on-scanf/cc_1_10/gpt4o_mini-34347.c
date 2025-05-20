//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LEN 20
#define PASSWORD_LEN 20

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int userID;
} User;

User* userDatabase[MAX_USERS];
int userCount = 0;

int addUser(const char* username, const char* password) {
    if (userCount >= MAX_USERS) {
        printf("Error: User database is full.\n");
        return -1; // Database full
    }

    for (int i = 0; i < userCount; i++) {
        if (strcmp(userDatabase[i]->username, username) == 0) {
            printf("Error: Username already exists.\n");
            return -2; // Username exists
        }
    }

    User* newUser = (User*)malloc(sizeof(User));
    strncpy(newUser->username, username, USERNAME_LEN);
    strncpy(newUser->password, password, PASSWORD_LEN);
    newUser->userID = userCount + 1; // Simple user ID assignment

    userDatabase[userCount++] = newUser;
    printf("User '%s' added successfully with ID %d.\n", username, newUser->userID);
    return newUser->userID; // Return user ID
}

void listUsers() {
    printf("\nCurrent users in the database:\n");
    for (int i = 0; i < userCount; i++) {
        printf("User ID: %d, Username: %s\n", userDatabase[i]->userID, userDatabase[i]->username);
    }
}

User* findUser(const char* username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(userDatabase[i]->username, username) == 0) {
            return userDatabase[i];
        }
    }
    return NULL; // User not found
}

int deleteUser(const char* username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(userDatabase[i]->username, username) == 0) {
            free(userDatabase[i]); // Free memory
            userDatabase[i] = userDatabase[userCount - 1]; // Replace with last user
            userCount--;
            printf("User '%s' deleted successfully.\n", username);
            return 0; // Success
        }
    }
    printf("Error: User '%s' not found.\n", username);
    return -1; // User not found
}

void freeUsers() {
    for (int i = 0; i < userCount; i++) {
        free(userDatabase[i]);
    }
}

int main() {
    char command[50], username[USERNAME_LEN], password[PASSWORD_LEN];
    
    printf("Welcome to the User Database Simulator!\n");
    
    while (1) {
        printf("\nEnter command (add/list/find/delete/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addUser(username, password);
        } else if (strcmp(command, "list") == 0) {
            listUsers();
        } else if (strcmp(command, "find") == 0) {
            printf("Enter username to find: ");
            scanf("%s", username);
            User* user = findUser(username);
            if (user) {
                printf("Found user: ID: %d, Username: %s\n", user->userID, user->username);
            } else {
                printf("User '%s' not found.\n", username);
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter username to delete: ");
            scanf("%s", username);
            deleteUser(username);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    freeUsers();
    printf("Exiting the User Database Simulator. Goodbye!\n");
    return 0;
}