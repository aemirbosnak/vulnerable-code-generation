//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} Password;

void generatePassword(char password[PASSWORD_LENGTH]) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$%^&*()_+";
    int randomIndex;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        randomIndex = rand() % strlen(charset);
        password[i] = charset[randomIndex];
    }
}

void addPassword(Password passwords[MAX_PASSWORDS], int numPasswords, char username[50], char password[PASSWORD_LENGTH]) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].password, password);
            return;
        }
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void printPasswords(Password passwords[MAX_PASSWORDS], int numPasswords) {
    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[50];
    char password[PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    generatePassword(passwords[numPasswords].password);
    strcpy(passwords[numPasswords].username, username);

    addPassword(passwords, numPasswords, username, password);

    printf("Your password has been saved.\n");

    printPasswords(passwords, numPasswords);
}