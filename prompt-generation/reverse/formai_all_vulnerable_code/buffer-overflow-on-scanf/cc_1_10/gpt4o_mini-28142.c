//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 5
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isLoggedIn;
} User;

User users[MAX_USERS] = {
    {"admin", "admin123", 0},
    {"user1", "password1", 0},
    {"user2", "password2", 0},
    {"user3", "password3", 0},
    {"user4", "password4", 0}
};

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void printWelcome() {
    printf("**************************\n");
    printf("* Welcome to Retro OS!    *\n");
    printf("**************************\n");
}

int checkCredentials(const char *username, const char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            return i; // return index of user
        }
    }
    return -1; // user not found
}

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    int userIndex = checkCredentials(username, password);
    if (userIndex != -1) {
        printf("Login Successful! Welcome, %s.\n", username);
        users[userIndex].isLoggedIn = 1;
    } else {
        printf("Login Failed! Incorrect username or password.\n");
    }
}

void printLoggedInUsers() {
    printf("Currently Logged In Users:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].isLoggedIn) {
            printf(" - %s\n", users[i].username);
        }
    }
}

void logout() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username to logout: ");
    scanf("%s", username);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].isLoggedIn = 0;
            printf("%s has logged out successfully.\n", username);
            return;
        }
    }
    printf("User not found.\n");
}

void changePassword() {
    char username[MAX_USERNAME_LENGTH];
    char oldPassword[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your old password: ");
    scanf("%s", oldPassword);
    printf("Enter your new password: ");
    scanf("%s", newPassword);

    int userIndex = checkCredentials(username, oldPassword);
    if (userIndex != -1) {
        strcpy(users[userIndex].password, newPassword);
        printf("Password changed successfully for user %s.\n", username);
    } else {
        printf("Error: Incorrect username or old password.\n");
    }
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Login\n");
    printf("2. Logout\n");
    printf("3. Change Password\n");
    printf("4. Show Logged In Users\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    clearScreen();
    printWelcome();

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                logout();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                printLoggedInUsers();
                break;
            case 5:
                printf("Exiting Retro OS. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}