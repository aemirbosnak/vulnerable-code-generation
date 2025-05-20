//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[]{}|;:,.<>/?";
    int numChars = strlen(chars);

    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % numChars];
    }
}

int comparePasswords(const void *a, const void *b) {
    return strcmp(*(Password **)a, *(Password **)b);
}

int main() {
    Password *passwords = malloc(MAX_PASSWORDS * sizeof(Password));
    int numPasswords = 0;

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter a website name: ");
        scanf("%s", passwords[numPasswords].name);

        printf("Enter a password length (between 1 and 20): ");
        int length = rand() % 20 + 1;
        while (length < 1 || length > 20) {
            printf("Invalid length. Enter a password length (between 1 and 20): ");
            scanf("%d", &length);
        }

        generatePassword(passwords[numPasswords].password, length);
        numPasswords++;
    }

    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("Website: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].password);
    }

    free(passwords);
    return 0;
}