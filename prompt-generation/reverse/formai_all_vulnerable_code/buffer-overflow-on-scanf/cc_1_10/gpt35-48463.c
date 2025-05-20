//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NUM_PASSWORDS 100

typedef struct Password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int menu();
void addPassword(Password passwords[], int *count);
void viewPasswords(Password passwords[], int count);
void searchPasswords(Password passwords[], int count);

int main() {
    Password passwords[MAX_NUM_PASSWORDS];
    int count = 0;
    int choice = 0;

    while (choice != 4) {
        choice = menu();

        switch (choice) {
            case 1:
                addPassword(passwords, &count);
                break;
            case 2:
                viewPasswords(passwords, count);
                break;
            case 3:
                searchPasswords(passwords, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

int menu() {
    int choice;
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void addPassword(Password passwords[], int *count) {
    if (*count >= MAX_NUM_PASSWORDS) {
        printf("Cannot add password, maximum number of passwords reached.\n");
        return;
    }

    Password password;

    printf("Enter username (20 characters or less): ");
    scanf("%s", password.username);

    printf("Enter password (20 characters or less): ");
    scanf("%s", password.password);

    passwords[*count] = password;
    (*count)++;

    printf("Password added successfully!\n");
}

void viewPasswords(Password passwords[], int count) {
    if (count == 0) {
        printf("No passwords to display.\n");
        return;
    }

    printf("Passwords:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. Username: %s, Password: %s\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

void searchPasswords(Password passwords[], int count) {
    if (count == 0) {
        printf("No passwords to search.\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to search for: ");
    scanf("%s", username);

    for (int i = 0; i < count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password found! Username: %s, Password: %s\n", passwords[i].username, passwords[i].password);
            return;
        }
    }

    printf("Password not found for username: %s\n", username);
}