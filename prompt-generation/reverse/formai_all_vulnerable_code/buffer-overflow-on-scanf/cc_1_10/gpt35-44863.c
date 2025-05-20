//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    printf("\nOriginal Message: %s", message);

    encrypt(message, key);
    printf("Encrypted Message: %s", message);

    decrypt(message, key);
    printf("Decrypted Message: %s", message);

    return 0;
}

void encrypt(char message[], int key)
{
    int len = strlen(message);

    for(int i=0; i<len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] + key - 97) % 26 + 97;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] + key - 65) % 26 + 65;
        }
    }
}

void decrypt(char message[], int key)
{
    int len = strlen(message);

    for(int i=0; i<len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - key - 97 + 26) % 26 + 97;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - key - 65 + 26) % 26 + 65;
        }
    }
}