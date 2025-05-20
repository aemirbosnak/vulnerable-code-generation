//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; ++i)
    {
        char ch = message[i];

        if(ch >= 'a' && ch <= 'z') // If character is lowercase alphabet
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') // If character is uppercase alphabet
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

void decrypt(char *message, int key)
{
    encrypt(message, 26 - key);
}

int main()
{
    char message[1000];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}