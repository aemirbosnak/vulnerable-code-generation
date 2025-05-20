//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords to delete.\n");
        return;
    }

    printf("Enter username to delete: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            memset(&passwords[i], 0, sizeof(Password));
            numPasswords--;
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void searchPassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords to search.\n");
        return;
    }

    printf("Enter username to search: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Error: Password not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Search Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            deletePassword();
            break;
        case 3:
            searchPassword();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}