//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the key for encryption
#define KEY "My secret key"

// Define the alphabet
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

void encrypt(char *message, int key)
{
    int length = strlen(message);
    char result[length + 1];
    int i, j;

    for (i = 0, j = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                result[j] = toupper((message[i] + key - 65) % 26 + 65);
            }
            else
            {
                result[j] = toupper((message[i] + key - 97) % 26 + 97);
            }
            j++;
        }
        else
        {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);
}

void decrypt(char *message, int key)
{
    int length = strlen(message);
    char result[length + 1];
    int i, j;

    for (i = 0, j = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                result[j] = toupper((message[i] - key - 65) % 26 + 65);
            }
            else
            {
                result[j] = toupper((message[i] - key - 97) % 26 + 97);
            }
            j++;
        }
        else
        {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';
    strcpy(message, result);
}

int main()
{
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}