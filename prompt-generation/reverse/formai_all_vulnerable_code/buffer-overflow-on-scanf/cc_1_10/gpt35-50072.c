//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter a message to encrypt/decrypt (maximum %d characters): ", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);

    printf("\nEnter a secret key: ");
    scanf("%d", &key);

    printf("\nSelect an option:\n 1. Encrypt message\n 2. Decrypt message\n");
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
            printf("\nInvalid choice! Please choose an option between 1 and 2.\n");
            break;
    }

    return 0;
}

void encrypt(char *message, int key)
{
    int i, c;

    for (i = 0; message[i] != '\0'; i++)
    {
        c = message[i];

        if (isalpha(c))
        {
            c = tolower(c);
            c = ((c - 'a') + key) % 26 + 'a';
        }

        message[i] = c;
    }
}

void decrypt(char *message, int key)
{
    int i, c;

    for (i = 0; message[i] != '\0'; i++)
    {
        c = message[i];

        if (isalpha(c))
        {
            c = tolower(c);
            c = ((c - 'a') - key + 26) % 26 + 'a';
        }

        message[i] = c;
    }
}