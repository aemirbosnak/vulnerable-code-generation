//Falcon-180B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password) {
    const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = charset[rand() % strlen(charset)];
    }

    password->length = i;
}

int comparePasswords(Password *password1, Password *password2) {
    return strcmp(password1->password, password2->password);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Enter the number of passwords you want to generate:\n");
    scanf("%d", &numPasswords);

    printf("Generating %d passwords...\n", numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        generatePassword(&passwords[i]);
        printf("Password %d: %s\n", i+1, passwords[i].password);
    }

    printf("Enter the password number you want to compare:\n");
    scanf("%d", &numPasswords);

    printf("Enter the password to compare with:\n");
    scanf("%s", passwords[numPasswords-1].password);

    if (comparePasswords(&passwords[numPasswords-1], &passwords[0]) == 0) {
        printf("Passwords match!\n");
    } else {
        printf("Passwords do not match!\n");
    }

    return 0;
}