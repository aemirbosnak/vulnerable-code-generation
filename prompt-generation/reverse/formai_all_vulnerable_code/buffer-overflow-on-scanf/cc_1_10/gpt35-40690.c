//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LEN 20

struct user {
    char username[20];
    char password[MAX_PASSWORD_LEN];
};

struct user database[MAX_USERS];

void add_user() {
    char username[20];
    char password[MAX_PASSWORD_LEN];
    printf("Enter new username: ");
    scanf("%s", username);
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(database[i].username, username) == 0) {
            printf("Username already exists!\n");
            return;
        }
    }
    printf("Enter new password: ");
    scanf("%s", password);
    if (strlen(password) > MAX_PASSWORD_LEN) {
        printf("Error: Password too long.\n");
        return;
    }
    for (int i = 0; i < MAX_USERS; i++) {
        if (strlen(database[i].username) == 0) {
            strcpy(database[i].username, username);
            strcpy(database[i].password, password);
            printf("User %s added successfully.\n", username);
            return;
        }
    }
    printf("Error: Too many users.\n");
}

void remove_user() {
    char username[20];
    printf("Enter username to remove: ");
    scanf("%s", username);
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(database[i].username, username) == 0) {
            memset(&database[i], 0, sizeof(struct user));
            printf("User %s removed successfully.\n", username);
            return;
        }
    }
    printf("Error: User not found.\n");
}

void change_password() {
    char username[20];
    char old_password[MAX_PASSWORD_LEN];
    char new_password[MAX_PASSWORD_LEN];
    printf("Enter username to change password: ");
    scanf("%s", username);
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(database[i].username, username) == 0) {
            printf("Enter old password: ");
            scanf("%s", old_password);
            if (strcmp(database[i].password, old_password) == 0) {
                printf("Enter new password: ");
                scanf("%s", new_password);
                if (strlen(new_password) > MAX_PASSWORD_LEN) {
                    printf("Error: Password too long.\n");
                    return;
                }
                strcpy(database[i].password, new_password);
                printf("Password changed successfully for user %s.\n", username);
                return;
            } else {
                printf("Error: Incorrect password.\n");
                return;
            }
        }
    }
    printf("Error: User not found.\n");
}

int main() {
    char choice;
    memset(database, 0, sizeof(database));
    while(1) {
        printf("Password management menu:\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Change password\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                add_user();
                break;
            case '2':
                remove_user();
                break;
            case '3':
                change_password();
                break;
            case '4':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}