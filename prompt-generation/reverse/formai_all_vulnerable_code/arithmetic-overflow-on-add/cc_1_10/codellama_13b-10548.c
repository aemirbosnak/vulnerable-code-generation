//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the encryption and decryption functions
void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
    char message[100];
    int key;

    // Get the message and key from the user
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

// Encryption function
void encrypt(char* message, int key) {
    // Calculate the encryption key
    int encryption_key = key * 7 + 5;

    // Encrypt the message
    for (int i = 0; i < strlen(message); i++) {
        message[i] += encryption_key;
    }
}

// Decryption function
void decrypt(char* message, int key) {
    // Calculate the decryption key
    int decryption_key = key * 7 + 5;

    // Decrypt the message
    for (int i = 0; i < strlen(message); i++) {
        message[i] -= decryption_key;
    }
}