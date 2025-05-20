//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given plaintext
void encrypt(char message[])
{
    int i = 0;
    while (message[i] != '\0')
    {
        message[i] = (char)((int)message[i] + i % 10);
        i++;
    }
}

// Function to decrypt the given ciphertext
void decrypt(char message[])
{
    int i = 0;
    while (message[i] != '\0')
    {
        message[i] = (char)((int)message[i] - i % 10);
        i++;
    }
}

int main()
{
    char plaintext[100];
    char ciphertext[100];

    printf("Enter a message to encrypt: ");
    fgets(plaintext, 100, stdin);

    // Remove the newline character from input
    plaintext[strlen(plaintext)-1] = '\0';

    encrypt(plaintext);

    printf("Encrypted message: %s\n", plaintext);

    printf("Enter a message to decrypt: ");
    fgets(ciphertext, 100, stdin);

    // Remove the newline character from input
    ciphertext[strlen(ciphertext)-1] = '\0';

    decrypt(ciphertext);

    printf("Decrypted message: %s\n", ciphertext);

    return 0;
}