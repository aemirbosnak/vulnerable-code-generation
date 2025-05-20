//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char *username, const char *password) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    strncpy(users[user_count].username, username, sizeof(users[user_count].username) - 1);
    strncpy(users[user_count].password, password, PASSWORD_LENGTH - 1);
    user_count++;
    printf("User %s added successfully.\n", username);
}

int authenticate_user(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

void change_password(const char *username, const char *new_password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strncpy(users[i].password, new_password, PASSWORD_LENGTH - 1);
            printf("Password changed successfully for user %s.\n", username);
            return;
        }
    }
    printf("User %s not found.\n", username);
}

void list_users() {
    if (user_count == 0) {
        printf("No users found.\n");
        return;
    }
    printf("Current users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("- %s\n", users[i].username);
    }
}

void display_menu() {
    printf("\nPassword Management System\n");
    printf("1. Add User\n");
    printf("2. Authenticate User\n");
    printf("3. Change Password\n");
    printf("4. List Users\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char username[50];
    char password[PASSWORD_LENGTH];
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                add_user(username, password);
                break;

            case 2:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                if (authenticate_user(username, password)) {
                    printf("Authentication successful for user %s.\n", username);
                } else {
                    printf("Authentication failed for user %s.\n", username);
                }
                break;

            case 3:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                printf("Enter new password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                change_password(username, password);
                break;

            case 4:
                list_users();
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}