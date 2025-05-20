//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to encrypt the message using a Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + key - 65);
            } else {
                message[i] = toupper(message[i] + key - 97);
            }
        }
        i++;
    }
}

// Function to decrypt the message using a Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] - key - 65);
            } else {
                message[i] = toupper(message[i] - key - 97);
            }
        }
        i++;
    }
}

int main() {
    char message[1000];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%[^\n]", message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}