//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Function to encrypt a string using a Caesar cipher
void encrypt_caesar(char *input, char *output, int key) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] + key;
    }
}

// Function to decrypt a string using a Caesar cipher
void decrypt_caesar(char *input, char *output, int key) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] - key;
    }
}

// Function to encrypt a string using a Vigenere cipher
void encrypt_vigenere(char *input, char *output, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++, j = (j + 1) % strlen(key)) {
        output[i] = input[i] + key[j];
    }
}

// Function to decrypt a string using a Vigenere cipher
void decrypt_vigenere(char *input, char *output, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++, j = (j + 1) % strlen(key)) {
        output[i] = input[i] - key[j];
    }
}

int main() {
    char input[100];
    char output[100];
    char key[100];

    // Caesar cipher
    printf("Enter the message to encrypt: ");
    scanf("%s", input);
    printf("Enter the key: ");
    scanf("%s", key);
    encrypt_caesar(input, output, atoi(key));
    printf("Encrypted message: %s\n", output);
    decrypt_caesar(output, input, atoi(key));
    printf("Decrypted message: %s\n", input);

    // Vigenere cipher
    printf("Enter the message to encrypt: ");
    scanf("%s", input);
    printf("Enter the key: ");
    scanf("%s", key);
    encrypt_vigenere(input, output, key);
    printf("Encrypted message: %s\n", output);
    decrypt_vigenere(output, input, key);
    printf("Decrypted message: %s\n", input);

    return 0;
}