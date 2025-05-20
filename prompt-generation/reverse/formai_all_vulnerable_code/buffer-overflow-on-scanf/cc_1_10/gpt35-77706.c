//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_USERS 5

// Data structures to hold user data
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user(char* username, char* password) {
    if (num_users >= MAX_USERS) {
        printf("Error: maximum number of users reached\n");
        return;
    }

    User new_user;
    strncpy(new_user.username, username, MAX_USERNAME_LENGTH);
    strncpy(new_user.password, password, MAX_PASSWORD_LENGTH);

    users[num_users++] = new_user;
    printf("User %s added.\n", username);
}

bool authenticate_user(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strncmp(users[i].username, username, MAX_USERNAME_LENGTH) == 0 
            && strncmp(users[i].password, password, MAX_PASSWORD_LENGTH) == 0) 
        {
            return true;
        }
    }
    return false;
}

int main() {
    add_user("user1", "password123");
    add_user("user2", "password456");

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (authenticate_user(username, password)) {
        printf("Login successful.\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}