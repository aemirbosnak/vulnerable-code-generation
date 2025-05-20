//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Encryption function
void encryption(char* message, int key)
{
    int i, length = strlen(message);

    // Loop through the message and add key to each character
    for(i = 0; i < length; ++i)
    {
        message[i] += key;
    }
}

// Decryption function
void decryption(char* message, int key)
{
    int i, length = strlen(message);

    // Loop through the message and subtract key from each character
    for(i = 0; i < length; ++i)
    {
        message[i] -= key;
    }
}

int main()
{
    // Declare variables
    char message[100];
    int key;

    // Get message from user
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Call encryption function
    encryption(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Call decryption function
    decryption(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}