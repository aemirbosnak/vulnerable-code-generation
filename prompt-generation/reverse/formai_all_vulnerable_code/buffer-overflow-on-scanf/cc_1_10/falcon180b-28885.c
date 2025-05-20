//Falcon-180B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("User already exists.\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter a username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i + 1], sizeof(password_t) * (num_passwords - i - 1));
            num_passwords--;
            printf("User removed.\n");
            return;
        }
    }

    printf("User not found.\n");
}

void change_password() {
    char old_username[MAX_PASSWORD_LENGTH];
    char new_username[MAX_PASSWORD_LENGTH];
    char old_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    printf("Enter the old username: ");
    scanf("%s", old_username);

    printf("Enter the new username: ");
    scanf("%s", new_username);

    printf("Enter the old password: ");
    scanf("%s", old_password);

    printf("Enter the new password: ");
    scanf("%s", new_password);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, old_username) == 0 && strcmp(passwords[i].password, old_password) == 0) {
            strcpy(passwords[i].username, new_username);
            strcpy(passwords[i].password, new_password);
            printf("Password changed.\n");
            return;
        }
    }

    printf("User not found or incorrect password.\n");
}

void display_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n2. Remove password\n3. Change password\n4. Display passwords\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                change_password();
                break;
            case 4:
                display_passwords();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}