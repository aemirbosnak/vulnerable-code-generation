//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 30
#define MAX_USERS 10

// Structure to store user information
typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} user_t;

// Array to store user information
user_t users[MAX_USERS];

// Function to get the user's input
char *get_input(const char *prompt) {
    char *input;
    printf("%s", prompt);
    scanf("%s", &input);
    return input;
}

// Function to create a new user
void new_user(void) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, "") == 0) {
            break;
        }
    }
    if (i == MAX_USERS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }
    strcpy(users[i].name, get_input("Enter your name: "));
    strcpy(users[i].password, get_input("Enter your password: "));
    printf("Welcome, %s!\n", users[i].name);
}

// Function to log in to the system
int login(const char *name, const char *password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, name) == 0 &&
                strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    printf("Error: Username or password incorrect\n");
    return -1;
}

// Function to log out of the system
void logout(int user_id) {
    users[user_id].name[0] = '\0';
    users[user_id].password[0] = '\0';
    printf("Goodbye, %s!\n", users[user_id].name);
}

// Function to display the list of users
void display_users(void) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        printf("%d: %s (%s)\n", i, users[i].name, users[i].password);
    }
}

int main(void) {
    int user_id;
    char name[50];
    char password[PASSWORD_LENGTH];

    // Display the list of users
    display_users();

    // Create a new user
    new_user();

    // Log in to the system
    user_id = login(name, password);

    // Log out of the system
    logout(user_id);

    return 0;
}