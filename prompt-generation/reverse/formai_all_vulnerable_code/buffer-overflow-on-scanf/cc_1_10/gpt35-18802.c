//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complex
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//Function to encrypt a message using a substitution cipher
void encrypt(char message[], char key[])
{
    int i, j;
    char encrypted[100];

    //Create a map for substitution cipher
    char map[128];
    for(i=0;i<128;i++)
    {
        map[i] = i;
    }

    //Encrypt the message using the key
    for(i=0;i<strlen(key);i++)
    {
        map[key[i]] = '#';
    }

    j=0;
    for(i=0;i<strlen(message);i++)
    {
        if(isalpha(message[i]))
        {
            encrypted[j] = map[toupper(message[i])];
        }
        else
        {
            encrypted[j] = message[i];
        }
        j++;
    }
    encrypted[j] = '\0';

    printf("Encrypted Message: %s\n", encrypted);
}

//Function to decrypt a message using a substitution cipher
void decrypt(char message[], char key[])
{
    int i, j;
    char decrypted[100];

    //Create a map for substitution cipher
    char map[128];
    for(i=0;i<128;i++)
    {
        map[i] = i;
    }

    //Encrypt the message using the key
    for(i=0;i<strlen(key);i++)
    {
        map[key[i]] = '#';
    }

    for(i=0;i<strlen(message);i++)
    {
        if(isalpha(message[i]))
        {
            for(j=0;j<128;j++)
            {
                if(map[j] == toupper(message[i]))
                {
                    decrypted[i] = j;
                }
            }
        }
        else
        {
            decrypted[i] = message[i];
        }
    }
    decrypted[i] = '\0';

    printf("Decrypted Message: %s\n", decrypted);
}

int main()
{
    char message[100], key[100];
    int choice;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);

    printf("Enter the key for encryption: ");
    scanf(" %[^\n]s", key);

    printf("\nSelect an Option: ");
    printf("\n1. Encrypt Message");
    printf("\n2. Decrypt Message\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: encrypt(message, key);
                break;

        case 2: decrypt(message, key);
                break;

        default: printf("Invalid Choice!");
    }

    return 0;
}