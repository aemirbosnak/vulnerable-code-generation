//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt using Caesar Cipher
void encrypt(char* message, int key)
{
    char ch;
    for(int i=0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        // Encrypt only alphabets
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
                ch = ch - 'z' + 'a' - 1;

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if (ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;

            message[i] = ch;
        }
    }
}

// function to decrypt using Caesar Cipher
void decrypt(char* message, int key)
{
    char ch;
    for(int i=0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        // Decrypt only alphabets
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if(ch < 'a')
                ch = ch + 'z' - 'a' + 1;

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if(ch < 'A')
                ch = ch + 'Z' - 'A' + 1;

            message[i] = ch;
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}