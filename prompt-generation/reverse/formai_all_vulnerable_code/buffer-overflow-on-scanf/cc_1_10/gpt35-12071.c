//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key, int message_length, int key_length)
{
    int i, j;
    for(i = 0, j = 0; i < message_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }
        message[i] = (message[i] + key[j]) % 26 + 'A'; 
    }
}

void decrypt(char *message, char *key, int message_length, int key_length)
{
    int i, j;
    for(i = 0, j = 0; i < message_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }
        message[i] = (message[i] - key[j] + 26) % 26 + 'A'; 
    }
}

int main()
{
    char message[100];
    char key[100];
    int message_length, key_length;

    printf("Enter the message you want to encrypt: ");
    scanf("%s", message);
    message_length = strlen(message);

    printf("\nEnter the key you want to use for encryption: ");
    scanf("%s", key);
    key_length = strlen(key);

    encrypt(message, key, message_length, key_length);
    printf("\nEncrypted message: %s", message);

    decrypt(message, key, message_length, key_length);
    printf("\nDecrypted message: %s", message);

    return 0;
}