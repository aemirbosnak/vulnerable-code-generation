//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void createUser(User *user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    printf("Enter password: ");
    scanf("%s", user->password);
}

void login(User *users, int numUsers, char *username, char *password) {
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Login failed.\n");
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;

    while (numUsers < MAX_USERS) {
        User newUser;
        createUser(&newUser);

        int i;
        for (i = 0; i < numUsers; i++) {
            if (strcmp(users[i].username, newUser.username) == 0) {
                printf("Username already exists.\n");
                break;
            }
        }

        if (i == numUsers) {
            users[numUsers] = newUser;
            numUsers++;
        }
    }

    int choice;
    while (1) {
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char username[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            login(users, numUsers, username, password);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}