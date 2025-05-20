//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char key[KEY_SIZE]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt the message
void encrypt(char message[1000], char key[KEY_SIZE]) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            if (isalpha(message[i])) {
                message[i] = message[i] + key[j % KEY_SIZE];
                j++;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char message[1000], char key[KEY_SIZE]) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            if (isalpha(message[i])) {
                message[i] = message[i] - key[j % KEY_SIZE];
                j++;
            }
        }
    }
}

int main() {
    char message[1000];
    char key[KEY_SIZE];

    // Prompt user to enter message
    printf("Enter message: ");
    scanf("%s", message);

    // Generate random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}