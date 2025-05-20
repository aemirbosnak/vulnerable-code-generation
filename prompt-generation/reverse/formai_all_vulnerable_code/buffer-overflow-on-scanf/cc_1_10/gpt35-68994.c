//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constant Declaration
#define MAX_USERS 100
#define MAX_LENGTH 50

// Structure Declaration
struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int admin;
};

// Function Declaration
void addUser(struct User users[], int *count);
void removeUser(struct User users[], int *count);
int login(struct User users[], int count, char *username, char *password);

// Main Function
int main() {
    struct User users[MAX_USERS]; // Creating an empty array
    int count = 0; // Initializing the user count to 0
    int choice, loggedIn = 0; // Initializing the choice and loggedIn variables to 0

    // Menu Driven System
    while(1) {
        printf("==============================\n");
        printf("Welcome to the System\n");
        printf("==============================\n");

        // If the user is not logged in
        if(!loggedIn) {
            printf("Please choose an option:\n");
            printf("1. Login\n");
            printf("2. Exit\n");
            printf("Choice: ");
            scanf("%d", &choice);

            // Login Option
            if(choice == 1) {
                char username[MAX_LENGTH], password[MAX_LENGTH];
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                int isAdmin = login(users, count, username, password);
                if(isAdmin == -1) {
                    printf("Invalid username or password\n");
                } else {
                    loggedIn = 1;
                    printf("Welcome %s\n", username);
                    printf("You are %s\n", isAdmin ? "an admin" : "a normal user");
                }
            } else {
                printf("Exiting...\n");
                break;
            }
        } else {
            printf("Please choose an option:\n");
            printf("1. Add User\n");
            printf("2. Remove User\n");
            printf("3. Logout\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    addUser(users, &count);
                    break;
                case 2:
                    removeUser(users, &count);
                    break;
                case 3:
                    printf("Logging out...\n");
                    loggedIn = 0;
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
    }

    return 0;
}

// Function Definition to Add User
void addUser(struct User users[], int *count) {
    // Checking if maximum users limit is reached
    if(*count == MAX_USERS) {
        printf("Maximum Users Limit Reached\n");
        return;
    }
    // User Input
    struct User user;
    printf("Enter a username: ");
    scanf("%s", user.username);
    printf("Enter a password: ");
    scanf("%s", user.password);
    printf("Is the user an admin? (1/0): ");
    scanf("%d", &user.admin);
    // Adding User
    users[*count] = user;
    *count += 1; // Updating the count
    printf("User %s added successfully\n", user.username);
}

// Function Definition to Remove User
void removeUser(struct User users[], int *count) {
    char username[MAX_LENGTH];
    printf("Enter the username to remove: ");
    scanf("%s", username);
    // Finding User in the array
    int index = -1;
    for(int i = 0; i < *count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    // Removing User
    if(index == -1) {
        printf("User not found\n");
    } else {
        for(int i = index; i < *count - 1; i++) {
            users[i] = users[i+1];
        }
        *count -= 1; // Updating the count
        printf("User %s removed successfully\n", username);
    }
}

// Function Definition for User Login
int login(struct User users[], int count, char *username, char *password) {
    for(int i = 0; i < count; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].admin;
        }
    }
    return -1;
}