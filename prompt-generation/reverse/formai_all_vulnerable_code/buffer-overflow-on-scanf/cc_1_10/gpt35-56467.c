//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
//Password management program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100 // maximum number of users
#define MAX_LEN 50 // maximum length of username and password

// structure to store user data
struct user {
    char username[MAX_LEN];
    char password[MAX_LEN];
};

int num_users = 0; // current number of users
struct user users[MAX_USERS]; // array to store all users

// function to check if a user exists
int user_exists(char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1; // user exists
        }
    }
    return 0; // user does not exist
}

// function to add a new user
void add_user() {
    // check if maximum number of users has been reached
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }

    // read in username and check if it already exists
    char username[MAX_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    if (user_exists(username)) {
        printf("Error: User already exists\n");
        return;
    }

    // read in password
    char password[MAX_LEN];
    printf("Enter password: ");
    scanf("%s", password);

    // add user to users array
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;

    printf("User added successfully\n");
}

// function to remove a user
void remove_user() {
    // read in username and check if it exists
    char username[MAX_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    int user_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user_index = i; // user found
            break;
        }
    }
    if (user_index == -1) {
        printf("Error: User not found\n");
        return;
    }

    // remove user from users array
    for (int i = user_index; i < num_users-1; i++) {
        users[i] = users[i+1];
    }
    num_users--;

    printf("User removed successfully\n");
}

// function to change a user's password
void change_password() {
    // read in username and check if it exists
    char username[MAX_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    int user_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user_index = i; // user found
            break;
        }
    }
    if (user_index == -1) {
        printf("Error: User not found\n");
        return;
    }

    // read in new password
    char new_password[MAX_LEN];
    printf("Enter new password: ");
    scanf("%s", new_password);

    // update user's password
    strcpy(users[user_index].password, new_password);

    printf("Password changed successfully\n");
}

// function to display all users
void display_users() {
    printf("Username\tPassword\n");
    printf("========================\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\t\t%s\n", users[i].username, users[i].password);
    }
}

int main() {
    int choice;
    do {
        printf("\nPassword Management Program\n");
        printf("==============================\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Change Password\n");
        printf("4. Display Users\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                display_users();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}