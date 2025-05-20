//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a simple system administration tool that allows the user
 * to create and manage user accounts on a UNIX-based system.
 */

#define MAX_USERS 100
#define NAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_LOGIN_ATTEMPTS 3

// function prototypes
void displayMenu();
void createUser();
void deleteUser();
void editUser();
void displayUsers();
int getUserIndex(char name[]);
void resetPassword(char name[]);
void changePassword(char name[]);
void login();

// user structure definition
struct User {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int loginAttempts;
};

// users array and count
struct User users[MAX_USERS];
int userCount = 0;

int main() {
    int choice;

    // display menu and prompt for user input
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;

            case 2:
                deleteUser();
                break;

            case 3:
                editUser();
                break;

            case 4:
                displayUsers();
                break;

            case 5:
                resetPassword("");
                break;

            case 6:
                changePassword("");
                break;

            case 7:
                login();
                break;

            case 8:
                printf("Goodbye!\n\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

/*
 * This function displays the main menu options to the user.
 */
void displayMenu() {
    printf("*** User Administration Menu ***\n");
    printf("1. Create user\n");
    printf("2. Delete user\n");
    printf("3. Edit user\n");
    printf("4. Display users\n");
    printf("5. Reset password\n");
    printf("6. Change password\n");
    printf("7. Login\n");
    printf("8. Exit\n\n");
}

/*
 * This function allows the user to create a new user account.
 */
void createUser() {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];

    // prompt for user name and password
    printf("Enter user name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // check if user already exists
    if (getUserIndex(name) != -1) {
        printf("User already exists. Please try again.\n\n");
        return;
    }

    // add user to array
    struct User user;
    strcpy(user.name, name);
    strcpy(user.password, password);
    user.loginAttempts = 0;
    users[userCount++] = user;

    printf("User %s created.\n\n", name);
}

/*
 * This function allows the user to delete an existing user account.
 */
void deleteUser() {
    char name[NAME_LENGTH];
    int index;

    // prompt for user name
    printf("Enter user name: ");
    scanf("%s", name);

    // find user index
    index = getUserIndex(name);
    if (index == -1) {
        printf("User not found. Please try again.\n\n");
        return;
    }

    // remove user from array
    for (int i = index; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    userCount--;

    printf("User %s deleted.\n\n", name);
}

/*
 * This function allows the user to edit an existing user account.
 */
void editUser() {
    char name[NAME_LENGTH];
    int index;
    int choice;

    // prompt for user name
    printf("Enter user name: ");
    scanf("%s", name);

    // find user index
    index = getUserIndex(name);
    if (index == -1) {
        printf("User not found. Please try again.\n\n");
        return;
    }

    // display user options and prompt for choice
    printf("*** Edit User Menu ***\n");
    printf("1. Reset password\n");
    printf("2. Change password\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            resetPassword(name);
            break;

        case 2:
            changePassword(name);
            break;

        default:
            printf("Invalid choice. Please try again.\n\n");
            break;
    }
}

/*
 * This function displays a list of all user accounts.
 */
void displayUsers() {
    printf("*** User List ***\n");

    if (userCount == 0) {
        printf("No users found.\n\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        printf("%d. %s\n", i + 1, users[i].name);
    }

    printf("\n");
}

/*
 * This function returns the index of a user in the users array.
 * Returns -1 if the user is not found.
 */
int getUserIndex(char name[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * This function resets the password of an existing user account.
 */
void resetPassword(char name[]) {
    char password[PASSWORD_LENGTH];
    int index;

    // prompt for user name
    if (strcmp(name, "") == 0) {
        printf("Enter user name: ");
        scanf("%s", name);
    }

    // find user index
    index = getUserIndex(name);
    if (index == -1) {
        printf("User not found. Please try again.\n\n");
        return;
    }

    // prompt for new password
    printf("Enter new password: ");
    scanf("%s", password);

    // change password
    strcpy(users[index].password, password);

    printf("Password reset for user %s.\n\n", name);
}

/*
 * This function allows the user to change the password of an existing user account.
 */
void changePassword(char name[]) {
    char oldPassword[PASSWORD_LENGTH];
    char newPassword[PASSWORD_LENGTH];
    int index;

    // prompt for user name
    if (strcmp(name, "") == 0) {
        printf("Enter user name: ");
        scanf("%s", name);
    }

    // find user index
    index = getUserIndex(name);
    if (index == -1) {
        printf("User not found. Please try again.\n\n");
        return;
    }

    // prompt for old password
    printf("Enter old password: ");
    scanf("%s", oldPassword);

    // check if old password matches
    if (strcmp(users[index].password, oldPassword) != 0) {
        printf("Incorrect password. Please try again.\n\n");
        users[index].loginAttempts++;
        if (users[index].loginAttempts == MAX_LOGIN_ATTEMPTS) {
            printf("Account locked. Please contact administrator.\n\n");
            exit(0);
        }
        return;
    }

    // prompt for new password
    printf("Enter new password: ");
    scanf("%s", newPassword);

    // change password
    strcpy(users[index].password, newPassword);

    printf("Password changed for user %s.\n\n", name);
}

/*
 * This function simulates the login process for a user.
 */
void login() {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int index;

    // prompt for user name
    printf("Enter user name: ");
    scanf("%s", name);

    // find user index
    index = getUserIndex(name);
    if (index == -1) {
        printf("User not found. Please try again.\n\n");
        return;
    }

    // prompt for password
    printf("Enter password: ");
    scanf("%s", password);

    // check if password matches
    if (strcmp(users[index].password, password) != 0) {
        printf("Incorrect password. Please try again.\n\n");
        users[index].loginAttempts++;
        if (users[index].loginAttempts == MAX_LOGIN_ATTEMPTS) {
            printf("Account locked. Please contact administrator.\n\n");
            exit(0);
        }
        return;
    }

    printf("Welcome, %s!\n\n", name);
}