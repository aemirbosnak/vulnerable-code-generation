//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key)
{
    int i;
    for(i=0; i<KEY_SIZE; i++)
    {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext)
{
    int i, j;
    for(i=0, j=0; i<strlen(plaintext); i++)
    {
        if(isalpha(plaintext[i]))
        {
            ciphertext[j++] = (plaintext[i] + key[i % KEY_SIZE]) % 26 + 'a';
        }
        else
        {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext)
{
    int i, j;
    for(i=0, j=0; i<strlen(ciphertext); i++)
    {
        if(isalpha(ciphertext[i]))
        {
            plaintext[j++] = (ciphertext[i] - key[i % KEY_SIZE] + 26) % 26 + 'a';
        }
        else
        {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main()
{
    char plaintext[1000], ciphertext[1000], key[KEY_SIZE];
    generate_key(key);
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}