//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the encryption function
void encrypt(char *message) {
    int length = strlen(message);
    int key = 5;
    char encrypted_message[length];

    // Encrypt each character in the message
    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        }
        encrypted_message[i] = c;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Define the decryption function
void decrypt(char *message) {
    int length = strlen(message);
    int key = 5;
    char decrypted_message[length];

    // Decrypt each character in the message
    for (int i = 0; i < length; i++) {
        char c = toupper(message[i]);
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - key + 26) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - key + 26) % 26 + 'a';
        }
        decrypted_message[i] = c;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

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