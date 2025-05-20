//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char *username;
    char *password;
};

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charsetSize = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetSize];
    }

    password[length] = '\0';
}

int comparePasswords(const void *a, const void *b) {
    const struct Password *passwordA = (const struct Password *)a;
    const struct Password *passwordB = (const struct Password *)b;

    return strcmp(passwordA->username, passwordB->username);
}

void printPasswords(struct Password *passwords, int numPasswords) {
    qsort(passwords, numPasswords, sizeof(struct Password), comparePasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    generatePassword(password, strlen(username));

    strcat(password, username);

    printf("Your password is: %s\n", password);

    FILE *file = fopen("passwords.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "%s:%s\n", username, password);

    fclose(file);

    return 0;
}