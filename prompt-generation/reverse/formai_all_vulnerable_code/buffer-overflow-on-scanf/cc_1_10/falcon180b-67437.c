//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords.\n");
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

    int i;
    printf("Enter password index to remove (0-%d): ", numPasswords - 1);
    scanf("%d", &i);

    if (i < 0 || i >= numPasswords) {
        printf("Invalid index.\n");
        return;
    }

    for (int j = i; j < numPasswords - 1; j++) {
        strcpy(passwords[j].username, passwords[j + 1].username);
        strcpy(passwords[j].password, passwords[j + 1].password);
    }

    numPasswords--;
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char choice;

    do {
        printf("Password Manager\n");
        printf("A - Add password\n");
        printf("R - Remove password\n");
        printf("D - Display passwords\n");
        printf("Q - Quit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                addPassword();
                break;
            case 'R':
                removePassword();
                break;
            case 'D':
                displayPasswords();
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}