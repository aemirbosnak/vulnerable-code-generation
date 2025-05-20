//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void encrypt(char* message, int shift);
void decrypt(char* message, int shift);

int main()
{
    char message[MAX_LEN];
    int shift;
    int choice;

    printf("Enter your message: ");
    fgets(message, MAX_LEN, stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encrypt(message, shift);
            printf("Encrypted message: %s", message);
            break;
        case 2:
            decrypt(message, shift);
            printf("Decrypted message: %s", message);
            break;
        default:
            printf("Invalid option selected.\n");
    }

    return 0;
}

void encrypt(char* message, int shift)
{
    int i = 0;

    while(message[i] != '\0')
    {
        char c = message[i];
        if(c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        
        if(c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        message[i] = c;
        i++;
    }
}

void decrypt(char* message, int shift)
{
    int i = 0;
    while(message[i] != '\0')
    {
        char c = message[i];
        if(c >= 'a' && c <= 'z')
        {
            c = (c - 'a' - shift + 26) % 26 + 'a';
        }
        
        if(c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' - shift + 26) % 26 + 'A';
        }
        message[i] = c;
        i++;
    }
}