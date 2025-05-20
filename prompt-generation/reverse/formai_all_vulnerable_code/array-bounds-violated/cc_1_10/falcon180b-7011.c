//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % SIZE + 'A';
            }
            else {
                message[i] = (message[i] - 'a' + key) % SIZE + 'a';
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + SIZE) % SIZE + 'A';
            }
            else {
                message[i] = (message[i] - 'a' - key + SIZE) % SIZE + 'a';
            }
        }
        i++;
    }
}

int main() {
    char message[100];
    int key = 3;

    // Get input message from user
    printf("Enter the message to be encrypted/decrypted: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Error: Input message is too long.\n");
        exit(1);
    }

    // Remove newline character from input message
    int length = strlen(message);
    message[length - 1] = '\0';

    // Encrypt the message using Caesar cipher
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using Caesar cipher
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}