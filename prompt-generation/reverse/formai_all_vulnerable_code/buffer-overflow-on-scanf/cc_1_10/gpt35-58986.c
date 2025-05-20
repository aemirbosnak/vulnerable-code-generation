//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
#define PASSWORD_LENGTH 10
#define MAX_USERS 50

struct User {
    char username[MAX_LENGTH];
    char password[PASSWORD_LENGTH + 1];
    int id;
};

struct User users[MAX_USERS];
int num_users = 0;

void register_user() {
    struct User user;
    printf("Enter your username: ");
    fgets(user.username, MAX_LENGTH, stdin);
    printf("Enter your password (must be %d characters): ", PASSWORD_LENGTH);
    fgets(user.password, PASSWORD_LENGTH + 1, stdin);
    user.password[strcspn(user.password, "\n")] = 0; // remove newline character
    
    // check if password meets requirements
    if (strlen(user.password) != PASSWORD_LENGTH) {
        printf("Password must be %d characters long.\n", PASSWORD_LENGTH);
        return;
    }
    
    // check if username already exists
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, user.username) == 0) {
            printf("Username already exists. Please choose another.\n");
            return;
        }
    }
    
    user.id = num_users + 1;
    users[num_users] = user;
    num_users++;
    printf("User registered successfully!\n");
}

void login() {
    char username[MAX_LENGTH];
    char password[PASSWORD_LENGTH + 1];
    printf("Enter your username: ");
    fgets(username, MAX_LENGTH, stdin);
    printf("Enter your password: ");
    fgets(password, PASSWORD_LENGTH + 1, stdin);
    password[strcspn(password, "\n")] = 0;
    
    // find user with matching username and password
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", users[i].username);
            return;
        }
    }
    
    printf("Incorrect username or password. Please try again.\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}