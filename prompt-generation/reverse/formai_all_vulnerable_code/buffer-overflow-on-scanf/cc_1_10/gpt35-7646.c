//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encryption Key */
const int key = 5;

/* Function to encrypt the input message */
void encrypt(char message[])
{
    int i;
    int length = strlen(message);

    for (i = 0; i < length; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] + key - 97) % 26 + 97;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] + key - 65) % 26 + 65;
        }
    }
}

/* Function to decrypt the encoded message */
void decrypt(char message[])
{
    int i;
    int length = strlen(message);

    for (i = 0; i < length; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - key + 26) % 26 + 97;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - key + 26) % 26 + 65;
        }
    }
}

/* Main function that takes user input and encrypts or decrypts the message*/
int main()
{
    char message[100];
    int choice;

    printf("Enter message to encrypt or decrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        encrypt(message);
        printf("Encrypted message: %s", message);
    }
    else if (choice == 2)
    {
        decrypt(message);
        printf("Decrypted message: %s", message);
    }
    else
    {
        printf("Invalid choice! Please enter 1 or 2.");
    }

    return 0;
}