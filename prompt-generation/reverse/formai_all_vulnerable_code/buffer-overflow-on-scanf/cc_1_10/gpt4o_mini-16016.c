//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser(const char *username, const char *password) {
    if (userCount < MAX_USERS) {
        strncpy(users[userCount].username, username, MAX_LENGTH);
        strncpy(users[userCount].password, password, MAX_LENGTH);
        userCount++;
        printf("User %s added successfully!\n", username);
    } else {
        printf("User limit reached. Cannot add more users.\n");
    }
}

int findUser(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1; // User not found.
}

void deleteUser(const char *username) {
    int idx = findUser(username);
    if (idx != -1) {
        for (int i = idx; i < userCount - 1; i++) {
            users[i] = users[i + 1];
        }
        userCount--;
        printf("User %s deleted successfully!\n", username);
    } else {
        printf("User %s not found!\n", username);
    }
}

void changePassword(const char *username, const char *newPassword) {
    int idx = findUser(username);
    if (idx != -1) {
        strncpy(users[idx].password, newPassword, MAX_LENGTH);
        printf("Password for user %s changed successfully!\n", username);
    } else {
        printf("User %s not found!\n", username);
    }
}

void displayUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }
    printf("Registered Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s, Password: %s\n", users[i].username, users[i].password);
    }
}

void menu() {
    printf("\nPassword Management System:\n");
    printf("1. Add User\n");
    printf("2. Delete User\n");
    printf("3. Change Password\n");
    printf("4. Display Users\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char username[MAX_LENGTH], password[MAX_LENGTH];

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove trailing newline
                addUser(username, password);
                break;
            case 2:
                printf("Enter username to delete: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
                deleteUser(username);
                break;
            case 3:
                printf("Enter username to change password: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
                printf("Enter new password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove trailing newline
                changePassword(username, password);
                break;
            case 4:
                displayUsers();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}