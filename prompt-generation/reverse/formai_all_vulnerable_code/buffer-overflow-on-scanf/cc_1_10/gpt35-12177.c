//FormAI DATASET v1.0 Category: modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char* message, int key)
{
    int length = strlen(message);

    // Iterate through message characters
    for (int i = 0; i < length; i++) {
        // Encrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

// Function to perform decryption
void decrypt(char* message, int key)
{
    int length = strlen(message);

    // Iterate through message characters
    for (int i = 0; i < length; i++) {
        // Decrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
}

int main()
{
    char message[100];
    int key;

    // Get input from user
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    // Perform encryption and output result
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Perform decryption and output result
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}