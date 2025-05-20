//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 1024

unsigned char shift_bits(unsigned char byte, int shift)
{
    unsigned char mask = 0x01; // start with mask = 1
    unsigned char result = 0;  // start with result = 0

    for (int i = 0; i < shift; i++)
    {
        if (byte & mask)
        {
            result |= (1 << (7 - i));
        }
        mask <<= 1; // left shift mask by 1 bit
    }

    return result;
}

void encrypt(unsigned char *plaintext, int plaintext_length, unsigned char *key, int key_length)
{
    for (int i = 0; i < plaintext_length; i++)
    {
        int key_index = i % key_length;
        unsigned char shifted_byte = shift_bits(plaintext[i], key[key_index]);
        plaintext[i] = shifted_byte;
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_length, unsigned char *key, int key_length)
{
    for (int i = 0; i < ciphertext_length; i++)
    {
        int key_index = i % key_length;
        unsigned char unshifted_byte = shift_bits(ciphertext[i], -key[key_index]);
        ciphertext[i] = unshifted_byte;
    }
}

int main()
{
    char plaintext[STRING_SIZE];
    char key[STRING_SIZE];
    int choice, plaintext_length = 0, key_length = 0;

    printf("Enter a message to encrypt: ");
    fgets(plaintext, STRING_SIZE, stdin);

    printf("Enter a key to use for encryption: ");
    fgets(key, STRING_SIZE, stdin);

    plaintext_length = strlen(plaintext) - 1; // remove newline character
    key_length = strlen(key) - 1;            // remove newline character

    printf("1. Encrypt\n2. Decrypt\nChoose an option: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        encrypt((unsigned char *)plaintext, plaintext_length, (unsigned char *)key, key_length);
        printf("Encrypted message: %s\n", plaintext);
        break;
    case 2:
        decrypt((unsigned char *)plaintext, plaintext_length, (unsigned char *)key, key_length);
        printf("Decrypted message: %s\n", plaintext);
        break;
    default:
        printf("Invalid choice!\n");
    }

    return 0;
}