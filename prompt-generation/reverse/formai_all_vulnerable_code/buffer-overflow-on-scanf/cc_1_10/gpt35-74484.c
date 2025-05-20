//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

void encrypt(char *plain_text, int key)
{
    int i;
    for(i=0; plain_text[i]!='\0'; i++)
    {
        if(plain_text[i]>='a' && plain_text[i]<='z')
        {
            plain_text[i] = (plain_text[i] - 'a' + key) % 26 + 'a';        
        }
        else if(plain_text[i]>='A' && plain_text[i]<='Z')
        {
            plain_text[i] = (plain_text[i] - 'A' + key) % 26 + 'A';
        }
    }
}

void decrypt(char *cipher_text, int key)
{
    int i;
    for(i=0; cipher_text[i]!='\0'; i++)
    {
        if(cipher_text[i]>='a' && cipher_text[i]<='z')
        {
            cipher_text[i] = (cipher_text[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher_text[i]>='A' && cipher_text[i]<='Z')
        {
            cipher_text[i] = (cipher_text[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main()
{
    char plain_text[MAX_SIZE], cipher_text[MAX_SIZE];
    int key;

    printf("Enter the text to be encrypted: ");
    fgets(plain_text, MAX_SIZE, stdin);

    printf("Enter the key: ");
    scanf("%d",&key);

    //Remove newline character from plain_text
    plain_text[strcspn(plain_text, "\n")] = 0;

    encrypt(plain_text, key);

    printf("Encrypted text: %s\n", plain_text);

    decrypt(plain_text, key);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}