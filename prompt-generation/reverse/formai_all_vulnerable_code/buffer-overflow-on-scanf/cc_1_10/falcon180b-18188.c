//Falcon-180B DATASET v1.0 Category: Encryption ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *message, int key)
{
    int i, j, n;
    char cipher[100];
    n = strlen(message);
    for(i=0,j=0;i<n;i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] + key;
                if(message[i]>'Z')
                {
                    message[i] = message[i] - 26;
                }
            }
            else
            {
                message[i] = message[i] + key;
                if(message[i]>'z')
                {
                    message[i] = message[i] - 26;
                }
            }
        }
        else
        {
            cipher[j] = message[i];
            j++;
        }
    }
    cipher[j] = '\0';
    printf("Encrypted message: %s\n", cipher);
}

void decrypt(char *message, int key)
{
    int i, j, n;
    char plain[100];
    n = strlen(message);
    for(i=0,j=0;i<n;i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] - key;
                if(message[i]<'A')
                {
                    message[i] = message[i] + 26;
                }
            }
            else
            {
                message[i] = message[i] - key;
                if(message[i]<'a')
                {
                    message[i] = message[i] + 26;
                }
            }
        }
        else
        {
            plain[j] = message[i];
            j++;
        }
    }
    plain[j] = '\0';
    printf("Decrypted message: %s\n", plain);
}

int main()
{
    char message[100];
    int key, choice;
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%d", &key);
    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);
    if(choice==1)
    {
        encrypt(message, key);
    }
    else if(choice==2)
    {
        decrypt(message, key);
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}