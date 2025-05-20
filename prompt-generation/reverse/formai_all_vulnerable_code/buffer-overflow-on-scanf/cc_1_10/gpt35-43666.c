//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 20     // maximum password length
#define MAX_USERS 10               // maximum number of users that can be stored

// Structure to store each user's information
typedef struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Function to check if a given username is already taken
int isUsernameTaken(User users[], int num_users, char* username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new user to the system
void addUser(User users[], int* num_users) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", username);

    if (isUsernameTaken(users, *num_users, username)) {
        printf("Username already taken!\n");
        return;
    }

    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    // Encrypt the password before storing
    // [Implementation of password encryption not shown in this example program]
    strcpy(users[*num_users].username, username);
    strcpy(users[*num_users].password, password);

    *num_users += 1;
    printf("User added successfully!\n");
}

// Function to authenticate a user by checking their username and password
int authenticateUser(User users[], int num_users, char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                return 1;   // Authentication success
            } else {
                return 0;   // Authentication failed (password mismatch)
            }
        }
    }
    return 0;   // Authentication failed (username not found)
}

int main() {
    User users[MAX_USERS];
    int num_users = 0;

    int choice;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("1. Add user\n");
        printf("2. Authenticate user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &num_users);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                if (authenticateUser(users, num_users, username, password)) {
                    printf("Authentication success!\n");
                } else {
                    printf("Authentication failed!\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}