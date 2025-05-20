//FormAI DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>

// Function to encrypt the message
void encrypt(char message[], int key)
{
    int i = 0;
    char ch;

    // Loop through each character and shift its ASCII value
    while (message[i] != '\0')
    {
        ch = message[i];

        // Shift only for uppercase and lowercase English alphabets
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        i++;
    }
}

// Function to decrypt the message
void decrypt(char message[], int key)
{
    int i = 0;
    char ch;

    // Loop through each character and shift its ASCII value
    while (message[i] != '\0')
    {
        ch = message[i];

        // Shift only for uppercase and lowercase English alphabets
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }

        i++;
    }
}

int main()
{
    int key;
    char message[100];

    printf("Enter the message you want to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}