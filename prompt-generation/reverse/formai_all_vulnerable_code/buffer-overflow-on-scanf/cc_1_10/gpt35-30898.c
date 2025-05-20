//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

// Function prototype declarations
void encrypt(char *plaintext, unsigned char *key, int size);
void decrypt(char *ciphertext, unsigned char *key, int size);
void generate_key(unsigned char *key);

int main()
{
    char message[256];
    unsigned char key[KEY_SIZE];

    printf("Enter a message to be encrypted: ");
    scanf("%s", message);

    generate_key(key);

    encrypt(message, key, strlen(message));
    printf("Encrypted message: %s\n", message);

    decrypt(message, key, strlen(message));
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *plaintext, unsigned char *key, int size)
{
    unsigned char block[BLOCK_SIZE];
    unsigned char keystream[BLOCK_SIZE];
    int i, j;

    // Initialize block and keystream
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        block[i] = 0;
        keystream[i] = 0;
    }

    // Encrypt each block of plaintext
    for (i = 0; i < size; i += BLOCK_SIZE)
    {
        // Increment block counter
        for (j = 0; j < BLOCK_SIZE && (i + j) < size; j++)
        {
            block[j] ^= plaintext[i + j];
        }

        // Generate keystream using key and block
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            keystream[j] = key[j] ^ block[j];
        }

        // XOR plaintext with keystream to get ciphertext
        for (j = 0; j < BLOCK_SIZE && (i + j) < size; j++)
        {
            plaintext[i + j] ^= keystream[j];
        }

        // Reset block for next iteration
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            block[j] = 0;
        }
    }
}

void decrypt(char *ciphertext, unsigned char *key, int size)
{
    encrypt(ciphertext, key, size);
}

void generate_key(unsigned char *key)
{
    srand(time(NULL));

    // Generate random key
    for (int i = 0; i < KEY_SIZE; i++)
    {
        key[i] = rand() % 256;
    }
}