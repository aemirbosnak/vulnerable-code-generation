//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user;

user users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Cannot add more users.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    num_users++;
}

void login() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            if (strcmp(users[i].password, password) == 0) {
                printf("Login successful!\n");
            } else {
                printf("Incorrect password.\n");
            }

            return;
        }
    }

    printf("User not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_user();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}