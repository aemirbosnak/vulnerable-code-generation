//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

// Function to generate a random number between 0 and 255
uint8_t get_random_byte() {
    return (uint8_t)rand() % 256;
}

// Function to encrypt a message using the Vigenere cipher
void vigenere_encrypt(char* message, char* key, char* cipher) {
    int i, j;
    for (i = 0, j = 0; message[i] != '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        cipher[i] = message[i] + key[j];
    }
    cipher[i] = '\0';
}

// Function to decrypt a message using the Vigenere cipher
void vigenere_decrypt(char* cipher, char* key, char* message) {
    int i, j;
    for (i = 0, j = 0; cipher[i] != '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        message[i] = cipher[i] - key[j];
    }
    message[i] = '\0';
}

// Function to generate a random key
char* generate_key(int length) {
    char* key = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        key[i] = get_random_byte();
    }
    return key;
}

// Function to generate a random message
char* generate_message(int length) {
    char* message = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        message[i] = get_random_byte();
    }
    return message;
}

// Function to print the encryption and decryption results
void print_results(char* message, char* key, char* cipher) {
    printf("Message: %s\n", message);
    printf("Key: %s\n", key);
    printf("Encrypted Message: %s\n", cipher);
    printf("Decrypted Message: %s\n", message);
}

int main() {
    srand(time(NULL));

    // Generate a random message and key
    char* message = generate_message(100);
    char* key = generate_key(10);

    // Encrypt the message using the Vigenere cipher
    char* cipher = malloc(strlen(message) * sizeof(char));
    vigenere_encrypt(message, key, cipher);

    // Decrypt the message using the Vigenere cipher
    char* decrypted = malloc(strlen(cipher) * sizeof(char));
    vigenere_decrypt(cipher, key, decrypted);

    // Print the encryption and decryption results
    print_results(message, key, cipher);

    return 0;
}