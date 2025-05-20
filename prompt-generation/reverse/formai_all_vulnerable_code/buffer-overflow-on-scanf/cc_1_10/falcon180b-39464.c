//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // 128-bit key

// Function to encrypt the message using the key
void encrypt(char *message, char *key, char *ciphertext) {
    int i, j, k = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]); // Convert to uppercase
            ciphertext[k++] = message[i]; // Store the plaintext character in the ciphertext
        } else {
            ciphertext[k++] = message[i]; // Store the special character as it is
        }
    }
    ciphertext[k] = '\0'; // Terminate the ciphertext string

    // XOR the message with the key to get the encrypted message
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

// Function to decrypt the message using the key
void decrypt(char *ciphertext, char *key, char *message) {
    int i, j, k = 0;
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = tolower(ciphertext[i]); // Convert to lowercase
            message[k++] = ciphertext[i] ^ key[i % KEY_SIZE]; // XOR with the key to get the plaintext
        } else {
            message[k++] = ciphertext[i]; // Store the special character as it is
        }
    }
    message[k] = '\0'; // Terminate the message string
}

int main() {
    char message[100], key[KEY_SIZE], ciphertext[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the encryption key (16 characters): ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    decrypt(ciphertext, key, message);
    printf("Decrypted message: %s\n", message);

    return 0;
}