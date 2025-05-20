//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 1000

void encrypt(char *message, char *key, int key_size, char *ciphertext)
{
    int i,j;
    char *key_copy;
    int key_index = 0;

    key_copy = (char*)malloc(sizeof(char)*(key_size+1));
    strcpy(key_copy, key);

    for(i=0; message[i]!='\0'; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] + (key_copy[key_index] - 65);
            }
            else
            {
                message[i] = message[i] + (key_copy[key_index] - 97);
            }
        }
        key_index++;
        if(key_index == key_size)
        {
            key_index = 0;
        }
    }

    strcpy(ciphertext, message);
}

void decrypt(char *ciphertext, char *key, int key_size, char *message)
{
    int i,j;
    char *key_copy;
    int key_index = 0;

    key_copy = (char*)malloc(sizeof(char)*(key_size+1));
    strcpy(key_copy, key);

    for(i=0; ciphertext[i]!='\0'; i++)
    {
        if(isalpha(ciphertext[i]))
        {
            if(isupper(ciphertext[i]))
            {
                ciphertext[i] = ciphertext[i] - (key_copy[key_index] - 65);
            }
            else
            {
                ciphertext[i] = ciphertext[i] - (key_copy[key_index] - 97);
            }
        }
        key_index++;
        if(key_index == key_size)
        {
            key_index = 0;
        }
    }

    strcpy(message, ciphertext);
}

int main()
{
    char message[SIZE], key[SIZE], ciphertext[SIZE];
    int key_size;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the key for encryption: ");
    scanf("%s", key);

    printf("Enter the size of the key: ");
    scanf("%d", &key_size);

    encrypt(message, key, key_size, ciphertext);

    printf("\nEncrypted message is: %s\n", ciphertext);

    printf("Enter the key for decryption: ");
    scanf("%s", key);

    decrypt(ciphertext, key, key_size, message);

    printf("\nDecrypted message is: %s\n", message);

    return 0;
}