//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 128

void encrypt(char* message, int shift);

int main()
{
    char message[MAX_SIZE];
    int shift;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("\nEncrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, int shift)
{
    int len = strlen(message);

    for(int i = 0; i < len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        else if(message[i] == '\n') // remove newline character
        {
            message[i] = '\0';
        }
    }

    if(len > 0)
    {
        encrypt(message+1, shift);
    }
}