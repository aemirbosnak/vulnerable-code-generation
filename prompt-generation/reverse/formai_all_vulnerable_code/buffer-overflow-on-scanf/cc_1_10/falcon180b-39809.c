//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password *newPassword = &passwords[numPasswords];
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);

    numPasswords++;
}

void printPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void deletePassword(char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            numPasswords--;

            return;
        }
    }

    printf("Error: Password not found.\n");
}

void changePassword(char *username, char *newPassword) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].password);
            passwords[i].password = strdup(newPassword);

            printf("Password changed successfully.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

int main() {
    char *username;
    char *password;

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        addPassword(username, password);
    }

    return 0;
}