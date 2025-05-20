//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000

int getKey()
{
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    return key;
}

void encrypt(char* message, int key)
{
    int i=0;
    char ch;
    while( message[i] )
    {
        ch = message[i];
        if(ch>='a' && ch<='z')
        {
            ch += key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch>='A' && ch<='Z')
        {
            ch += key;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        i++;
    }
}

void decrypt(char* message, int key)
{
    int i=0;
    char ch;
    while( message[i] )
    {
        ch = message[i];
        if(ch>='a' && ch<='z')
        {
            ch -= key;
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch>='A' && ch<='Z')
        {
            ch -= key;
            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        i++;
    }
}

int main()
{
    char message[MAX_LEN];
    int choice, key;
    printf("Enter message: ");
    fgets(message, MAX_LEN, stdin);
    printf("1: Encrypt\n2: Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            key = getKey();
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;

        case 2:
            key = getKey();
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}