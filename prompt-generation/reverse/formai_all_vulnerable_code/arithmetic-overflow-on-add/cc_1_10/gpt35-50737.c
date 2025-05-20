//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function prototypes 
void encryption(char [], int);
void decryption(char [], int);

// Main function
int main()
{
    char message[100];
    int choice, key;
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    printf("Choose an option:\n");
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Choice: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        encryption(message, key);       // calling encryption function
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 2)
    {
        decryption(message, key);       // calling decryption function
        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid choice!");
    }
    return 0;
}

// Encryption function
void encryption(char message[], int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
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

// Decryption function
void decryption(char message[], int key)
{   
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
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