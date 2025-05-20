//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char key[] = "Secret key";
    char message[] = "This is a secret message";
    int i, j, k, l;
    int encrypt = 0;
    char ciphertext[1024];

    printf("Enter 1 to encrypt, 2 to decrypt: ");
    scanf("%d", &encrypt);

    if (encrypt == 1)
    {
        printf("Enter the message: ");
        scanf("%s", message);

        for (i = 0; message[i] != '\0'; i++)
        {
            k = (key[i % 16] ^ message[i]) & 0xff;
            ciphertext[i] = k;
        }

        printf("Ciphertext: ");
        for (j = 0; ciphertext[j] != '\0'; j++)
        {
            printf("%02x ", ciphertext[j]);
        }

        printf("\n");
    }
    else if (encrypt == 2)
    {
        printf("Enter the ciphertext: ");
        scanf("%s", ciphertext);

        for (i = 0; ciphertext[i] != '\0'; i++)
        {
            k = (key[i % 16] ^ ciphertext[i]) & 0xff;
            message[i] = k;
        }

        printf("Message: ");
        for (j = 0; message[j] != '\0'; j++)
        {
            printf("%c ", message[j]);
        }

        printf("\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}