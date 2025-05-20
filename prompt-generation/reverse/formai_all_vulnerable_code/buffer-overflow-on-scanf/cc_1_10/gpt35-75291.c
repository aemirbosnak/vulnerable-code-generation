//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key)
{
    int keylen = strlen(key);
    int plaintextlen = strlen(plaintext);
    int i, j;

    for (i = 0, j = 0; i < plaintextlen; ++i, ++j)
    {
        if (j == keylen)
            j = 0;
        plaintext[i] += key[j];
    }
}

void decrypt(char *ciphertext, char *key)
{
    int keylen = strlen(key);
    int ciphertextlen = strlen(ciphertext);
    int i, j;

    for (i = 0, j = 0; i < ciphertextlen; ++i, ++j)
    {
        if (j == keylen)
            j = 0;
        ciphertext[i] -= key[j];
    }
}

int main()
{
    char plaintext[100], ciphertext[100], key[100];
    int choice;

    printf("Choose an option:\n");
    printf("1. Encrypt a plaintext\n");
    printf("2. Decrypt a ciphertext\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
                printf("Enter plaintext to encrypt (less than 100 characters):\n");
                scanf("%s", plaintext);

                printf("Enter key (less than 100 characters):\n");
                scanf("%s", key);

                encrypt(plaintext, key);

                printf("Encrypted ciphertext: %s\n", plaintext);
                break;

            case 2:
                printf("Enter ciphertext to decrypt (less than 100 characters):\n");
                scanf("%s", ciphertext);

                printf("Enter key (less than 100 characters):\n");
                scanf("%s", key);

                decrypt(ciphertext, key);

                printf("Decrypted plaintext: %s\n", ciphertext);
                break;

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

        printf("Choose an option:\n");
        printf("1. Encrypt a plaintext\n");
        printf("2. Decrypt a ciphertext\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }

    printf("Goodbye!\n");

    return 0;
}