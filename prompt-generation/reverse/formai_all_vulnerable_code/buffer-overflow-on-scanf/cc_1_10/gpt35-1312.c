//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void performEncryption(char *, char *, int);
void performDecryption(char *, char *, int);

int main()
{
    char message[N], key[N], encryptedMessage[N], decryptedMessage[N];
    int choice, keyLength, i;

    printf("Please enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strlen(message) - 1] = '\0';

    printf("\nPlease enter the key to be used for encryption: ");
    fgets(key, sizeof(key), stdin);
    key[strlen(key) - 1] = '\0';

    keyLength = strlen(key);

    printf("\nPlease select an operation to perform:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        performEncryption(message, key, keyLength);
        printf("\nEncrypted message is: %s\n", message);
        break;
    case 2:
        performDecryption(message, key, keyLength);
        printf("\nDecrypted message is: %s\n", message);
        break;
    default:
        printf("\nInvalid choice!\n");
    }

    return 0;
}

void performEncryption(char *message, char *key, int keyLength)
{
    int i, j = 0;
    char encryptedMessage[N];

    for (i = 0; message[i] != '\0'; i++)
    {
        encryptedMessage[i] = message[i] + key[j];
        j++;
        if (j == keyLength)
        {
            j = 0;
        }
    }
    encryptedMessage[i] = '\0';
    strcpy(message, encryptedMessage);
}

void performDecryption(char *message, char *key, int keyLength)
{
    int i, j = 0;
    char decryptedMessage[N];

    for (i = 0; message[i] != '\0'; i++)
    {
        decryptedMessage[i] = message[i] - key[j];
        j++;
        if (j == keyLength)
        {
            j = 0;
        }
    }
    decryptedMessage[i] = '\0';
    strcpy(message, decryptedMessage);
}