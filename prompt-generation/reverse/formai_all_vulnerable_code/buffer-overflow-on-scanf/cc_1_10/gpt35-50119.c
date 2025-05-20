//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int shift);

void decrypt(char message[], int shift);

int main()
{
    int choice, shift;
    char message[100];

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("Enter the shift: ");
    scanf("%d", &shift);

    printf("\nChoose what to do: ");
    printf("\n1. Encrypt message");
    printf("\n2. Decrypt message");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encrypt(message, shift);
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, shift);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}

void encrypt(char message[], int shift)
{
    if(strlen(message) == 0)
    {
        return;
    }
    else
    {
        char c = message[0];
        if(c >= 'a' && c <= 'z')
        {
            c = 'a' + ((c - 'a' + shift) % 26);
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + ((c - 'A' + shift) % 26);
        }
        message[0] = c;
        encrypt(message + 1, shift);
    }   
}

void decrypt(char message[], int shift)
{
    if(strlen(message) == 0)
    {
        return;
    }
    else
    {
        char c = message[0];
        if(c >= 'a' && c <= 'z')
        {
            c = 'a' + ((c - 'a' - shift + 26) % 26);
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + ((c - 'A' - shift + 26) % 26);
        }
        message[0] = c;
        decrypt(message + 1, shift);
    }   
}