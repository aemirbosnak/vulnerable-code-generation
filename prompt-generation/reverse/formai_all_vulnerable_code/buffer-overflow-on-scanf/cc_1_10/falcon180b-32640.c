//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void generate_key(char key[SIZE]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        key[i] = i + 'A';
    }
}

void encrypt(char message[100], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + (int) key[i % SIZE]) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + (int) key[i % SIZE]) % 26 + 'a';
            }
        }
    }
}

void decrypt(char message[100], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - (int) key[i % SIZE] + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - (int) key[i % SIZE] + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char message[100], key[SIZE];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}