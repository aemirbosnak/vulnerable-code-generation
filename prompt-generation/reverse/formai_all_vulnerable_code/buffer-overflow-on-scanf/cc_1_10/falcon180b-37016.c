//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const int KEY = 13;

// Define the encryption function
void encrypt(char *message) {
    int length = strlen(message);
    char *encrypted_message = malloc(length + 1);

    // Encrypt each character in the message
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            encrypted_message[i] = c + KEY;
            if (encrypted_message[i] > 'z') {
                encrypted_message[i] -= 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            encrypted_message[i] = c + KEY;
            if (encrypted_message[i] > 'Z') {
                encrypted_message[i] -= 26;
            }
        } else {
            encrypted_message[i] = c;
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Define the decryption function
void decrypt(char *message) {
    int length = strlen(message);
    char *decrypted_message = malloc(length + 1);

    // Decrypt each character in the message
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            decrypted_message[i] = c - KEY;
            if (decrypted_message[i] < 'a') {
                decrypted_message[i] += 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            decrypted_message[i] = c - KEY;
            if (decrypted_message[i] < 'A') {
                decrypted_message[i] += 26;
            }
        } else {
            decrypted_message[i] = c;
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Define the main function
int main() {
    char message[100];
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    char encrypted_message[100];
    strcpy(encrypted_message, message);
    decrypt(encrypted_message);

    return 0;
}