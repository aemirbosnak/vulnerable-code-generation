//FormAI DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 50

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main()
{
    char message[MAX_CHARS];
    int key = 0;
    int choice = 0;

    printf("Welcome to Retro Encryption!\n");

    while(choice != 3)
    {
        printf("\nPlease choose an option:\n\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Quit\n\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter your message to encrypt (maximum of 50 characters):\n");
                scanf(" %[^\n]s", message);
                printf("Enter a key value (1-9): ");
                scanf("%d", &key);

                encrypt(message, key);
                printf("\nEncrypted message: %s\n", message);
                break;

            case 2:
                printf("\nEnter the message to decrypt:\n");
                scanf(" %[^\n]s", message);
                printf("Enter the key value: ");
                scanf("%d", &key);

                decrypt(message, key);
                printf("\nDecrypted message: %s\n", message);
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}

void encrypt(char* message, int key)
{
    srand(time(NULL));
    int shift = rand() % 26;

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') + key + shift) % 26 + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') + key + shift) % 26 + 'a';
        }
    }
}

void decrypt(char* message, int key)
{
    srand(time(NULL));
    int shift = rand() % 26;

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') - key - shift + 26) % 26 + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') - key - shift + 26) % 26 + 'a';
        }
    }
}