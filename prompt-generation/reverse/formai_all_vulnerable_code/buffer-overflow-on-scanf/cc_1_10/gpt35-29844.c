//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This program encrypts and decrypts a given message using the caesar cipher */

void encrypt(char message[], int shift);
void decrypt(char message[], int shift);

int main()
{
    char message[100];
    int shift;
    char choice;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a shift value: ");
    scanf("%d", &shift);

    printf("\n");

    // Prompt user to choose an operation
    printf("Choose an operation:\n");
    printf("1) Encrypt\n");
    printf("2) Decrypt\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice)
    {
        case '1':
            encrypt(message, shift);
            break;
        case '2':
            decrypt(message, shift);
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            exit(0);
    }

    return 0;
}

void encrypt(char message[], int shift)
{
    int i;

    for (i = 0; i < strlen(message); i++)
    {
        // Check if character is an alphabet
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (char)(((int)message[i] + shift - 97) % 26 + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (char)(((int)message[i] + shift - 65) % 26 + 65);
        }
    }

    printf("Encrypted message: %s\n", message);
}

void decrypt(char message[], int shift)
{
    int i;

    for (i = 0; i < strlen(message); i++)
    {
        // Check if character is an alphabet
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (char)(((int)message[i] - shift - 97 + 26) % 26 + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (char)(((int)message[i] - shift - 65 + 26) % 26 + 65);
        }
    }

    printf("Decrypted message: %s\n", message);
}