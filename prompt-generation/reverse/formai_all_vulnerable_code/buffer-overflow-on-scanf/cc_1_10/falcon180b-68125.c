//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void removePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    int index;
    printf("Enter index of password to remove: ");
    scanf("%d", &index);

    if (index >= numPasswords || index < 0) {
        printf("Error: Invalid index.\n");
        return;
    }

    memmove(&passwords[index], &passwords[index + 1], sizeof(Password) * (numPasswords - index - 1));
    numPasswords--;
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("%s -> %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Display passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            addPassword();
            break;
        case '2':
            removePassword();
            break;
        case '3':
            displayPasswords();
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}