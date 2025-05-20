//FormAI DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[MAX_LEN], key[MAX_LEN], option;
    int len;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LEN, stdin);
    len = strlen(message);
    message[len-1] = '\0';

    printf("Enter encryption key: ");
    fgets(key, MAX_LEN, stdin);
    len = strlen(key);
    key[len-1] = '\0';

    printf("Choose (e)ncryption or (d)ecryption: ");
    scanf("%c", &option);

    if (option == 'e')
    {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if (option == 'd')
    {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid option\n");
    }

    return 0;
}

void encrypt(char *message, char *key)
{
    int i, j, k;
    int message_len = strlen(message);
    int key_len = strlen(key);

    for (i = 0, j = 0; i < message_len; i++, j++)
    {
        if (j == key_len)
        {
            j = 0;
        }

        k = (message[i] + key[j]) % 26;
        message[i] = k + 'A';
    }
}

void decrypt(char *message, char *key)
{
    int i, j, k;
    int message_len = strlen(message);
    int key_len = strlen(key);

    for (i = 0, j = 0; i < message_len; i++, j++)
    {
        if (j == key_len)
        {
            j = 0;
        }

        k = (message[i] - key[j] + 26) % 26;
        message[i] = k + 'A';
    }
}