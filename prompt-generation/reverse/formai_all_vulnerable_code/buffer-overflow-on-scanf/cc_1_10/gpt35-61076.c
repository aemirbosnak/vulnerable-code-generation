//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define P 17               // Prime number P (greater than 2)
#define G 3                // Generator G (between 2 and P-1)
#define PRIVATE_KEY_MAX 10 // Max private key value
#define MESSAGE_MAX 100    // Max message length

// Calculates G^x mod P
int power_modulo(int base, int exponent, int divisor)
{
    int result = 1;
    for(int i=0;i<exponent;i++)
        result = (result * base) % divisor;
    return result;
}

// Generates a random private key
int generate_private_key(int max_value)
{
    srand(time(0));
    return (rand() % max_value) + 1; // Random value between 1 and max value (inclusive)
}

// Encrypts message using public key (y,g,p)
void encrypt_message(int private_key, int y, int g, int p, char* message)
{
    int len = strlen(message);

    // Allocating memory dynamically for storing encrypted message
    int* encrypted_message = (int*) malloc(len * sizeof(int));

    for(int i=0;i<len;i++)
    {
        int encrypted_char = (power_modulo(y, private_key, p) * (int) message[i]) % p;
        encrypted_message[i] = encrypted_char;
    }

    // Printing encrypted message
    printf("Encrypted Message: ");
    for(int i=0;i<len;i++)
    {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

}

// Decrypts encrypted message using private key and public key (g,p)
void decrypt_message(int* encrypted_message, int private_key, int g, int p, int len)
{
    // Allocating memory dynamically for storing decrypted message
    char* decrypted_message = (char*) malloc(len * sizeof(char));

    for(int i=0;i<len;i++)
    {
        int decrypted_char = (encrypted_message[i] * power_modulo(g, p-1-private_key, p)) % p;
        decrypted_message[i] = (char) decrypted_char;
    }

    // Printing decrypted message
    printf("Decrypted Message: ");
    for(int i=0;i<len;i++)
    {
        printf("%c", decrypted_message[i]);
    }
    printf("\n");
}

int main()
{
    // Generating private key
    int private_key = generate_private_key(PRIVATE_KEY_MAX);

    // Calculating public key
    int public_key = power_modulo(G, private_key, P);

    printf("Public key: %d\n", public_key);

    // Reading message to be encrypted
    char message[MESSAGE_MAX];
    printf("Enter a message to encrypt: ");
    fgets(message, MESSAGE_MAX, stdin);

    // Removing trailing newline character, if any
    int len = strlen(message);
    if (message[len-1] == '\n')
    {
        message[len-1] = '\0';
        len--;
    }

    // Encrypting message
    encrypt_message(private_key, public_key, G, P, message);

    // Decrypting message
    printf("Enter the encrypted message: ");
    int encrypted_message[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d", &encrypted_message[i]);
    }
    decrypt_message(encrypted_message, private_key, G, P, len);

    return 0;
}