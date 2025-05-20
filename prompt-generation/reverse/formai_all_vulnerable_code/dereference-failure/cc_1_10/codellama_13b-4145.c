//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
// Cryptography Implementation in C
// Artistic Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PLAINTEXT_SIZE 1024
#define MAX_CIPHERTEXT_SIZE 1024
#define MAX_KEY_SIZE 1024

// Function to encrypt plaintext using Caesar Cipher
char* encryptCaesar(char* plaintext, int key) {
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        ciphertext[i] = (plaintext[i] + key) % 26;
    }

    ciphertext[len] = '\0';
    return ciphertext;
}

// Function to decrypt ciphertext using Caesar Cipher
char* decryptCaesar(char* ciphertext, int key) {
    int len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        plaintext[i] = (ciphertext[i] - key) % 26;
    }

    plaintext[len] = '\0';
    return plaintext;
}

// Main function
int main() {
    // Get plaintext and key from user
    char plaintext[MAX_PLAINTEXT_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter plaintext: ");
    fgets(plaintext, MAX_PLAINTEXT_SIZE, stdin);
    printf("Enter key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // Convert key to integer
    int key_int = atoi(key);

    // Encrypt plaintext using Caesar Cipher
    char* ciphertext = encryptCaesar(plaintext, key_int);

    // Decrypt ciphertext using Caesar Cipher
    char* decrypted_plaintext = decryptCaesar(ciphertext, key_int);

    // Print plaintext, ciphertext, and decrypted plaintext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

    // Free memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}