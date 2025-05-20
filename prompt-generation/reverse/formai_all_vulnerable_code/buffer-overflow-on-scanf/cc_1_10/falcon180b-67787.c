//Falcon-180B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

void savePasswords(Password *passwords, int numPasswords) {
    FILE *file = fopen("passwords.txt", "w");

    if (file == NULL) {
        printf("Error: Could not save passwords.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < numPasswords; i++) {
        fprintf(file, "Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

void loadPasswords(Password *passwords) {
    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Error: Could not load passwords.\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_PASSWORD_LENGTH];

    while (fgets(line, MAX_PASSWORD_LENGTH, file)!= NULL) {
        if (sscanf(line, "Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password)!= 2) {
            printf("Error: Invalid password format.\n");
            exit(1);
        }

        i++;
    }

    fclose(file);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter a website:\n");
        scanf("%s", passwords[numPasswords].username);

        generatePassword(passwords[numPasswords].password, strlen(passwords[numPasswords].username));

        printf("Generated password for %s: %s\n", passwords[numPasswords].username, passwords[numPasswords].password);

        numPasswords++;
    }

    savePasswords(passwords, numPasswords);

    return 0;
}