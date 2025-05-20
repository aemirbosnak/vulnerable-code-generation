//FormAI DATASET v1.0 Category: Modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
void encrypt(char* input, int key)
{
    // Convert input string to lowercase
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += 32;
        }
    }

    // Shift each character by the key value
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = (char)((int)input[i] + key);

            // Wrap around the alphabet
            if(input[i] > 'z')
            {
                input[i] = (char)((int)input[i] - 26);
            }
        }
    }
}

// Decryption function
void decrypt(char* input, int key)
{
    // Shift each character back by the key value
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = (char)((int)input[i] - key);

            // Wrap around the alphabet
            if(input[i] < 'a')
            {
                input[i] = (char)((int)input[i] + 26);
            }
        }
    }
}

int main()
{
    // Get input string and encryption key from user
    char input[100];
    int key;

    printf("Enter a string to encrypt: ");
    scanf("%s", input);

    printf("Enter an encryption key: ");
    scanf("%d", &key);

    // Encrypt the input string
    encrypt(input, key);
    printf("Encrypted string: %s \n", input);

    // Decrypt the input string
    decrypt(input, key);
    printf("Decrypted string: %s \n", input);

    return 0;
}