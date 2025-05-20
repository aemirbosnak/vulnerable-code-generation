//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[50];
} Password;

void addPassword(Password* passwords, int numPasswords, char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void removePassword(Password* passwords, int numPasswords, char* username) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            numPasswords--;
            break;
        }
    }
}

void displayPasswords(Password* passwords, int numPasswords) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, "")!= 0 && strcmp(passwords[i].password, "")!= 0) {
            printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char choice;
    do {
        printf("Password Manager\n");
        printf("1. Add Password\n2. Remove Password\n3. Display Passwords\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            char username[50];
            scanf("%s", username);

            printf("Enter password: ");
            char password[50];
            scanf("%s", password);

            addPassword(passwords, numPasswords, username, password);
            break;

        case '2':
            printf("Enter username to remove: ");
            char removeUsername[50];
            scanf("%s", removeUsername);

            removePassword(passwords, numPasswords, removeUsername);
            break;

        case '3':
            displayPasswords(passwords, numPasswords);
            break;

        case '4':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= '4');

    return 0;
}