//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char str[], int key);
void decrypt(char str[], int key);

int main() 
{
    char message[1000];
    int key, choice;

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("Do you want to encrypt or decrypt the message?\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1: 
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;

        case 2: 
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;

        default: 
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

void encrypt(char str[], int key) 
{
    for(int i = 0; i < strlen(str); ++i) 
    {
        str[i] = str[i] + key;
    }
}

void decrypt(char str[], int key) 
{
    for(int i = 0; i < strlen(str); ++i) 
    {
        str[i] = str[i] - key;
    }
}