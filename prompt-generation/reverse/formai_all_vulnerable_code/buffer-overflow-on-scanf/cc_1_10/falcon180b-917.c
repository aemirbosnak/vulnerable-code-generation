//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 1000
#define PASSWORD_LENGTH 32

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user() {
    char username[50];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);

    num_users++;
}

void login() {
    char username[50];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Login failed.\n");
}

void change_password() {
    char username[50];
    char old_password[PASSWORD_LENGTH];
    char new_password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter old password: ");
    scanf("%s", old_password);

    printf("Enter new password: ");
    scanf("%s", new_password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, old_password) == 0) {
            strcpy(users[i].password, new_password);
            printf("Password changed successfully!\n");
            return;
        }
    }

    printf("Old password is incorrect.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add user\n");
        printf("2. Login\n");
        printf("3. Change password\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                login();
                break;
            case 3:
                change_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}