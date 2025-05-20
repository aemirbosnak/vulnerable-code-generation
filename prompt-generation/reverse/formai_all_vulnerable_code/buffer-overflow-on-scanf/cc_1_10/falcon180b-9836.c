//Falcon-180B DATASET v1.0 Category: Encryption ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 1000

void encrypt(char *message, int key)
{
    int i, j, n = strlen(message);
    for(i = 0; i < n; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            }
            else
            {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

void decrypt(char *message, int key)
{
    int i, j, n = strlen(message);
    for(i = 0; i < n; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            }
            else
            {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

int main()
{
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("Enter your choice (1 for encryption, 2 for decryption): ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 2)
    {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}