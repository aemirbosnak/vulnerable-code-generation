//GEMINI-pro DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 256

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    bool is_admin;
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password, bool is_admin) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].is_admin = is_admin;
    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    if (i >= num_passwords) {
        printf("Error: Password not found.\n");
        return;
    }

    for (; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    num_passwords--;

    printf("Password removed successfully.\n");
}

void print_passwords() {
    int i;

    printf("Passwords:\n");

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char input[MAX_PASSWORD_LENGTH];
    int choice;
    bool is_admin = false;

    printf("Welcome to the Password Management System!\n");
    printf("Please enter your username:\n");
    scanf("%s", input);

    printf("Please enter your password:\n");
    scanf("%s", input);

    if (strcmp(input, "admin") == 0) {
        is_admin = true;
    } else {
        printf("Error: Invalid username or password.\n");
        return 1;
    }

    while (true) {
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. Print passwords\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter the username:\n");
                scanf("%s", input);
                printf("Please enter the password:\n");
                scanf("%s", input);
                printf("Is this user an admin? (y/n)\n");
                scanf("%s", input);
                if (strcmp(input, "y") == 0) {
                    add_password(input, input, true);
                } else {
                    add_password(input, input, false);
                }
                break;
            case 2:
                printf("Please enter the username:\n");
                scanf("%s", input);
                remove_password(input);
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}