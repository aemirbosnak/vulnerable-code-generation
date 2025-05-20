//FormAI DATASET v1.0 Category: modern Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to perform encryption
void encrypt(char* message, int key)
{
    int len = strlen(message);
    
    // Iterate over every character in the message
    for (int i = 0; i < len; i++)
    {
        // Shift the character by the key value
        message[i] = message[i] + key;
    }
}

// Function to perform decryption
void decrypt(char* message, int key)
{
    int len = strlen(message);
    
    // Iterate over every character in the message
    for (int i = 0; i < len; i++)
    {
        // Shift the character back by the key value
        message[i] = message[i] - key;
    }
}

int main()
{
    char message[100];
    int key;
    
    // Ask the user to enter a message and key
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    
    printf("Enter a key: ");
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