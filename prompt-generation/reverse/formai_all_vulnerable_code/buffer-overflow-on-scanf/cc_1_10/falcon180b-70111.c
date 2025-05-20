//Falcon-180B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter name for password: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void viewPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void deletePassword() {
    printf("Enter name of password to delete: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(name, passwords[i].name) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            numPasswords--;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void main() {
    printf("Password Manager\n");
    printf("----------------\n");

    while (1) {
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;

        case 2:
            viewPasswords();
            break;

        case 3:
            deletePassword();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}