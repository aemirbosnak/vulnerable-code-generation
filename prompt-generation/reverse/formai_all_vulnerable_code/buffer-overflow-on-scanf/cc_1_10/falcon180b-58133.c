//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
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

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

int addPassword() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;

    return 0;
}

int removePassword() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter a username to remove: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i + 1], (numPasswords - i - 1) * sizeof(Password));
            numPasswords--;
            break;
        }
    }

    return 0;
}

int viewPasswords() {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}

int main() {
    int choice;

    while (1) {
        printf("1. Add password\n2. Remove password\n3. View passwords\n4. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}