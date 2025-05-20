//Falcon-180B DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

// Function to generate a random key
void generate_key(char key[SIZE]) {
    char valid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    for (i = 0; i < SIZE; i++) {
        key[i] = valid_chars[rand() % strlen(valid_chars)];
    }
}

// Function to encrypt a message using the key
void encrypt(char message[100], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isupper(message[i])) {
            message[i] = (message[i] - 'A' + (int)key[i % SIZE] - 1) % 26 + 'A';
        } else if (islower(message[i])) {
            message[i] = (message[i] - 'a' + (int)key[i % SIZE] - 1) % 26 + 'a';
        }
    }
}

// Function to decrypt a message using the key
void decrypt(char ciphertext[100], char key[SIZE]) {
    int i;

    for (i = 0; i < strlen(ciphertext); i++) {
        if (isupper(ciphertext[i])) {
            ciphertext[i] = (ciphertext[i] - 'A' - (int)key[i % SIZE] + 26) % 26 + 'A';
        } else if (islower(ciphertext[i])) {
            ciphertext[i] = (ciphertext[i] - 'a' - (int)key[i % SIZE] + 26) % 26 + 'a';
        }
    }
}

// Main function
int main() {
    char message[100], ciphertext[100], key[SIZE];

    // Get message from user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate random key
    generate_key(key);

    // Encrypt message using key
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message using same key
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}