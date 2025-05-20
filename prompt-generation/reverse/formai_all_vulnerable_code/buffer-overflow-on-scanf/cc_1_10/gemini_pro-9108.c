//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

// Function to encrypt or decrypt a message using the Caesar cipher
int caesar_cipher(char *msg, int key, int mode) {
    int len = strlen(msg);

    // Check if the key is valid
    if (key < 1 || key > 26) {
        printf("Invalid key. Key must be between 1 and 26.\n");
        return -1;
    }

    // Encrypt or decrypt the message
    if (mode == ENCRYPT) {
        for (int i = 0; i < len; i++) {
            char c = msg[i];
            if (c >= 'a' && c <= 'z') {
                c = (c + key - 'a') % 26 + 'a';
            } else if (c >= 'A' && c <= 'Z') {
                c = (c + key - 'A') % 26 + 'A';
            }
            msg[i] = c;
        }
    } else if (mode == DECRYPT) {
        for (int i = 0; i < len; i++) {
            char c = msg[i];
            if (c >= 'a' && c <= 'z') {
                c = (c - key - 'a' + 26) % 26 + 'a';
            } else if (c >= 'A' && c <= 'Z') {
                c = (c - key - 'A' + 26) % 26 + 'A';
            }
            msg[i] = c;
        }
    } else {
        printf("Invalid mode. Mode must be either ENCRYPT or DECRYPT.\n");
        return -1;
    }

    return 0;
}

int main() {
    // Initialize the message and key
    char msg[100];
    int key;

    // Get the message and key from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", msg);
    printf("Enter the key (1-26): ");
    scanf("%d", &key);

    // Encrypt or decrypt the message
    int status = caesar_cipher(msg, key, ENCRYPT);
    if (status != 0) {
        printf("Encryption failed.\n");
        return -1;
    }

    // Print the encrypted/decrypted message
    printf("Encrypted/Decrypted message: %s\n", msg);

    return 0;
}