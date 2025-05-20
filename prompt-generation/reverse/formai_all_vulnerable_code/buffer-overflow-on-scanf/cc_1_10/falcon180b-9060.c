//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100

typedef struct {
    char username[20];
    char password[20];
    int userID;
} User;

User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists.\n");
            return;
        }
    }

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    users[numUsers].userID = numUsers + 1;

    numUsers++;

    printf("User added successfully.\n");
}

void login() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Login failed.\n");
}

void main() {
    int choice;

    do {
        printf("\n\nPassword Management System\n");
        printf("1. Add User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
        }
    } while (1);
}