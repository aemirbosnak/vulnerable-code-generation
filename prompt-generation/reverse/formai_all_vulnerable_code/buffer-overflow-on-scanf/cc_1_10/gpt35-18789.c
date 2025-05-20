//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10 // Maximum number of users supported by the program
#define MAX_PASSWORD_LEN 20 // Maximum allowed length of passwords
#define MAX_USERNAME_LEN 20 // Maximum allowed length of usernames

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User users[MAX_USERS]; // Array of user structures to store user data

int num_users = 0; // Number of users currently stored in the array

/**
 * Function to add a new user to the system
 */
void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    User new_user;
    printf("Enter username:");
    scanf("%s", new_user.username);
    printf("Enter password:");
    scanf("%s", new_user.password);
    users[num_users++] = new_user;
    printf("User created successfully.\n");
}

/**
 * Function to authenticate a user
 */
int authenticate_user(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Present options to the user
    printf("Welcome to Password Manager!\n");
    printf("Select an option:\n");
    printf("1. Create a new user\n");
    printf("2. Authenticate a user\n");

    int selected_option;
    scanf("%d", &selected_option);

    switch (selected_option) {
        case 1:
            add_user();
            break;
        case 2: {
            char username[MAX_USERNAME_LEN];
            char password[MAX_PASSWORD_LEN];

            printf("Enter username:");
            scanf("%s", username);
            printf("Enter password:");
            scanf("%s", password);

            if (authenticate_user(username, password)) {
                printf("Authentication successful.\n");
            } else {
                printf("Invalid credentials.\n");
            }
            break;
        }
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}