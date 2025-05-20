//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void createUser(User *user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    printf("Enter password: ");
    scanf("%s", user->password);
}

void displayUser(User user) {
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
}

void main() {
    User user;
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Create user\n");
        printf("2. Display user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createUser(&user);
            printf("User created successfully!\n");
            break;
        case 2:
            displayUser(user);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);
}