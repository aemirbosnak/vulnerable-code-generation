//Falcon-180B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void removePassword(char* username) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, 0, strlen(passwords[i].password));
            numPasswords--;
            i--;
        }
    }
}

void printPasswords() {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("Password Manager\n");
        printf("1. Add Password\n2. Remove Password\n3. Print Passwords\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(username, password);
            break;
        case '2':
            printf("Enter username: ");
            scanf("%s", username);
            removePassword(username);
            break;
        case '3':
            printPasswords();
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