//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("\nEncrypting message...\n");
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    printf("\n\nDecrypting message...\n");
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}

void encrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            
            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            
            message[i] = ch;
        }
    }
}