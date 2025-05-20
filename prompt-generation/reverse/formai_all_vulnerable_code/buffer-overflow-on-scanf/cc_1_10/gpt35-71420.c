//FormAI DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LEN 20         // maximum password length
#define MAX_NUM_OF_USERS 10     // maximum number of users

// data structure to hold a user's information
typedef struct {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
} User;

// global variables
User users[MAX_NUM_OF_USERS];   // array of users
int num_of_users = 0;           // number of registered users

// function to register a new user
void register_user() {
    // check if we have reached the maximum number of users
    if (num_of_users == MAX_NUM_OF_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    // prompt user for username and password
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
    printf("Enter a username:\n");
    scanf("%s", username);
    printf("Enter a password (maximum %d characters):\n", MAX_PASS_LEN);
    scanf("%s", password);
    
    // check if the username already exists
    for (int i = 0; i < num_of_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }
    
    // add the user to the list of registered users
    strcpy(users[num_of_users].username, username);
    strcpy(users[num_of_users].password, password);
    num_of_users++;
    
    printf("User registration successful.\n");
}

// function to authenticate a user
void authenticate_user() {
    // prompt user for username and password
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
    printf("Enter your username:\n");
    scanf("%s", username);
    printf("Enter your password:\n");
    scanf("%s", password);
    
    // check if the username and password match a registered user
    for (int i = 0; i < num_of_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Authentication successful.\n");
            return;
        }
    }
    
    printf("Incorrect username or password.\n");
}

// main function
int main() {
    // print instructions
    printf("Welcome to the password management system.\n");
    printf("Enter 'register' to register a new user.\n");
    printf("Enter 'authenticate' to authenticate a user.\n");
    printf("Enter 'exit' to exit the program.\n");
    
    // loop to process user input
    while (1) {
        // prompt user for input
        char input[MAX_PASS_LEN];
        printf("Enter a command:\n");
        scanf("%s", input);
        
        // check if user wants to register a new user
        if (strcmp(input, "register") == 0) {
            register_user();
        }
        // check if user wants to authenticate a user
        else if (strcmp(input, "authenticate") == 0) {
            authenticate_user();
        }
        // check if user wants to exit the program
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }
        // handle invalid input
        else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}