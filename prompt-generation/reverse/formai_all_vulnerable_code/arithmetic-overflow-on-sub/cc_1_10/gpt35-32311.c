//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Function to encrypt the message
void encrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] + key <= 'z')
        {
            message[i] = message[i] + key;
        }
        else
        {
            message[i] = message[i] + key - 'z' + 'a' - 1;
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] - key >= 'a')
        {
            message[i] = message[i] - key;
        }
        else
        {
            message[i] = message[i] - key + 'z' - 'a' + 1;
        }
    }
}

int main()
{
    int choice, key;
    char message[MAX];

    while(1)
    {
        printf("\nChoose an option:");
        printf("\n1. Encrypt a message");
        printf("\n2. Decrypt a message");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter message to encrypt: ");
            scanf(" %[^\n]", message);
            printf("Enter key: ");
            scanf("%d", &key);
            encrypt(message, key);
            printf("\nEncrypted message: %s", message);
            break;
        
        case 2:
            printf("\nEnter message to decrypt: ");
            scanf(" %[^\n]", message);
            printf("Enter key: ");
            scanf("%d", &key);
            decrypt(message, key);
            printf("\nDecrypted message: %s", message);
            break;

        case 3:
            printf("\nExiting program...");
            exit(0);
            break;
        
        default:
            printf("\nInvalid choice!");
            break;
        }
    }
    return 0;
}