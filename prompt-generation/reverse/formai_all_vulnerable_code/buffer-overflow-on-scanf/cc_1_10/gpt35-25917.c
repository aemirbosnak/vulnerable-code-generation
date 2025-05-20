//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
//***********************************************
//*  C Encryption Example Program - Ada Lovelace *
//***********************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char* data, char* key);
void decrypt(char* data, char* key);

int main()
{
    char message[100];
    char key[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* data, char* key)
{
    int i, j;
    int keyLen = strlen(key);
    int dataLen = strlen(data);

    for(i = 0, j = 0; i < dataLen; ++i, ++j)
    {
        if(j == keyLen)
            j = 0;

        data[i] = (data[i] + key[j]) % 256;
    }
}

void decrypt(char* data, char* key)
{
    int i, j;
    int keyLen = strlen(key);
    int dataLen = strlen(data);

    for(i = 0, j = 0; i < dataLen; ++i, ++j)
    {
        if(j == keyLen)
            j = 0;

        data[i] = (data[i] - key[j] + 256) % 256;
    }
}