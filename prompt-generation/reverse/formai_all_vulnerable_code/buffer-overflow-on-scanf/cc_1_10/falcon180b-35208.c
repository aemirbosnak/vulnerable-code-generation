//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void removePassword() {
    if (numPasswords == 0) {
        printf("No passwords to remove.\n");
        return;
    }

    printf("Enter username to remove: ");
    scanf("%s", passwords[0].username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            memset(passwords[i].username, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            numPasswords--;
            break;
        }
    }

    if (i == numPasswords) {
        printf("Username not found.\n");
    }
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords to view.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\n1. Add Password\n2. Remove Password\n3. View Passwords\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            removePassword();
            break;
        case 3:
            viewPasswords();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}