//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter the string which you want to encrypt: ");
    fgets(input, 100, stdin);

    int key;
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    char encrypted[100];
    int i;
    for(i = 0; i < strlen(input); i++)
    {
        char ch = input[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            encrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            encrypted[i] = ch;
        }
        else
        {
            encrypted[i] = ch;
        }
    }

    printf("\n\nEncrypted message: ");
    printf("%s", encrypted);

    char decrypted[100];
    for(i = 0; i < strlen(encrypted); i++)
    {
        char ch = encrypted[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }

            decrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }

            decrypted[i] = ch;
        }
        else
        {
            decrypted[i] = ch;
        }
    }

    printf("\n\nDecrypted message: ");
    printf("%s", decrypted);

    return 0;
}