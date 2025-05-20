//Code Llama-13B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 16

void print_menu();
int create_password();
int enter_password();
int compare_passwords(char *, char *);
void reset_password();

int main() {
    int choice;
    char password[MAX_PASSWORD_LENGTH];

    print_menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_password();
                break;
            case 2:
                enter_password();
                break;
            case 3:
                reset_password();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("Welcome to the Password Management System\n");
    printf("1. Create a new password\n");
    printf("2. Enter an existing password\n");
    printf("3. Reset a password\n");
    printf("4. Exit\n");
}

int create_password() {
    char password[MAX_PASSWORD_LENGTH];
    int i;

    printf("Enter a new password: ");
    scanf("%s", password);

    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            printf("Password must contain only alphanumeric characters.\n");
            return 1;
        }
    }

    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 1;
    }

    printf("Password created successfully.\n");
    return 0;
}

int enter_password() {
    char password[MAX_PASSWORD_LENGTH];
    char input[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", input);

    if (strcmp(password, input) == 0) {
        printf("Password correct.\n");
        return 0;
    } else {
        printf("Incorrect password.\n");
        return 1;
    }
}

int compare_passwords(char *password1, char *password2) {
    return strcmp(password1, password2);
}

void reset_password() {
    char password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    int i;

    printf("Enter your current password: ");
    scanf("%s", password);

    if (compare_passwords(password, "password") == 0) {
        printf("Enter a new password: ");
        scanf("%s", new_password);

        for (i = 0; i < strlen(new_password); i++) {
            if (!isalnum(new_password[i])) {
                printf("Password must contain only alphanumeric characters.\n");
                return;
            }
        }

        if (strlen(new_password) < 8) {
            printf("Password must be at least 8 characters long.\n");
            return;
        }

        strcpy(password, new_password);
        printf("Password reset successfully.\n");
    } else {
        printf("Incorrect password.\n");
    }
}