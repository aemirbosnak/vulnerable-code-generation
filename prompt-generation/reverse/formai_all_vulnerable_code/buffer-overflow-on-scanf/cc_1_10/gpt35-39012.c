//FormAI DATASET v1.0 Category: Modern Encryption ; Style: active
#include<stdio.h>
#include<string.h>

void encrypt(char message[], int key)
{
    int len = strlen(message);
    char result[len];
    for (int i=0; i<len; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
           result[i] = (char) ((((int) message[i] - 97 + key) % 26) + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            result[i] = (char) ((((int) message[i] - 65 + key) % 26) + 65);
        }
        else
        {
            result[i] = message[i];
        }
    }
    printf("Encrypted Message: %s\n", result);
}

void decrypt(char message[], int key)
{
    int len = strlen(message);
    char result[len];
    for (int i=0; i<len; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            result[i] = (char) ((((int) message[i] - 97 - key + 26) % 26) + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            result[i] = (char) ((((int) message[i] - 65 - key + 26) % 26) + 65);
        }
        else
        {
            result[i] = message[i];
        }
    }
    printf("Decrypted Message: %s\n", result);
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nEnter message to decrypt: ");
    scanf("%[^\n]", message);
    getchar();

    printf("Enter decryption key: ");
    scanf("%d", &key);

    decrypt(message, key);

    return 0;
}