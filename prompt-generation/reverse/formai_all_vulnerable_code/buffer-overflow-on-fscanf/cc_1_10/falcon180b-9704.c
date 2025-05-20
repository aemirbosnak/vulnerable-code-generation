//Falcon-180B DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
};

void generatePassword(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charsetLength = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    password[length] = '\0';
}

void savePassword(struct Password *password) {
    FILE *file = fopen("passwords.txt", "a");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fprintf(file, "%s:%s\n", password->username, password->password);

    fclose(file);
}

void loadPasswords(struct Password passwords[MAX_PASSWORDS]) {
    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int numPasswords = 0;

    while (fscanf(file, "%s:%s\n", passwords[numPasswords].username, passwords[numPasswords].password) == 2) {
        numPasswords++;
    }

    fclose(file);
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    loadPasswords(passwords);

    while (1) {
        printf("Enter username: ");
        scanf("%s", passwords[numPasswords].username);

        if (numPasswords >= MAX_PASSWORDS) {
            printf("Error: Maximum number of passwords reached.\n");
            break;
        }

        int passwordLength = rand() % MAX_PASSWORD_LENGTH + 8;
        generatePassword(passwords[numPasswords].password, passwordLength);

        printf("Password generated: %s\n", passwords[numPasswords].password);

        savePassword(&passwords[numPasswords]);

        numPasswords++;
    }

    return 0;
}