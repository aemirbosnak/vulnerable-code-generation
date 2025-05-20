//FormAI DATASET v1.0 Category: modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the message
char* encryptMessage(char* message, int key)
{
    char* result = (char*)malloc(sizeof(char) * strlen(message));
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++)
    {
        // Shift the character by the key value
        result[i] = message[i] + key;
    }
    return result;
}

// Function to decrypt the message
char* decryptMessage(char* message, int key)
{
    char* result = (char*)malloc(sizeof(char) * strlen(message));
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++)
    {
        // Shift the character back by the key value
        result[i] = message[i] - key;
    }
    return result;
}

int main()
{
    char message[100];
    int key;
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();
    printf("Enter the key: ");
    scanf("%d", &key);
    // Seed the random number generator with the current time
    srand(time(NULL));
    // Generate a random number between 1 and 100
    int randomNum = rand() % 100 + 1;
    // Multiply the key by the random number to make it more secure
    key = key * randomNum;
    // Encrypt the message
    char* encryptedMessage = encryptMessage(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);
    // Decrypt the message
    char* decryptedMessage = decryptMessage(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);
    // Free the memory
    free(encryptedMessage);
    free(decryptedMessage);
    return 0;
}