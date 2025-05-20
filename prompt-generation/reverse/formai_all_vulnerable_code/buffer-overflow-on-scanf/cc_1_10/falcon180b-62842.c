//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username:\n");
    scanf("%s", username);

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter the website or service name:\n");
        scanf("%s", password);

        int passwordLength = strlen(password);
        if (passwordLength < 1 || passwordLength > MAX_PASSWORD_LENGTH) {
            printf("Invalid password length.\n");
        } else {
            generatePassword(password, passwordLength);
            strcpy(passwords[numPasswords].username, username);
            strcpy(passwords[numPasswords].password, password);
            numPasswords++;
        }
    }

    printf("Your passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}