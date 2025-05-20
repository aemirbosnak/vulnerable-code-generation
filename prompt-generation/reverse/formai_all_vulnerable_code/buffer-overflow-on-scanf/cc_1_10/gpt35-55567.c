//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16            // 128-bit key
#define BLOCK_SIZE 16          // 128-bit block

// Function to perform XOR operation
void xorOperation(char *input, const char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        input[i] ^= key[i];
    }
}

// Function to generate a random key
void generateRandomKey(char *key) {
    srand(time(NULL));       // Initialize random number generator
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to perform encryption
void encrypt(char *input, const char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        input[i] ^= key[i];
    }
}

// Function to perform decryption
void decrypt(char *input, const char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        input[i] ^= key[i];
    }
}

int main() {
    char key[KEY_SIZE];
    char input[BLOCK_SIZE];
    
    generateRandomKey(key);     // Generate a random key
    
    printf("Enter the input text (16 bytes):\n");
    scanf("%16s", input);
    
    printf("Input text: %s\n", input);
    
    encrypt(input, key);
    
    printf("Encrypted text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", (unsigned char) input[i]);
    }
    printf("\n");
    
    decrypt(input, key);
    
    printf("Decrypted text: %s\n", input);
    
    return 0;
}