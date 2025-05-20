//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 10
#define MAX_LENGTH 20

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct User users[MAX_USERS];
int num_users = 0;

bool add_user(char username[], char password[]) {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return false;
    }
    
    // Check if username already exists
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists.\n");
            return false;
        }
    }
    
    // Add new user
    struct User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    users[num_users++] = new_user;
    printf("New user successfully added.\n");
    return true;
}

bool authenticate(char username[], char password[]) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char command[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    
    printf("Welcome to the User Administration Program.\n");
    
    while (true) {
        printf("Enter a command (adduser, login, quit):\n");
        scanf("%s", command);
        
        if (strcmp(command, "adduser") == 0) {
            printf("Enter username:\n");
            scanf("%s", username);
            printf("Enter password:\n");
            scanf("%s", password);
            add_user(username, password);
        }
        else if (strcmp(command, "login") == 0) {
            printf("Enter username:\n");
            scanf("%s", username);
            printf("Enter password:\n");
            scanf("%s", password);
            if (authenticate(username, password)) {
                printf("Login successful.\n");
            }
            else {
                printf("Invalid username or password.\n");
            }
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Exiting Program.\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}