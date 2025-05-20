//Falcon-180B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void addPassword(Password *passwords, int numPasswords, char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void deletePassword(Password *passwords, int numPasswords, char *username) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, 0, strlen(passwords[i].password));
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void displayPasswords(Password *passwords, int numPasswords) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("1. Add Password\n2. Delete Password\n3. Display Passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(passwords, numPasswords, username, password);
            break;

        case '2':
            printf("Enter username: ");
            scanf("%s", username);
            deletePassword(passwords, numPasswords, username);
            break;

        case '3':
            if (numPasswords == 0) {
                printf("No passwords found.\n");
            } else {
                displayPasswords(passwords, numPasswords);
            }
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}