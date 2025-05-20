//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char* username;
    char* password;
} Password;

void addPassword(Password* passwords, int numPasswords, char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    Password newPassword;
    strcpy(newPassword.username, username);
    strcpy(newPassword.password, password);

    passwords[numPasswords] = newPassword;
    numPasswords++;
}

int authenticate(Password* passwords, int numPasswords, char* username, char* password) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            if (strcmp(passwords[i].password, password) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

void printPasswords(Password* passwords, int numPasswords) {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char* username;
    char* password;

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        addPassword(passwords, numPasswords, username, password);

        if (numPasswords == 0) {
            printf("No passwords found.\n");
        } else {
            printPasswords(passwords, numPasswords);
        }
    }

    return 0;
}