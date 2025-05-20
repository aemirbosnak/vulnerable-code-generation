//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void encrypt(char *key, char *plaintext, char *ciphertext)
{
    int i, j;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char *ptr = plaintext;
    char *ptr2 = ciphertext;

    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = tolower(plaintext[i]);
            }

            j = 0;

            while (key[j]!= plaintext[i])
            {
                j++;
            }

            strncat(ciphertext, &alphabet[j], 1);
        }
        else
        {
            strncat(ciphertext, &plaintext[i], 1);
        }

        ptr++;
        ptr2++;
    }
}

void decrypt(char *key, char *ciphertext, char *plaintext)
{
    int i, j;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char *ptr = ciphertext;
    char *ptr2 = plaintext;

    for (i = 0; i < strlen(ciphertext); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            j = 0;

            while (key[j]!= ciphertext[i])
            {
                j++;
            }

            plaintext[i] = alphabet[j];
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }

        ptr++;
        ptr2++;
    }
}

int main()
{
    char plaintext[SIZE], ciphertext[SIZE], key[SIZE];
    int i, choice;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        encrypt(key, plaintext, ciphertext);
        printf("Ciphertext: %s\n", ciphertext);
    }
    else if (choice == 2)
    {
        decrypt(key, ciphertext, plaintext);
        printf("Plaintext: %s\n", plaintext);
    }

    return 0;
}