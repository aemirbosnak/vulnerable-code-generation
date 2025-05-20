//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], ciphertext[100], key[100];
    int i, j, msglen, keylen, choice;

    printf("Enter message: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    fgets(key, 100, stdin);

    msglen = strlen(message);
    keylen = strlen(key);

    printf("Choose\n1. Encryption\n2. Decryption\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (i = 0, j = 0; i < msglen; i++, j++)
        {
            if (j == keylen)
            {
                j = 0;
            }
            ciphertext[i] = ((message[i] - 'a' + key[j] - 'a') % 26) + 'a';
        }
        ciphertext[i] = '\0';
        printf("Encrypted message: %s", ciphertext);
    }
    else if (choice == 2)
    {
        for (i = 0, j = 0; i < msglen; i++, j++)
        {
            if (j == keylen)
            {
                j = 0;
            }
            ciphertext[i] = ((message[i] - 'a' - key[j] + 'a') % 26);
            if(ciphertext[i]<0)
            {
                ciphertext[i] += 26;
            }
            ciphertext[i] += 'a';
        }
        ciphertext[i] = '\0';
        printf("Decrypted message: %s", ciphertext);
    }
    else
    {
        printf("Invalid choice!");
    }

    return 0;
}