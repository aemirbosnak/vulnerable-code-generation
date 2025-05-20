//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the Caesar cipher
#define KEY 13

// Function to encrypt a message using the Caesar cipher
void encrypt(char *message) {
    int i = 0;
    while (message[i]) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + KEY;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
        i++;
    }
}

// Function to decrypt a message using the Caesar cipher
void decrypt(char *message) {
    int i = 0;
    while (message[i]) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - KEY;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
        i++;
    }
}

// Function to generate a random key for the Caesar cipher
void generate_key() {
    int key = rand() % 26 + 1;
    printf("Key: %d\n", key);
}

int main() {
    char message[100];
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);
    
    // Generate a random key for the Caesar cipher
    generate_key();
    
    // Encrypt the message using the Caesar cipher
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    
    // Decrypt the encrypted message using the Caesar cipher
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}