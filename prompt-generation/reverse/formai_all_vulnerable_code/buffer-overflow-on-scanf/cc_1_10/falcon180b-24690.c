//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void vigenere_cipher(char plaintext[], char key[], char ciphertext[])
{
    int i, j, k, n, m, shift;
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    n = strlen(plaintext);
    m = strlen(key);
    k = 0;

    for (i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                j = toupper(plaintext[i]) - 'A';
                k = toupper(key[k % m]) - 'A';
            }
            else
            {
                j = tolower(plaintext[i]) - 'a';
                k = tolower(key[k % m]) - 'a';
            }

            shift = (j + k) % 26;
            ciphertext[i] = alpha[shift];
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }

        k++;
    }

    ciphertext[n] = '\0';
}

int main()
{
    char plaintext[100], key[100], ciphertext[200];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    vigenere_cipher(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}