//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char key[], char message[]);
void decrypt(char key[], char message[]);

int main()
{
    char key[100];
    char message[100];
    int choice;

    printf("Welcome to the Puzzling Encryption!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a message.\n");
    printf("2. Decrypt a message.\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the message to be encrypted: ");
            scanf("%s", message);
            printf("Enter the encryption key: ");
            scanf("%s", key);
            encrypt(key, message);
            printf("The encrypted message is: %s\n", message);
            break;

        case 2:
            printf("Enter the message to be decrypted: ");
            scanf("%s", message);
            printf("Enter the decryption key: ");
            scanf("%s", key);
            decrypt(key, message);
            printf("The decrypted message is: %s\n", message);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

void encrypt(char key[], char message[])
{
    int i, j, k = 0;
    int kl = strlen(key), ml = strlen(message);
    char encrypted[100];

    for(i=0; i<ml; i++)
    {
        j = k % kl;
        encrypted[i] = message[i] + key[j];
        k++;
    }

    encrypted[i] = '\0';
    strcpy(message, encrypted);
}

void decrypt(char key[], char message[])
{
    int i, j, k = 0;
    int kl = strlen(key), ml = strlen(message);
    char decrypted[100];

    for(i=0; i<ml; i++)
    {
        j = k % kl;
        decrypted[i] = message[i] - key[j];
        k++;
    }

    decrypted[i] = '\0';
    strcpy(message, decrypted);
}