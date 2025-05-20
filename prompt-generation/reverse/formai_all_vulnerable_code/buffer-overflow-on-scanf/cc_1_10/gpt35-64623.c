//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 20
#define MAX_NAME_LENGTH 30
#define MAX_USERS 10

/* A structure for holding user data */
struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
};

/* Function prototypes */
int menu();
int login(struct User *users, int num_users);
void add_user(struct User *users, int *num_users);
void change_password(struct User *users, int num_users, char *username);

int main() {
    struct User users[MAX_USERS];
    int num_users = 0;
    int choice;
    int logged_in = 0;
    char current_user[MAX_NAME_LENGTH];
    
    while(1) {
        choice = menu();
        
        switch(choice) {
            case 1:
                logged_in = login(users, num_users);
                if(logged_in) {
                    strncpy(current_user, users[logged_in - 1].username, MAX_NAME_LENGTH);
                    printf("\nWelcome, %s!\n\n", current_user);
                }
                break;
            case 2:
                if(logged_in) {
                    change_password(users, num_users, current_user);
                } else {
                    printf("\nYou must be logged in to change your password.\n\n");
                }
                break;
            case 3:
                if(logged_in) {
                    printf("\nGoodbye, %s!\n\n", current_user);
                    logged_in = 0;
                } else {
                    printf("\nYou must be logged in to log out.\n\n");
                }
                break;
            case 4:
                add_user(users, &num_users);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}

/* Displays the menu and returns the user's choice */
int menu() {
    int choice;
    
    printf("Menu:\n");
    printf("----\n");
    printf("1. Login\n");
    printf("2. Change Password\n");
    printf("3. Logout\n");
    printf("4. Add User\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character
    
    return choice;
}

/* Prompts the user for their username and password and returns their index in the users array if valid, otherwise returns 0 */
int login(struct User *users, int num_users) {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
    
    printf("\nPlease enter your username: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    printf("Please enter your password: ");
    fgets(password, MAX_PASS_LENGTH, stdin);
    
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i + 1; // Return the user index plus 1 to signify a successful login
        }
    }
    
    printf("\nIncorrect username or password. Please try again.\n\n");
    return 0;
}

/* Prompts the admin to add a new user */
void add_user(struct User *users, int *num_users) {
    if(*num_users >= MAX_USERS) {
        printf("\nMaximum number of users has been reached.\n\n");
        return;
    }
    
    printf("\nAdding new user:\n");
    printf("-----------------\n");
    printf("Username (max %d characters): ", MAX_NAME_LENGTH);
    fgets(users[*num_users].username, MAX_NAME_LENGTH, stdin);
    printf("Password (max %d characters): ", MAX_PASS_LENGTH);
    fgets(users[*num_users].password, MAX_PASS_LENGTH, stdin);
    
    (*num_users)++;
    
    printf("\nUser has been added.\n\n");
}

/* Prompts the user to change their password */
void change_password(struct User *users, int num_users, char *username) {
    char password[MAX_PASS_LENGTH];
    
    printf("\nHello, %s.\n", username);
    printf("Please enter your new password (max %d characters): ", MAX_PASS_LENGTH);
    fgets(password, MAX_PASS_LENGTH, stdin);
    
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            strncpy(users[i].password, password, MAX_PASS_LENGTH);
            printf("\nPassword has been changed.\n\n");
            return;
        }
    }
    
    printf("\nError: user not found.\n\n");
}