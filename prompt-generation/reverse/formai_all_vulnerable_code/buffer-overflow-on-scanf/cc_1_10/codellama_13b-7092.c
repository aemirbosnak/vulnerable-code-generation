//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store the encryption key and the message
typedef struct {
    char key[100];
    char message[100];
} encryption_t;

// Function to encrypt a message using the Vigenere cipher
void encrypt_message(encryption_t *encryption) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encryption->message); i++, j++) {
        if (j == strlen(encryption->key)) {
            j = 0;
        }
        encryption->message[i] = encryption->message[i] + encryption->key[j];
    }
}

// Function to decrypt a message using the Vigenere cipher
void decrypt_message(encryption_t *encryption) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encryption->message); i++, j++) {
        if (j == strlen(encryption->key)) {
            j = 0;
        }
        encryption->message[i] = encryption->message[i] - encryption->key[j];
    }
}

int main() {
    // Create an encryption struct to store the key and message
    encryption_t encryption;

    // Ask the user to enter the key and message
    printf("Enter the key: ");
    scanf("%s", encryption.key);
    printf("Enter the message: ");
    scanf("%s", encryption.message);

    // Encrypt the message
    encrypt_message(&encryption);
    printf("Encrypted message: %s\n", encryption.message);

    // Decrypt the message
    decrypt_message(&encryption);
    printf("Decrypted message: %s\n", encryption.message);

    return 0;
}