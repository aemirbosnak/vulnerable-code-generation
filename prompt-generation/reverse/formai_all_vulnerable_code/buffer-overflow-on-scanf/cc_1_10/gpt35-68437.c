//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char key[5], plaintext[100], ciphertext[100];
    int i, j, key_len, plaintext_len, ciphertext_len;

    printf("Enter the encryption key (4 characters only): ");
    scanf("%s", &key);

    key_len = strlen(key);

    while(key_len != 4)
    {
        printf("Invalid key length. Please enter 4 characters only: ");
        scanf("%s", &key);
        key_len = strlen(key);
    }

    printf("Enter the plaintext message to be encrypted: ");
    scanf("%s", &plaintext);

    plaintext_len = strlen(plaintext);
    ciphertext_len = plaintext_len;

    for(i = 0; i < plaintext_len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    printf("Ciphertext message: ");

    for(i = 0; i < ciphertext_len; i++)
    {
        printf("%02X", (unsigned char) ciphertext[i]);
    }

    printf("\n");

    printf("Decrypted message: ");

    for(i = 0; i < ciphertext_len; i++)
    {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
        printf("%c", plaintext[i]);
    }

    printf("\n");

    return 0;
}