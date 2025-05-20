//Code Llama-13B DATASET v1.0 Category: Password management ; Style: multiplayer
/*
* C Program to Manage Passwords in a Multiplayer Style
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LEN 20
#define MAX_USERS 10

struct user {
    char username[20];
    char password[MAX_PASS_LEN];
};

void addUser(struct user* users, char* username, char* password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, "") == 0) {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            return;
        }
    }
    printf("Maximum number of users reached\n");
}

void removeUser(struct user* users, char* username) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].username, "");
            strcpy(users[i].password, "");
            return;
        }
    }
    printf("User not found\n");
}

int login(struct user* users, char* username, char* password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct user users[MAX_USERS];
    char username[20];
    char password[MAX_PASS_LEN];
    int choice;

    printf("Welcome to the password management system\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add a new user\n");
        printf("2. Remove a user\n");
        printf("3. Login\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the username: ");
            scanf("%s", username);
            printf("Enter the password: ");
            scanf("%s", password);
            addUser(users, username, password);
            break;
        case 2:
            printf("Enter the username to remove: ");
            scanf("%s", username);
            removeUser(users, username);
            break;
        case 3:
            printf("Enter the username: ");
            scanf("%s", username);
            printf("Enter the password: ");
            scanf("%s", password);
            if (login(users, username, password)) {
                printf("Login successful\n");
            } else {
                printf("Login failed\n");
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}