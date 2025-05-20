//Falcon-180B DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 32

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} Password;

void generateHash(char* password, char* hash) {
    int i, j;
    for (i = 0, j = 0; i < strlen(password); i++) {
        hash[j++] = tolower(password[i]);
    }
    hash[j] = '\0';
}

int compareHashes(char* hash1, char* hash2) {
    return strcmp(hash1, hash2) == 0;
}

void addPassword(Password* passwords, int numPasswords, char* name, char* password) {
    generateHash(password, passwords[numPasswords].hash);
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void printPasswords(Password* passwords, int numPasswords) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Name: %s\n", passwords[i].name);
        printf("Password: %s\n", passwords[i].password);
        printf("Hash: %s\n\n", passwords[i].hash);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Welcome to the Password Manager!\n");

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter the name of the website/service: ");
        scanf("%s", passwords[numPasswords].name);

        printf("Enter the password: ");
        scanf("%s", passwords[numPasswords].password);

        addPassword(passwords, numPasswords, passwords[numPasswords].name, passwords[numPasswords].password);

        printf("Password added successfully!\n");
        numPasswords++;
    }

    printf("\nYour passwords:\n");
    printPasswords(passwords, numPasswords);

    return 0;
}