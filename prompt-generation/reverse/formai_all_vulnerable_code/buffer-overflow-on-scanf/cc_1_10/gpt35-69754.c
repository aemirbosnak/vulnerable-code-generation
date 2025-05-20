//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

void generateKey(char *key, int length);
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main()
{
    char key[MAX_SIZE], plaintext[MAX_SIZE], ciphertext[MAX_SIZE], decrypted[MAX_SIZE];
    int choice, length;

    printf("Enter the length of the key (max 100 characters): ");
    scanf("%d", &length);

    generateKey(key, length);

    printf("Key: %s\n", key);

    printf("\nEnter plaintext to encrypt: ");
    getchar(); //Consume newline
    fgets(plaintext, MAX_SIZE, stdin);

    encrypt(plaintext, key, ciphertext);
    printf("\nEncrypted ciphertext: %s", ciphertext);

    decrypt(ciphertext, key, decrypted);
    printf("\nDecrypted plaintext: %s", decrypted);

    return 0;
}

void generateKey(char *key, int length)
{
    int i;

    for(i = 0; i < length; i++)
    {
        int random = rand() % 26;
        key[i] = 'a' + random;
    }

    key[i] = '\0';
}

void encrypt(char *plaintext, char *key, char *ciphertext)
{
    int i;

    for(i = 0; i < strlen(plaintext); i++)
    {
        if(plaintext[i] == '\n') // Remove newline
        {
            continue;
        }

        plaintext[i] = tolower(plaintext[i]);

        int p = plaintext[i] - 'a';
        int k = key[i] - 'a';

        int c = (p + k) % 26;

        ciphertext[i] = 'a' + c;
    }

    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext)
{
    int i;

    for(i = 0; i < strlen(ciphertext); i++)
    {
        int c = ciphertext[i] - 'a';
        int k = key[i] - 'a';

        int p = (c - k + 26) % 26;

        plaintext[i] = 'a' + p;
    }

    plaintext[i] = '\0';
}