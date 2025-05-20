//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(Password* password) {
    const char* charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    char buffer[MAX_PASSWORD_LENGTH];
    int length = rand() % 10 + 8; // Password length between 8 and 18 characters

    for (int i = 0; i < length; i++) {
        buffer[i] = charset[rand() % strlen(charset)];
    }

    strcpy(password->password, buffer);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Enter a master password: ");
    char masterPassword[MAX_PASSWORD_LENGTH];
    scanf("%s", masterPassword);

    while (1) {
        printf("Enter a website or username: ");
        char input[MAX_USERNAME_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(passwords[i].username, input) == 0) {
                printf("Password for %s: %s\n", input, passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Enter a new password for %s: ", input);
            char newPassword[MAX_PASSWORD_LENGTH];
            scanf("%s", newPassword);

            generatePassword(&passwords[numPasswords]);
            strcpy(passwords[numPasswords].username, input);
            strcpy(passwords[numPasswords].password, newPassword);

            numPasswords++;
        }
    }

    return 0;
}