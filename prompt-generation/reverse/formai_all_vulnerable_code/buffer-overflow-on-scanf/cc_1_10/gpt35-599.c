//FormAI DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME 50
#define MAX_PASSWORD 50

struct User {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
};

void registerUser(struct User *users, int *numUsers) {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME, stdin);

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD, stdin);

    if (*numUsers > 0) {
        for (int i = 0; i < *numUsers; i++) {
            if (strcmp(users[i].username, username) == 0) {
                printf("Username already exists. Please choose another.\n");
                return;
            }
        }
    }

    // Add user to list
    strcpy(users[*numUsers].username, username);
    strcpy(users[*numUsers].password, password);
    (*numUsers)++;

    printf("User registered successfully!\n");
}

void loginUser(struct User *users, int numUsers) {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME, stdin);

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD, stdin);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Incorrect username or password.\n");
}

int main() {
    struct User users[10];
    int choice, numUsers = 0;

    printf("Welcome to User Management System!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Register a user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                registerUser(users, &numUsers);
                break;
            case 2:
                loginUser(users, numUsers);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}