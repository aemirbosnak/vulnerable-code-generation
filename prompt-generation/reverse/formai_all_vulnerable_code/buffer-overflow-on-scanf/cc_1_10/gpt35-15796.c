//FormAI DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main()
{
    char message[MAX_LEN];
    int key = 0, choice = 0;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("\nChoose from the following options:\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
    }

    return 0;
}

void encrypt(char message[], int key)
{
    int i = 0;
    char ch;

    while (message[i] != '\0')
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

        i++;
    }
}

void decrypt(char message[], int key)
{
    int i = 0;
    char ch;

    while (message[i] != '\0')
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

        i++;
    }
}