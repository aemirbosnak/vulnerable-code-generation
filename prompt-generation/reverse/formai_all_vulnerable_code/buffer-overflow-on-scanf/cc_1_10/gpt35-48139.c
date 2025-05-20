//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char arr[], int key)
{
    int len = strlen(arr);

    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = ((arr[i] - 'a') + key) % 26 + 'a';
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = ((arr[i] - 'A') + key) % 26 + 'A';
        }
    }
}

void decrypt(char arr[], int key)
{
    int len = strlen(arr);

    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = ((arr[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = ((arr[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}

int main()
{
    char message[MAX_LEN];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter key for encryption (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}