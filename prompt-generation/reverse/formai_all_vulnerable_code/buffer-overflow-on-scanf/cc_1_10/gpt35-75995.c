//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_USERS 10

struct user {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
};

struct user users[MAX_NUM_USERS];
int numUsers = 0;

void addUser() {
    if (numUsers >= MAX_NUM_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already taken.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
        return;
    }

    struct user newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    users[numUsers] = newUser;
    numUsers++;
}

void login() {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                printf("Login successful.\n");
                return;
            } else {
                printf("Incorrect password.\n");
                return;
            }
        }
    }

    printf("User not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add user\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}