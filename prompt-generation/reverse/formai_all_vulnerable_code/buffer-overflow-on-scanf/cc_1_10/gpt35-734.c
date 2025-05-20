//FormAI DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    if (numUsers == MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);

    numUsers++;

    printf("User added successfully.\n");
}

void login() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Error: Invalid username or password.\n");
}

void displayUsers() {
    for (int i = 0; i < numUsers; i++) {
        printf("%s\n", users[i].username);
    }
}

void displayMenu() {
    printf("1. Add user\n");
    printf("2. Login\n");
    printf("3. Display users\n");
    printf("4. Exit\n");
}

int main() {
    while (1) {
        displayMenu();

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                login();
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}