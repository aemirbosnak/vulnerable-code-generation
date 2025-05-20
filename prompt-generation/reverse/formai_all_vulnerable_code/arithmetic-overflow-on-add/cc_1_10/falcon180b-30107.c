//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void encrypt(char message[], int key)
{
    int i, j;
    char encrypted_message[SIZE];

    for(i=0, j=0; message[i]!='\0'; i++, j++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                encrypted_message[j] = ((message[i]-65+key)%26) + 65;
            }
            else
            {
                encrypted_message[j] = ((message[i]-97+key)%26) + 97;
            }
        }
        else
        {
            encrypted_message[j] = message[i];
        }
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char message[], int key)
{
    int i, j;
    char decrypted_message[SIZE];

    for(i=0, j=0; message[i]!='\0'; i++, j++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                decrypted_message[j] = ((message[i]-65-key+26)%26) + 65;
            }
            else
            {
                decrypted_message[j] = ((message[i]-97-key+26)%26) + 97;
            }
        }
        else
        {
            decrypted_message[j] = message[i];
        }
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main()
{
    char message[SIZE];
    int key;

    printf("Enter a message: ");
    fgets(message, SIZE, stdin);

    printf("Enter a key (between 0 and 25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}