//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 30

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charsetLength = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (1) {
        printf("Enter a new username (or type 'exit'): ");
        scanf("%s", passwords[numPasswords].username);

        if (strcmp(passwords[numPasswords].username, "exit") == 0) {
            break;
        }

        printf("Enter the password length (between 8 and 30 characters): ");
        int length;
        scanf("%d", &length);

        if (length < 8 || length > 30) {
            printf("Invalid password length.\n");
            continue;
        }

        generatePassword(passwords[numPasswords].password, length);

        numPasswords++;
    }

    printf("Passwords saved:\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}