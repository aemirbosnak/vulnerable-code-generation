//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
    printf("Password added successfully.\n");
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, '\0', MAX_PASSWORD_LENGTH);
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("Error: Username not found.\n");
}

void searchPassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    printf("Enter username to search: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Error: Username not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
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
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}