//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

int addUser(const char* username, const char* password);
int verifyUser(const char* username, const char* password);
void changePassword(const char* username, const char* newPassword);

int main() {
    int choice;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("1) Add user\n");
        printf("2) Verify user\n");
        printf("3) Change password\n");
        printf("4) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int result = addUser(username, password);
                if (result == 0) {
                    printf("User added successfully.\n");
                } else {
                    printf("Failed to add user. Please try again later.\n");
                }
                break;
            }
            case 2: {
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int result = verifyUser(username, password);
                if (result == 1) {
                    printf("User verified successfully.\n");
                } else {
                    printf("Incorrect username or password.\n");
                }
                break;
            }
            case 3: {
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter new password: ");
                scanf("%s", newPassword);
                changePassword(username, newPassword);
                printf("Password changed successfully.\n");
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}

int addUser(const char* username, const char* password) {
    if (num_users == MAX_USERS) {
        return -1;
    }
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;
    return 0;
}

int verifyUser(const char* username, const char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0
            && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void changePassword(const char* username, const char* newPassword) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].password, newPassword);
            return;
        }
    }
    // If the username doesn't exist, do nothing.
}