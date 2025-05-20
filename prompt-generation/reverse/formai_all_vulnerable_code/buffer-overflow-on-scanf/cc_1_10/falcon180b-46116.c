//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for(i = 0; i < 16; i++) {
        // Use rand() to generate a random number between 0 and 255
        // Then convert it to a character and store it in the key
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        // Use the key to shift the ASCII value of each character in the message
        char c = message[i];
        int k = key[i % 16];
        int s = (c + k) % 256;
        message[i] = s;
    }
}

// Function to decrypt the message using the key
void decrypt(char* message, char* key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        // Use the key to shift the ASCII value of each character in the message
        char c = message[i];
        int k = key[i % 16];
        int s = (c - k) % 256;
        message[i] = s;
    }
}

int main() {
    // Generate a random key
    char key[16];
    generate_key(key);

    // Get the message from the user
    char message[100];
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}