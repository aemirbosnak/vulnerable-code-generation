//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>

// Function to encrypt the given string using Caesar cipher
void encrypt(char *plain_text, int key)
{
    int i;
    char cipher_text[100];

    strcpy(cipher_text, plain_text);

    // Encrypt the string
    for (i = 0; plain_text[i]!= '\0'; i++)
    {
        if (isalpha(plain_text[i]))
        {
            if (isupper(plain_text[i]))
            {
                cipher_text[i] = (char) (((int) plain_text[i] - 65 + key) % 26 + 65);
            }
            else
            {
                cipher_text[i] = (char) (((int) plain_text[i] - 97 + key) % 26 + 97);
            }
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }

    printf("Encrypted string: %s\n", cipher_text);
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char *cipher_text, int key)
{
    int i;
    char plain_text[100];

    strcpy(plain_text, cipher_text);

    // Decrypt the string
    for (i = 0; cipher_text[i]!= '\0'; i++)
    {
        if (isalpha(cipher_text[i]))
        {
            if (isupper(cipher_text[i]))
            {
                plain_text[i] = (char) (((int) cipher_text[i] - 65 - key + 26) % 26 + 65);
            }
            else
            {
                plain_text[i] = (char) (((int) cipher_text[i] - 97 - key + 26) % 26 + 97);
            }
        }
        else
        {
            plain_text[i] = cipher_text[i];
        }
    }

    printf("Decrypted string: %s\n", plain_text);
}

int main()
{
    char plain_text[100];
    int key;

    // Get the plain text and key from the user
    printf("Enter the plain text: ");
    scanf("%s", plain_text);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the plain text using Caesar cipher
    encrypt(plain_text, key);

    // Decrypt the encrypted text using Caesar cipher
    decrypt(plain_text, key);

    return 0;
}