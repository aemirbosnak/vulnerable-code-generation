//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char *input, int key);

int main()
{
    char input[100], ch;
    int key, choice;
  
    printf("Enter a string to encrypt: \n");
    fgets(input, 100, stdin);

    printf("Enter an encryption key (1-25): ");
    scanf("%d", &key);

    encrypt(input, key);

    printf("\nEncrypted string: %s", input);

    return 0;
}

void encrypt(char *input, int key)
{
    int i;
    char ch;

    for(i = 0; i < strlen(input); i++)
    {
        ch = input[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            input[i] = ch;
        }
    }
}