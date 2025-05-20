//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords!\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);

    numPasswords++;

    printf("Password added successfully!\n");
}

void listPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found!\n");
        return;
    }

    printf("Username\t\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter a username to search for: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found!\n");
}

void main() {
    printf("Welcome to the Happy Password Manager!\n\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a password\n");
        printf("2. List all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;

        case 2:
            listPasswords();
            break;

        case 3:
            searchPassword();
            break;

        case 4:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}