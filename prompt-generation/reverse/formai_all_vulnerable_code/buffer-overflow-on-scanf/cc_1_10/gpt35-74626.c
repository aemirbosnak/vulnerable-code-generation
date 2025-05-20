//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_PASSWORD_LEN 20

// Structure to represent a user
typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} user_t;

// Global variables
user_t users[MAX_USERS];
int num_users = 0;

// Function declarations
void add_user();
void login();

int main() {
    int option;

    // Loop through the menu until the user chooses to quit
    do {
        printf("\n1. Add user\n");
        printf("2. Login\n");
        printf("3. Quit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_user();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while(option != 3);

    return 0;
}

// Function to add a new user with a username and password
void add_user() {
    // Check if we have space for a new user
    if(num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    // Get the username and password from the user
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Check if the username already exists
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    // Add the new user to the list
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;

    printf("User added successfully.\n");
}

// Function to authenticate a user by username and password
void login() {
    // Get the username and password from the user
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Find the user in the list
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}