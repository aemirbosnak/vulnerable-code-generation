//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

void add_user(user_t users[], int num_users, char* username, char* password) {
    if (num_users >= MAX_USERS) {
        printf("Cannot add more users.\n");
        return;
    }

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);

    num_users++;
}

int authenticate_user(user_t users[], int num_users, char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    user_t users[MAX_USERS];
    int num_users = 0;

    add_user(users, num_users, "admin", "password");
    add_user(users, num_users, "user1", "password1");
    add_user(users, num_users, "user2", "password2");

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        if (authenticate_user(users, num_users, username, password)) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Login failed.\n");
        }
    }

    return 0;
}