//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';
}

int comparePasswords(const void* a, const void* b) {
    const Password* passwordA = (const Password*)a;
    const Password* passwordB = (const Password*)b;

    return strcmp(passwordA->username, passwordB->username);
}

void printPasswords(Password passwords[], int numPasswords) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter a username (or type 'quit' to exit): ");
        scanf("%s", username);

        if (strcmp(username, "quit") == 0) {
            break;
        }

        printf("Enter a password for %s: ", username);
        scanf("%s", password);

        strcpy(passwords[numPasswords].username, username);
        strcpy(passwords[numPasswords].password, password);

        numPasswords++;
    }

    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);

    printf("Sorted Passwords:\n");
    printPasswords(passwords, numPasswords);

    return 0;
}