//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
// Alan Turing style Cryptography Implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generate a random number between 0 and 1000000000
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 1000000000;
}

// Encrypt a string using the Caesar Cipher
char* encryptCaesar(char* plaintext, int key) {
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] + key;
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Decrypt a string using the Caesar Cipher
char* decryptCaesar(char* ciphertext, int key) {
    int len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[len] = '\0';
    return plaintext;
}

// Main function
int main() {
    // Generate a random key
    int key = generateRandomNumber();

    // Prompt the user for the plaintext
    char* plaintext = malloc(1000);
    printf("Enter the plaintext: ");
    fgets(plaintext, 1000, stdin);

    // Encrypt the plaintext using the Caesar Cipher
    char* ciphertext = encryptCaesar(plaintext, key);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext using the Caesar Cipher
    char* decryptedText = decryptCaesar(ciphertext, key);
    printf("Decrypted text: %s\n", decryptedText);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedText);

    return 0;
}