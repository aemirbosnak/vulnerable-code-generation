//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int length = strlen(message);
    char encrypted_message[length + 1];

    // Encrypt each character of the message
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (message[i] + key - 65) % 26 + 65;
            } else {
                encrypted_message[i] = (message[i] + key - 97) % 26 + 97;
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    // Print the encrypted message
    encrypted_message[length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int length = strlen(message);
    char decrypted_message[length + 1];

    // Decrypt each character of the message
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = (message[i] - key - 65) % 26 + 65;
            } else {
                decrypted_message[i] = (message[i] - key - 97) % 26 + 97;
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }

    // Print the decrypted message
    decrypted_message[length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}