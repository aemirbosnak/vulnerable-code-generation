//Falcon-180B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_SIZE 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_SIZE];
} Password;

void generateHash(char* password, char* hash) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        hash[i] = 0;
    }
    for (i = 0; i < strlen(password); i++) {
        hash[i % HASH_SIZE] ^= password[i];
    }
}

int compareHash(char* password, char* hash) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        if (hash[i]!= 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_SIZE];
    int choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Enter your password: ");
        scanf("%s", password);
        generateHash(password, hash);
        printf("Your hash is: ");
        for (int i = 0; i < HASH_SIZE; i++) {
            printf("%02X", hash[i]);
        }
        printf("\n");

        if (numPasswords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
        } else {
            printf("Do you want to save this password? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                strcpy(passwords[numPasswords].password, password);
                strcpy(passwords[numPasswords].hash, hash);
                numPasswords++;
            }
        }

        printf("\n");
    } while (1);

    return 0;
}