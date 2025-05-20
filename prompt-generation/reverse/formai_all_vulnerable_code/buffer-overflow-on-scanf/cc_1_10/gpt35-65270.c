//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining maximum password length */
#define MAX_PASSWORD_LENGTH 20

/* Defining maximum number of users */
#define MAX_USERS 10

/* User structure to store user credentials */
struct user {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

/* Function to get user input */
void getUserInput(char *message, char *input) {
    printf("%s", message);
    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; /* Removing trailing newline character */
}

/* Function to check if the username and password match */
int checkUserCredentials(struct user *u, char *username, char *password) {
    return !strcmp(u->username, username) && !strcmp(u->password, password);
}

int main() {
    int numUsers = 0; /* To store current number of users */
    struct user users[MAX_USERS]; /* Array of users */

    while(1) { /* Infinite loop to keep the program running */

        /* Main menu for the password manager */
        printf("Password Manager:\n");
        printf("1. Add User\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); /* Removing trailing newline character from input buffer */

        switch(choice) {
            case 1: /* Add User */
                if(numUsers < MAX_USERS) { /* Checking if the maximum number of users has been reached */
                    getUserInput("Enter username: ", users[numUsers].username);
                    getUserInput("Enter password: ", users[numUsers].password);
                    numUsers++;
                } else {
                    printf("Maximum number of users reached.\n");
                }
                break;
            
            case 2: /* Login */
                if(numUsers == 0) { /* Checking if any users have been added */
                    printf("No users added.\n");
                } else {
                    char username[MAX_PASSWORD_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    getUserInput("Enter username: ", username);
                    getUserInput("Enter password: ", password);

                    int loggedIn = 0; /* To keep track if any user is logged in */
                    for(int i = 0; i < numUsers; i++) {
                        if(checkUserCredentials(&users[i], username, password)) {
                            printf("Logged in as %s.\n", username);
                            loggedIn = 1;
                            break;
                        }
                    }
                    if(!loggedIn) {
                        printf("Invalid username or password.\n");
                    }
                }
                break;
            
            case 3: /* Exit */
                printf("Exiting...\n");
                exit(0);
                break;
            
            default: /* Invalid Choice */
                printf("Invalid choice. Try again.\n");
        }

    }
    
    return 0; /* To satisfy main function return type */
}