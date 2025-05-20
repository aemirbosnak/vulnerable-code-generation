//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
    char message[MAX_SIZE];
    int key, choice;
    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin); // read input line
    printf("Select an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    printf("Enter key: ");
    scanf("%d", &key);

    switch (choice)
    {
        case 1: encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
        case 2: decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
        default: printf("Invalid Input\n");
                 break;
    }
    return 0;
}

// Function to encrypt the message
void encrypt(char *message, int key)
{
    int i;
    char ch;
    for(i=0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        // Encrypt only alphabets
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' -1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key)
{
    int i;
    char ch;
    for(i=0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        // Decrypt only alphabets
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}