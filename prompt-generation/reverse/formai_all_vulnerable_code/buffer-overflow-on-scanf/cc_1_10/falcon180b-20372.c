//Falcon-180B DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 10
#define MAX_PASSWORD 20

typedef struct user {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
} User;

void addUser(User *users, int numUsers, char *username, char *password) {
    if (numUsers == MAX_USER) {
        printf("Maximum number of users reached.\n");
        return;
    }

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);

    numUsers++;
}

int login(User *users, int numUsers, char *username, char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    User users[MAX_USER];
    int numUsers = 0;

    addUser(users, numUsers, "admin", "admin");
    addUser(users, numUsers, "user1", "password1");
    addUser(users, numUsers, "user2", "password2");

    char username[MAX_USER];
    char password[MAX_PASSWORD];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (login(users, numUsers, username, password)) {
        printf("Login successful.\n");
    } else {
        printf("Login failed.\n");
    }

    return 0;
}