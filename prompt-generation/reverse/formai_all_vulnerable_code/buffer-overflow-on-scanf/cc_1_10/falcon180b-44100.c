//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERNAMES 100
#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

void create_user(user_t* user) {
    printf("Enter a username: ");
    scanf("%s", user->username);

    printf("Enter a password: ");
    scanf("%s", user->password);

    printf("User %s created.\n", user->username);
}

void login(user_t* users, int num_users) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Login failed.\n");
}

void main() {
    user_t users[MAX_USERNAMES];
    int num_users = 0;

    while (num_users < MAX_USERNAMES) {
        printf("Enter 1 to create a new user, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            user_t new_user;
            create_user(&new_user);
            strcpy(users[num_users].username, new_user.username);
            strcpy(users[num_users].password, new_user.password);
            num_users++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    int choice;
    while (1) {
        printf("Enter 1 to login, 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice!= 1) {
            printf("Invalid choice.\n");
            continue;
        }

        login(users, num_users);
    }
}