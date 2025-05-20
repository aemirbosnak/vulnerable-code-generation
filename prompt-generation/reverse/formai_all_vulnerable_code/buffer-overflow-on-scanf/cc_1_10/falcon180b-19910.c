//Falcon-180B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50
#define MAX_USERS 100
#define MAX_USER_LEN 50

typedef struct {
    char username[MAX_USER_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

typedef struct {
    User users[MAX_USERS];
    int numUsers;
} PasswordManager;

PasswordManager* createPasswordManager() {
    PasswordManager* manager = (PasswordManager*)malloc(sizeof(PasswordManager));
    manager->numUsers = 0;
    return manager;
}

void addUser(PasswordManager* manager, char* username, char* password) {
    if (manager->numUsers >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    strncpy(manager->users[manager->numUsers].username, username, MAX_USER_LEN);
    strncpy(manager->users[manager->numUsers].password, password, MAX_PASSWORD_LEN);

    manager->numUsers++;
}

int authenticateUser(PasswordManager* manager, char* username, char* password) {
    for (int i = 0; i < manager->numUsers; i++) {
        if (strcmp(manager->users[i].username, username) == 0) {
            if (strcmp(manager->users[i].password, password) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    PasswordManager* manager = createPasswordManager();

    char username[MAX_USER_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        addUser(manager, username, password);
    }

    return 0;
}