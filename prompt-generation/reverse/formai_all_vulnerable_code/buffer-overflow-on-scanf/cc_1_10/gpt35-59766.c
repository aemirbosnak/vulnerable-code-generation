//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the encryption function
void encrypt(char *plaintext, char *key)
{
    int plaintextLength = strlen(plaintext), keyLength = strlen(key), i;
    char ciphertext[plaintextLength];
    
    // Encrypt each character of the plaintext
    for(i = 0; i < plaintextLength; i++)
    {
        ciphertext[i] = ((plaintext[i] + key[i % keyLength]) % 26) + 'A';
    }
    
    // Print the encrypted ciphertext
    printf("\nEncrypted Message: %s\n", ciphertext);
}

// This is the decryption function
void decrypt(char *ciphertext, char *key)
{
    int ciphertextLength = strlen(ciphertext), keyLength = strlen(key), i;
    char plaintext[ciphertextLength];
    
    // Decrypt each character of the ciphertext
    for(i = 0; i < ciphertextLength; i++)
    {
        plaintext[i] = (((ciphertext[i] - key[i % keyLength]) + 26) % 26) + 'A';
    }
    
    // Print the decrypted plaintext
    printf("\nDecrypted Message: %s\n", plaintext);
}

int main()
{
    char plaintext[100], key[100];
    
    // Prompt the user for the plaintext and key
    printf("Enter plaintext: ");
    scanf("%[^\n]", plaintext);
    
    printf("Enter key: ");
    scanf(" %[^\n]", key);
    
    // Encrypt the plaintext with the key
    encrypt(plaintext, key);
    
    // Decrypt the encrypted ciphertext with the same key
    decrypt("UHOMNOKZQAQNUHOMX", key);
    
    return 0;
}