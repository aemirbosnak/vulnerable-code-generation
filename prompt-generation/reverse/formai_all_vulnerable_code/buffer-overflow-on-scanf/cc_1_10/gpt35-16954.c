//FormAI DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main(void)
{
    char message[100], c;
    int key, choice;

    printf("Please enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Please enter a key for encryption: ");
    scanf("%d", &key);

    printf("\nPlease choose an option: \n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    return 0;
}

void encrypt(char *message, int key)
{
    int i;

    for (i = 0; message[i] != '\0'; ++i)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] + key;
            
            if (message[i] > 'z')
            {
                message[i] = message[i] - 'z' + 'a' - 1;
            }
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + key;
            
            if (message[i] > 'Z')
            {
                message[i] = message[i] - 'Z' + 'A' - 1;
            }
        }
    }

    printf("\nEncrypted message: %s\n", message);
}

void decrypt(char *message, int key)
{
    int i;

    for (i = 0; message[i] != '\0'; ++i)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - key;

            if (message[i] < 'a')
            {
                message[i] = message[i] + 'z' - 'a' + 1;
            }
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] - key;

            if (message[i] < 'A')
            {
                message[i] = message[i] + 'Z' - 'A' + 1;
            }
        }
    }

    printf("\nDecrypted message: %s\n", message);
}