//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 50

// Structure to hold user information
struct user {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Function to add a new user to the system
void add_user(struct user *users, int *num_users) {
    if (*num_users < MAX_USERS) {
        struct user new_user;

        printf("Enter username: ");
        scanf("%s", new_user.username);

        // Check if the user already exists
        for (int i = 0; i < *num_users; i++) {
            if (strcmp(new_user.username, users[i].username) == 0) {
                printf("User already exists\n");
                return;
            }
        }

        printf("Enter password: ");
        scanf("%s", new_user.password);

        // Add the new user to the array
        users[*num_users] = new_user;
        (*num_users)++;
        printf("User added successfully\n");
    } else {
        printf("Maximum number of users reached\n");
    }
}

// Function to authenticate a user
int authenticate(struct user *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct user users[MAX_USERS];
    int num_users = 0;

    while (1) {
        printf("\n");
        printf("1. Add user\n");
        printf("2. Authenticate user\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_user(users, &num_users);
        } else if (choice == 2) {
            char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            if (authenticate(users, num_users, username, password)) {
                printf("Authentication successful\n");
            } else {
                printf("Authentication failed\n");
            }
        } else if (choice == 3) {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}