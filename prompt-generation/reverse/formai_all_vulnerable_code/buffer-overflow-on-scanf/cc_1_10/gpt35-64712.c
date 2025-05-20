//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, int key)
{
    int i;
    int length = strlen(message);

    for(i = 0; i < length; i++)
    {
        // ASCII value for space is 32
        // If the character is not a space, encrypt it
        if(message[i] != 32)
        {
            // Add the key to the ASCII value of the character
            message[i] += key;

            // If the ASCII value of the character goes beyond 122 which is z, wrap it around to a
            if(message[i] > 122)
            {
                message[i] -= 26;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, int key)
{
    int i;
    int length = strlen(message);

    for(i = 0; i < length; i++)
    {
        // ASCII value for space is 32
        // If the character is not a space, decrypt it
        if(message[i] != 32)
        {
            // Subtract the key from the ASCII value of the character
            message[i] -= key;

            // If the ASCII value of the character goes below 97 which is a, wrap it around to z
            if(message[i] < 97)
            {
                message[i] += 26;
            }
        }
    }
}

int main()
{
    char message[1000];
    int key = 0;

    // Get the message to be encrypted from the user
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get the encryption key from the user
    printf("Enter an encryption key: ");
    scanf("%d", &key);

    // Remove the newline character from the message
    strtok(message, "\n");

    // Encrypt the message and display it
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message and display it
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}