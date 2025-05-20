//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26

// Function to generate a random key
void generateKey(char key[])
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        key[i] = 'A' + rand() % 26;
    }
}

// Function to encrypt the message
void encrypt(char key[], char message[])
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        if(isalpha(message[i]))
        {
            message[i] = message[i] + 'A' - 'a';
        }
    }
    for(i = 0; i < strlen(message); i++)
    {
        if(isalpha(message[i]))
        {
            message[i] = message[i] + (key[i%SIZE] - 'A');
        }
    }
}

// Function to decrypt the message
void decrypt(char key[], char message[])
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        if(isalpha(message[i]))
        {
            message[i] = message[i] - (key[i%SIZE] - 'A');
        }
    }
    for(i = 0; i < strlen(message); i++)
    {
        if(isalpha(message[i]))
        {
            message[i] = message[i] - 'A' + 'a';
        }
    }
}

int main()
{
    char key[SIZE], message[100];

    // Generate key
    generateKey(key);

    // Encrypt message
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(key, message);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(key, message);
    printf("Decrypted message: %s\n", message);

    return 0;
}