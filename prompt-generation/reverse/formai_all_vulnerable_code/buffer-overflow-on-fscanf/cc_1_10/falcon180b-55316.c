//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
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
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int comparePasswords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open passwords.txt\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", username, password) == 2) {
        if (numPasswords >= MAX_PASSWORDS) {
            fprintf(stderr, "Error: too many passwords\n");
            return 1;
        }
        strcpy(passwords[numPasswords].username, username);
        strcpy(passwords[numPasswords].password, password);
        numPasswords++;
    }

    fclose(file);

    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}