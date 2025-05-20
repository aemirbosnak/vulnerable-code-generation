//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_NUM_USERS 5

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_NUM_USERS];
int num_users = 0;

void printMenu() {
    printf("\nWelcome to Password Manager!\n\n");
    printf("1. Add a new user\n");
    printf("2. View all users\n");
    printf("3. Update a user's password\n");
    printf("4. Exit\n\n");
}

int validatePassword(char* password) {
    int len = strlen(password);
    if (len < 8 || len > 20) {
        return 0;
    }
    int num_digits = 0;
    int num_upper = 0;
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            return 0;
        }
        if (isdigit(password[i])) {
            num_digits++;
        }
        if (isupper(password[i])) {
            num_upper++;
        }
    }
    if (num_digits < 2 || num_upper < 1) {
        return 0;
    }
    return 1;
}

void addNewUser() {
    if (num_users >= MAX_NUM_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    struct User new_user;
    printf("Enter new username: ");
    scanf("%s", new_user.username);
    printf("Enter new password: ");
    scanf("%s", new_user.password);
    if (!validatePassword(new_user.password)) {
        printf("Invalid password. Password must be between 8 and 20 characters long, contain at least 2 digits and 1 uppercase letter.\n");
        return;
    }
    users[num_users++] = new_user;
    printf("User added successfully!\n");
}

void viewAllUsers() {
    if (num_users == 0) {
        printf("No users found.\n");
        return;
    }
    printf("All users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s: %s\n", users[i].username, users[i].password);
    }
}

int findUserIndex(char* username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void updatePassword() {
    if (num_users == 0) {
        printf("No users found.\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username of user to update: ");
    scanf("%s", username);
    int index = findUserIndex(username);
    if (index == -1) {
        printf("User not found.\n");
        return;
    }
    char new_password[MAX_PASSWORD_LENGTH];
    printf("Enter new password: ");
    scanf("%s", new_password);
    if (!validatePassword(new_password)) {
        printf("Invalid password. Password must be between 8 and 20 characters long, contain at least 2 digits and 1 uppercase letter.\n");
        return;
    }
    strcpy(users[index].password, new_password);
    printf("Password updated successfully!\n");
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addNewUser();
                break;
            case 2:
                viewAllUsers();
                break;
            case 3:
                updatePassword();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}