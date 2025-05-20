//FormAI DATASET v1.0 Category: Password management ; Style: resource intensive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 10 // password length
#define MAX_USERS 100 // maximum number of users
#define MAX_ATTEMPTS 3 // maximum number of login attempts

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH+1];
} User;

int numUsers = 0;
User users[MAX_USERS]; // initialize user array with maximum size
int loggedInUser = -1; // default value for logged in user
int loginAttempts = 0; // counter for login attempts

void addNewUser() {
    if (numUsers == MAX_USERS) { // if user array is full
        printf("Maximum number of users reached. Cannot add new user.\n");
        return;
    }

    // prompt user to enter new username and password
    char newUserName[50], newPassword[PASSWORD_LENGTH+1];
    printf("Enter new username: ");
    scanf("%s", newUserName);

    for (int i = 0; i < numUsers; i++) { // check if username already exists
        if (strcmp(users[i].username, newUserName) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter new password: ");
    scanf("%s", newPassword);

    // add new user to user array
    strcpy(users[numUsers].username, newUserName);
    strcpy(users[numUsers].password, newPassword);
    numUsers++;
    printf("New user added successfully.\n");
}

void loginUser() {
    if (loggedInUser != -1) { // if already logged in
        printf("You are already logged in.\n");
        return;
    }

    if (loginAttempts == MAX_ATTEMPTS) { // if maximum login attempts reached
        printf("Maximum login attempts reached. Please try again later.\n");
        return;
    }

    // prompt user to enter username and password
    char username[50], password[PASSWORD_LENGTH+1];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) { // search for user with matching username
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) { // if password matches
                loggedInUser = i; // set user as logged in
                loginAttempts = 0; // reset login attempts
                printf("Login successful. Welcome %s!\n", username);
                return;
            } else {
                printf("Incorrect password. Please try again.\n");
                loginAttempts++;
                loginUser();
            }
        }
    }

    printf("Username not found. Please try again.\n");
    loginAttempts++;
    loginUser();
}

void changePassword() {
    if (loggedInUser == -1) { // if not logged in
        printf("You must be logged in to change your password.\n");
        return;
    }

    char currentPassword[PASSWORD_LENGTH+1], newPassword[PASSWORD_LENGTH+1], retypeNewPassword[PASSWORD_LENGTH+1];
    printf("Enter current password: ");
    scanf("%s", currentPassword);

    if (strcmp(users[loggedInUser].password, currentPassword) != 0) { // if current password is incorrect
        printf("Incorrect password. Please try again.\n");
        changePassword();
    }

    printf("Enter new password: ");
    scanf("%s", newPassword);

    printf("Retype new password: ");
    scanf("%s", retypeNewPassword);

    if (strcmp(newPassword, retypeNewPassword) != 0) { // if new passwords don't match
        printf("Passwords do not match. Please try again.\n");
        changePassword();
    }

    // update password
    strcpy(users[loggedInUser].password, newPassword);
    printf("Password changed successfully.\n");
}

int main() {
    int choice;
    printf("Welcome to Password Management System\n\n");

    while (1) {
        printf("Select an option:\n1. Add new user\n2. Login\n3. Change password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                printf("Thank you for using Password Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}