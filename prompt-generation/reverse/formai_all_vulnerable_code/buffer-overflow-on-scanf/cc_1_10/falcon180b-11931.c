//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int comparePasswords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sortPasswords() {
    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);
}

void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Website: %s\n", passwords[i].website);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

int main() {
    char input[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter a website: ");
        scanf("%s", website);

        printf("Enter a username: ");
        scanf("%s", username);

        generatePassword(input, rand() % (MAX_PASSWORD_LENGTH - 8) + 8);

        strcpy(passwords[numPasswords].username, username);
        strcpy(passwords[numPasswords].website, website);
        strcpy(passwords[numPasswords].password, input);

        numPasswords++;

        printf("Password generated for %s@%s: %s\n", username, website, input);

        sortPasswords();
        printPasswords();
    }

    return 0;
}