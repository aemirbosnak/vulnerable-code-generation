//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 26

void init_key(char *key)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(isalpha(key[i]))
            key[i] = tolower(key[i]);
        else
            key[i] = 'a';
    }
}

void encrypt(char *key, char *message)
{
    int i;
    for(i=0;message[i]!='\0';i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
                message[i] = (message[i]-65+13)%26+65;
            else
                message[i] = (message[i]-97+13)%26+97;
        }
        else
            message[i] = message[i];
    }
}

void decrypt(char *key, char *message)
{
    int i;
    for(i=0;message[i]!='\0';i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
                message[i] = (message[i]-65-13+26)%26+65;
            else
                message[i] = (message[i]-97-13+26)%26+97;
        }
        else
            message[i] = message[i];
    }
}

int main()
{
    char key[SIZE];
    char message[1000];
    char choice;
    int length;

    printf("Enter the message to be encrypted/decrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (26 lowercase letters): ");
    fgets(key, sizeof(key), stdin);

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c",&choice);

    init_key(key);

    if(choice == 'e')
    {
        encrypt(key, message);
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 'd')
    {
        decrypt(key, message);
        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}