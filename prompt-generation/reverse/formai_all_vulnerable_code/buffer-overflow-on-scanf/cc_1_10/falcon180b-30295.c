//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 1000
#define PASSWORD_LENGTH 64

typedef struct {
    char username[32];
    char password[PASSWORD_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);

    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    num_users++;
}

int authenticate_user(char *username, char *password) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int choice, i;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add user\n");
        printf("2. Authenticate user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_users >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
            } else {
                add_user();
            }
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", users[0].username);

            printf("Enter password: ");
            scanf("%s", users[0].password);

            if (authenticate_user(users[0].username, users[0].password)) {
                printf("Authentication successful.\n");
            } else {
                printf("Authentication failed.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}