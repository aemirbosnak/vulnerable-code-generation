//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_USERS 10

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);
    num_users++;
}

void print_users() {
    printf("Users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].username);
    }
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("Password Manager\n");
        printf("1. Add user\n");
        printf("2. Print users\n");
        printf("3. Login\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                print_users();
                break;
            case 3:
                if (login()) {
                    printf("Login successful.\n");
                } else {
                    printf("Login failed.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}