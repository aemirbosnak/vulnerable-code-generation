//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given string using Caesar cipher
void encrypt(char *message, int key)
{
    int length = strlen(message);
    int i;

    // Iterate through each character in the message
    for(i=0; i<length; i++)
    {
        // If the character is an alphabet
        if(isalpha(message[i]))
        {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Encrypt the character using the key
            int ascii_value = message[i] + key;

            // Check if the encrypted character is a letter
            if(ascii_value > 122)
            {
                ascii_value = ascii_value - 26;
            }
            else if(ascii_value < 65)
            {
                ascii_value = ascii_value + 26;
            }

            message[i] = ascii_value;
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char *message, int key)
{
    int length = strlen(message);
    int i;

    // Iterate through each character in the message
    for(i=0; i<length; i++)
    {
        // If the character is an alphabet
        if(isalpha(message[i]))
        {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Decrypt the character using the key
            int ascii_value = message[i] - key;

            // Check if the decrypted character is a letter
            if(ascii_value < 65)
            {
                ascii_value = ascii_value + 26;
            }
            else if(ascii_value > 122)
            {
                ascii_value = ascii_value - 26;
            }

            message[i] = ascii_value;
        }
    }
}

// Function to generate a random key for encryption and decryption
int generateKey()
{
    int key = rand() % 26;

    // Check if the key is a valid letter
    while(!isalpha(key + 65))
    {
        key = rand() % 26;
    }

    return key;
}

int main()
{
    char message[100];
    int key;

    // Prompt the user to enter a message
    printf("Enter a message: ");
    scanf("%s", message);

    // Generate a random key for encryption and decryption
    key = generateKey();

    // Encrypt the message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}