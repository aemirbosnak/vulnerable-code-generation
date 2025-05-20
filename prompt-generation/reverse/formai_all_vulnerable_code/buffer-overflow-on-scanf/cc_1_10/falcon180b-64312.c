//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void shift(char *message, int key)
{
    int i;
    for(i=0; message[i]!='\0'; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                char temp = message[i];
                message[i] = (message[i] - key - 65) % 26 + 65;
                if(message[i] < 65)
                {
                    message[i] += 26;
                }
            }
            else
            {
                char temp = message[i];
                message[i] = (message[i] - key - 97) % 26 + 97;
                if(message[i] < 97)
                {
                    message[i] += 26;
                }
            }
        }
        else
        {
            message[i] = message[i];
        }
    }
}

void encrypt(char *message, int key)
{
    shift(message, key);
}

void decrypt(char *message, int key)
{
    shift(message, 26 - key);
}

int main()
{
    char message[100], key;
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("\nOriginal Message: %s\n", message);

    encrypt(message, key);

    printf("Encrypted Message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted Message: %s\n", message);

    return 0;
}