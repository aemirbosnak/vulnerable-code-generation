//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define KEY "mysecretkey"

// Function to encrypt the message
void encrypt(char message[SIZE], char key[SIZE]) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((int) message[i] + (int) key[i % strlen(key)]);
        }
    }
}

// Function to decrypt the message
void decrypt(char message[SIZE], char key[SIZE]) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((int) message[i] - (int) key[i % strlen(key)]);
        }
    }
}

// Function to generate a random key
void generateKey(char key[SIZE]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key) - 1] = '\0';
}

// Function to encrypt and decrypt the message
void main() {
    char message[SIZE];
    char key[SIZE];

    // Generate a random key
    generateKey(key);

    // Get the message from the user
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
}