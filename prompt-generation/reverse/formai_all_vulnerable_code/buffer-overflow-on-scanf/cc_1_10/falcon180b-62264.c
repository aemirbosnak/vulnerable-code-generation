//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);
    passwords[numPasswords].length = strlen(password);

    numPasswords++;
}

void displayPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s (%d characters)\n", passwords[i].username, passwords[i].length);
    }
}

void generatePassword(char *username, int length) {
    char password[MAX_PASSWORD_LENGTH];
    int i = 0;

    // Add lowercase letters
    for (i = 0; i < length / 4; i++) {
        password[i] = 'a' + rand() % 26;
    }

    // Add uppercase letters
    for (i = length / 4; i < length / 2; i++) {
        password[i] = 'A' + rand() % 26;
    }

    // Add numbers
    for (i = length / 2; i < 3 * length / 4; i++) {
        password[i] = '0' + rand() % 10;
    }

    // Add special characters
    for (i = 3 * length / 4; i < length; i++) {
        password[i] = "!@#$%^&*()_+-=[]{}|;:,.<>?"[rand() % 32];
    }

    password[length] = '\0';

    addPassword(username, password);
    printf("Generated password for %s: %s\n", username, password);
}

int main() {
    char username[50];
    int length;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter the desired password length (between 8 and 50): ");
    scanf("%d", &length);

    if (length < 8 || length > 50) {
        printf("Error: Invalid password length.\n");
        return 1;
    }

    generatePassword(username, length);

    displayPasswords();

    return 0;
}