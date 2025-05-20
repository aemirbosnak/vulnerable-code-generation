//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int len = strlen(message);
    char encrypted_message[len];

    // Encrypt each character in the message
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (char) (((int) message[i] + key - 65) % 26 + 65);
            } else {
                encrypted_message[i] = (char) (((int) message[i] + key - 97) % 26 + 97);
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int len = strlen(message);
    char decrypted_message[len];

    // Decrypt each character in the message
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = (char) (((int) message[i] - key - 65) % 26 + 65);
            } else {
                decrypted_message[i] = (char) (((int) message[i] - key - 97) % 26 + 97);
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the encryption/decryption key
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}