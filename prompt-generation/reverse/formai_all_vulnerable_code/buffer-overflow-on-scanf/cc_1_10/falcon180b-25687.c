//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Define the encryption function
void encrypt(char* message, char* encrypted_message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == strlen(KEY)) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ KEY[j];
    }
    encrypted_message[strlen(message)] = '\0';
}

// Define the decryption function
void decrypt(char* encrypted_message, char* decrypted_message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++, j++) {
        if (j == strlen(KEY)) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ KEY[j];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

// Define the main function
int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, encrypted_message);

    // Display the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(encrypted_message, decrypted_message);

    // Display the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}