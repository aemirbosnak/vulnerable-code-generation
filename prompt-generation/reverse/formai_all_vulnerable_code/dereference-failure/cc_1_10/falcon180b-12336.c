//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted = (char*) malloc(len + 1);
    memset(encrypted, 0, len + 1);

    // Encrypt the message
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + ((c - 'A' + key) % 26);
            } else {
                c = 'a' + ((c - 'a' + key) % 26);
            }
        }
        encrypted[i] = c;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);
}

// Function to decrypt the message
void decrypt(char* message, int key) {
    int len = strlen(message);
    char* decrypted = (char*) malloc(len + 1);
    memset(decrypted, 0, len + 1);

    // Decrypt the message
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + ((c - 'A' - key + 26) % 26);
            } else {
                c = 'a' + ((c - 'a' - key + 26) % 26);
            }
        }
        decrypted[i] = c;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char* message = "Hello, World! ";
    int key = 3;

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}