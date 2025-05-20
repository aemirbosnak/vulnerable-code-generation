//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>

// Define the encryption function
void encrypt(char* message, int key) {
    // Shift each character in the message by the key
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        int newChar = c + key;
        if (newChar > 'z') {
            newChar -= 26;
        }
        message[i] = newChar;
    }
}

// Define the decryption function
void decrypt(char* message, int key) {
    // Shift each character in the message by the inverse of the key
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        int newChar = c - key;
        if (newChar < 'a') {
            newChar += 26;
        }
        message[i] = newChar;
    }
}

int main() {
    // Prompt the user for a message to encrypt
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    // Prompt the user for a key to use for encryption and decryption
    int key;
    printf("Enter a key for encryption and decryption: ");
    scanf("%d", &key);
    
    // Encrypt the message using the key
    encrypt(message, key);
    
    // Print the encrypted message
    printf("Encrypted message: %s\n", message);
    
    // Decrypt the encrypted message using the key
    decrypt(message, key);
    
    // Print the decrypted message
    printf("Decrypted message: %s\n", message);
    
    return 0;
}