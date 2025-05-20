//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LEN 20

typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User users[MAX_USERS];
int num_users = 0;

void register_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User user;

    printf("Enter username: ");
    scanf("%s", user.username);

    printf("Enter password: ");
    scanf("%s", user.password);

    users[num_users++] = user;

    printf("User registered successfully.\n");
}

void login() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LEN];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LEN];
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0
            && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    while (1) {
        printf("1. Register\n2. Login\n3. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}