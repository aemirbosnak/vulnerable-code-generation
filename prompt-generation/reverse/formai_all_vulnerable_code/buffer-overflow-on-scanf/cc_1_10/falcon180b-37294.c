//Falcon-180B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define HASH_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} Password;

void generateHash(char* password, char* hash) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        hash[i] = tolower(password[i]);
    }
    hash[strlen(password)] = '\0';
}

int compareHashes(char* hash1, char* hash2) {
    int i;
    for (i = 0; i < strlen(hash1); i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

void storePassword(Password* passwords, int numPasswords, char* password, char* hash) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (passwords[i].password[0] == '\0') {
            strcpy(passwords[i].password, password);
            strcpy(passwords[i].hash, hash);
            return;
        }
    }
    printf("Maximum number of passwords reached.\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];

    while (1) {
        printf("Enter a password: ");
        scanf("%s", password);

        generateHash(password, hash);

        int i;
        for (i = 0; i < numPasswords; i++) {
            if (compareHashes(hash, passwords[i].hash)) {
                printf("Password already exists.\n");
                return 0;
            }
        }

        storePassword(passwords, numPasswords, password, hash);
        numPasswords++;
    }

    return 0;
}