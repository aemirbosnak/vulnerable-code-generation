//Falcon-180B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} Password;

void generateHash(char* password, char* hash) {
    int i, j;
    for (i = 0, j = 0; i < strlen(password); i++) {
        hash[j++] = password[i] ^ 0x36;
    }
    hash[j] = '\0';
}

bool compareHash(char* password, char* hash) {
    int i;
    for (i = 0; i < strlen(hash); i++) {
        if (hash[i]!= (password[i] ^ 0x36)) {
            return false;
        }
    }
    return true;
}

int main() {
    int numPasswords, i;
    Password passwords[MAX_PASSWORDS];

    printf("Enter number of passwords to store: ");
    scanf("%d", &numPasswords);

    printf("Enter passwords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("Password %d: ", i+1);
        scanf("%s", passwords[i].password);
        generateHash(passwords[i].password, passwords[i].hash);
    }

    printf("Passwords stored:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("Password %d: %s\n", i+1, passwords[i].password);
    }

    printf("Enter password to check:\n");
    char inputPassword[MAX_PASSWORD_LENGTH];
    scanf("%s", inputPassword);

    bool found = false;
    for (i = 0; i < numPasswords; i++) {
        if (compareHash(inputPassword, passwords[i].hash)) {
            printf("Password found!\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }

    return 0;
}