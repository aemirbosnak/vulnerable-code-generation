//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct PasswordManager {
    struct User users[MAX_USERS];
    int num_users;
};

void add_user(struct PasswordManager* manager, char* username, char* password) {
    if (manager->num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached!\n");
        return;
    }

    struct User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);

    manager->users[manager->num_users] = new_user;
    manager->num_users++;
}

int check_user_login(struct PasswordManager* manager, char* username, char* password) {
    for (int i = 0; i < manager->num_users; i++) {
        struct User user = manager->users[i];
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct PasswordManager manager;
    manager.num_users = 0;

    add_user(&manager, "user1", "pass1");
    add_user(&manager, "user2", "pass2");

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    if (check_user_login(&manager, username, password)) {
        printf("Login successful!");
    } else {
        printf("Login failed. Incorrect username or password.");
    }

    return 0;
}