//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, char *key, char *cipherText)
{
    int messageLength = strlen(message), keyLength = strlen(key), i;

    // XOR each character with corresponding character of key
    for (i = 0; i < messageLength; i++)
        cipherText[i] = message[i] ^ key[i % keyLength];

    // Terminate the cipher text with null character
    cipherText[messageLength] = '\0';
}

// Function to decrypt the cipher text
void decrypt(char *cipherText, char *key, char *decryptedMessage)
{
    int cipherTextLength = strlen(cipherText), keyLength = strlen(key), i;

    // XOR each character with corresponding character of key
    for (i = 0; i < cipherTextLength; i++)
        decryptedMessage[i] = cipherText[i] ^ key[i % keyLength];

    // Terminate the decrypted message with null character
    decryptedMessage[cipherTextLength] = '\0';
}

int main()
{
    char message[100], key[100], cipherText[100], decryptedMessage[100];

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    // Print the message and key entered by the user
    printf("Message: %s\nKey: %s\n", message, key);

    // Encrypt the message
    encrypt(message, key, cipherText);

    // Print the cipher text
    printf("Cipher Text: %s\n", cipherText);

    // Decrypt the cipher text
    decrypt(cipherText, key, decryptedMessage);

    // Print the decrypted message
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}