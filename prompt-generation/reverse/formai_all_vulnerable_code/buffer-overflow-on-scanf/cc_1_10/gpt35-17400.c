//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASS_LENGTH 20
#define MAX_TRIES 3

typedef struct {
    char username[20];
    char password[MAX_PASS_LENGTH + 1];
} User;

User users[MAX_USERS];
int num_users = 0;

int login_attempts[MAX_USERS];

void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User user;
    printf("Enter a username: ");
    scanf("%s", user.username);
    printf("Enter a password (maximum length %d): ", MAX_PASS_LENGTH);
    scanf("%s", user.password);

    users[num_users++] = user;

    printf("User created successfully!\n");
}

int find_user(char* username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void change_password() {
    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);

    int user_index = find_user(username);
    if (user_index == -1) {
        printf("User not found.\n");
        return;
    }

    char old_password[MAX_PASS_LENGTH + 1];
    printf("Enter your old password: ");
    scanf("%s", old_password);

    if (strcmp(users[user_index].password, old_password) != 0) {
        printf("Incorrect password.\n");
        login_attempts[user_index]++;
        if (login_attempts[user_index] >= MAX_TRIES) {
            printf("Too many login attempts. Account is locked.\n");
            exit(0);
        }
        return;
    }

    char new_password[MAX_PASS_LENGTH + 1];
    printf("Enter your new password (maximum length %d): ", MAX_PASS_LENGTH);
    scanf("%s", new_password);

    strncpy(users[user_index].password, new_password, MAX_PASS_LENGTH);
    printf("Password changed successfully!\n");
}

int main() {
    int choice;
    do {
        printf("Password Management System\n");
        printf("--------------------------\n");
        printf("1. Create user\n");
        printf("2. Change password\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                change_password();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}