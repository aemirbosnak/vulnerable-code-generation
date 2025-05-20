//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 2

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key, int mode)
{
    int i, j;
    char cipher[strlen(message)];

    for (i = 0, j = 0; message[i]!= '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                cipher[j] = (message[i] + key - 65) % 26 + 65;
            }
            else
            {
                cipher[j] = (message[i] + key - 97) % 26 + 97;
            }
            j++;
        }
        else
        {
            cipher[j] = message[i];
            j++;
        }
    }

    cipher[j] = '\0';

    if (mode == ENCRYPT)
    {
        printf("Encrypted message: %s\n", cipher);
    }
    else if (mode == DECRYPT)
    {
        printf("Decrypted message: %s\n", cipher);
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key, int mode)
{
    int i, j;
    char cipher[strlen(message)];

    for (i = 0, j = 0; message[i]!= '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                cipher[j] = (message[i] - key - 65 + 26) % 26 + 65;
            }
            else
            {
                cipher[j] = (message[i] - key - 97 + 26) % 26 + 97;
            }
            j++;
        }
        else
        {
            cipher[j] = message[i];
            j++;
        }
    }

    cipher[j] = '\0';

    if (mode == ENCRYPT)
    {
        printf("Decrypted message: %s\n", cipher);
    }
    else if (mode == DECRYPT)
    {
        printf("Encrypted message: %s\n", cipher);
    }
}

int main()
{
    char message[1000];
    int key, mode, i;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("Enter the mode (1 for encryption, 2 for decryption): ");
    scanf("%d", &mode);

    encrypt(message, key, mode);
    decrypt(message, key, mode);

    return 0;
}