//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key length which will be used for encryption and decryption
#define KEY_LENGTH 16

// Define the function prototypes
void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[1024], key[KEY_LENGTH];
    int choice;

    do
    {
        printf("\n\t Romantic Cryptography \n");
        printf("------------------------------------------\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
            case 1:
                printf("\nEnter the message to be encrypted: ");
                fgets(message, sizeof(message), stdin);
                printf("Enter the key for encryption (16 characters): ");
                fgets(key, sizeof(key), stdin);
                encrypt(message, key);
                printf("\nEncrypted message: %s", message);
                break;

            case 2:
                printf("\nEnter the message to be decrypted: ");
                fgets(message, sizeof(message), stdin);
                printf("Enter the key for decryption (16 characters): ");
                fgets(key, sizeof(key), stdin);
                decrypt(message, key);
                printf("\nDecrypted message: %s", message);
                break;

            case 3:
                printf("\nThank you for using Romantic Cryptography. Have a nice day!");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 3);

    return 0;
}

void encrypt(char *message, char *key)
{
    int i, j = 0;
    for (i = 0; message[i] != '\0'; ++i)
    {
        if (j == KEY_LENGTH)
        {
            j = 0;
        }

        message[i] = (message[i] ^ key[j]);
        ++j;
    }
}

void decrypt(char *message, char *key)
{
    encrypt(message, key);
}