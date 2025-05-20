//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, int key)
{
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char* message, int key)
{
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}