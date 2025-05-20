//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], char key[]);
void decrypt(char message[], char key[]);

int main()
{
    char message[100], key[100];
    int choice;

    printf("Enter a message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; //remove newline character from input

    printf("Enter a key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = '\0'; //remove newline character from input

    printf("Choose an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
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

void encrypt(char message[], char key[])
{
    int i, j = 0, k = 0, messageLength = strlen(message), keyLength = strlen(key);
    char encrypted[100];

    for(i = 0; i < messageLength; i++)
    {
        encrypted[i] = (message[i] + key[j]) % 26 + 'A';
        j++;

        if(j == keyLength)
        {
            j = 0;
        }
    }

    encrypted[i] = '\0';
    strcpy(message, encrypted);
}

void decrypt(char message[], char key[])
{
    int i, j = 0, k = 0, messageLength = strlen(message), keyLength = strlen(key);
    char decrypted[100];

    for(i = 0; i < messageLength; i++)
    {
        decrypted[i] = (message[i] - key[j] + 26) % 26 + 'A';
        j++;

        if(j == keyLength)
        {
            j = 0;
        }
    }

    decrypted[i] = '\0';
    strcpy(message, decrypted);
}