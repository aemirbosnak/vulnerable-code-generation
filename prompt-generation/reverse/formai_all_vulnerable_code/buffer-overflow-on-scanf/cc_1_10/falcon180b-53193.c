//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key - 65 + 26) % 26 + 65;
            } else {
                message[i] = (message[i] - key - 97 + 26) % 26 + 97;
            }
        }
        i++;
    }
}

// Function to generate a random key
void generateKey(char* key) {
    int i = 0;
    while (i < MAX_KEY_SIZE - 1) {
        key[i] = 'a' + rand() % 26;
        i++;
    }
    key[i] = '\0';
}

int main() {
    char message[100];
    char key[MAX_KEY_SIZE];
    
    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);
    
    // Generate a random key
    generateKey(key);
    
    // Display the original message and the key
    printf("Original message: %s\n", message);
    printf("Key: %s\n", key);
    
    // Encrypt the message
    encrypt(message, atoi(key));
    printf("Encrypted message: %s\n", message);
    
    // Decrypt the message
    decrypt(message, atoi(key));
    printf("Decrypted message: %s\n", message);
    
    return 0;
}