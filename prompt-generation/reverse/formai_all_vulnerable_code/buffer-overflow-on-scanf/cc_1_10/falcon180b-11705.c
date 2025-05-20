//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password, int length) {
    if (length == 0) {
        password->password[0] = '\0';
        password->length = 0;
        return;
    }
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int charsetLength = strlen(charset);
    int i = rand() % charsetLength;
    password->password[length - 1] = charset[i];
    generatePassword(password, length - 1);
}

void printPassword(Password password) {
    printf("%s\n", password.password);
}

int main() {
    int numPasswords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    if (numPasswords > MAX_PASSWORDS || numPasswords <= 0) {
        printf("Invalid number of passwords.\n");
        return 1;
    }

    Password passwords[numPasswords];

    for (int i = 0; i < numPasswords; i++) {
        int length;
        printf("Enter the length of password %d: ", i + 1);
        scanf("%d", &length);

        if (length > MAX_PASSWORD_LENGTH || length <= 0) {
            printf("Invalid password length.\n");
            return 1;
        }

        generatePassword(&passwords[i], length);
    }

    for (int i = 0; i < numPasswords; i++) {
        printPassword(passwords[i]);
    }

    return 0;
}