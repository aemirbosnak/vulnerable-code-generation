//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, int key) {
    int length = strlen(message);
    char encrypted_message[length + 1];
    encrypted_message[length] = '\0';

    // Encrypt each character of the message
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + key) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + key) % 26) + 'A';
        }
        encrypted_message[i] = c;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* message, int key) {
    int length = strlen(message);
    char decrypted_message[length + 1];
    decrypted_message[length] = '\0';

    // Decrypt each character of the message
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' - key + 26) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' - key + 26) % 26) + 'A';
        }
        decrypted_message[i] = c;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}