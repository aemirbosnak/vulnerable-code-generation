//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);
void print_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords);
void remove_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);
void change_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    int choice;
    char c;

    do {
        printf("\n\nPassword Management System\n\n");
        printf("1. Add a password\n");
        printf("2. Print all passwords\n");
        printf("3. Remove a password\n");
        printf("4. Change a password\n");
        printf("5. Exit\n");

        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                print_passwords(passwords, num_passwords);
                break;
            case 3:
                remove_password(passwords, &num_passwords);
                break;
            case 4:
                change_password(passwords, num_passwords);
                break;
            case 5:
                printf("\nThank you for using the Password Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char new_password[MAX_PASSWORD_LENGTH];
    int i;

    printf("\nEnter the new password: ");
    fgets(new_password, MAX_PASSWORD_LENGTH, stdin);

    for (i = 0; new_password[i] != '\0'; i++) {
        if (isspace(new_password[i])) {
            printf("\nInvalid password. Password cannot contain spaces.\n");
            return;
        }
    }

    if (*num_passwords >= MAX_PASSWORDS) {
        printf("\nPassword database full. Cannot add new password.\n");
        return;
    }

    strncpy(passwords[*num_passwords], new_password, MAX_PASSWORD_LENGTH);
    (*num_passwords)++;
    printf("\nNew password added to database.\n");
}

void print_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords) {
    int i;

    printf("\nPassword database:\n\n");

    for (i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }
}

void remove_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char password[MAX_PASSWORD_LENGTH];
    int i, j;

    printf("\nEnter the password you want to remove: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    for (i = 0; password[i] != '\0'; i++) {
        if (isspace(password[i])) {
            printf("\nInvalid password. Password cannot contain spaces.\n");
            return;
        }
    }

    for (i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            for (j = i; j < *num_passwords - 1; j++) {
                strncpy(passwords[j], passwords[j + 1], MAX_PASSWORD_LENGTH);
            }
            (*num_passwords)--;
            printf("\nPassword removed from database.\n");
            return;
        }
    }

    printf("\nPassword not found in database.\n");
}

void change_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords) {
    char old_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    int i;

    printf("\nEnter the old password: ");
    fgets(old_password, MAX_PASSWORD_LENGTH, stdin);

    for (i = 0; old_password[i] != '\0'; i++) {
        if (isspace(old_password[i])) {
            printf("\nInvalid password. Password cannot contain spaces.\n");
            return;
        }
    }

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i], old_password) == 0) {
            printf("\nEnter the new password: ");
            fgets(new_password, MAX_PASSWORD_LENGTH, stdin);

            for (i = 0; new_password[i] != '\0'; i++) {
                if (isspace(new_password[i])) {
                    printf("\nInvalid password. Password cannot contain spaces.\n");
                    return;
                }
            }

            strncpy(passwords[i], new_password, MAX_PASSWORD_LENGTH);
            printf("\nPassword changed.\n");
            return;
        }
    }

    printf("\nOld password not found in database.\n");
}