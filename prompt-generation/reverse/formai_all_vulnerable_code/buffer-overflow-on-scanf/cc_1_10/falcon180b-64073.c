//Falcon-180B DATASET v1.0 Category: Encryption ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define LENGTH 256

char *encrypt(char *message, char *key);
char *decrypt(char *message, char *key);

int main()
{
    char message[1000], key[100];
    int choice, length;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    length = strlen(message);

    if(length > LENGTH)
    {
        printf("Message is too long. Please enter a message with less than %d characters.\n", LENGTH);
        return 0;
    }

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Encrypted message: %s\n", encrypt(message, key));
            break;

        case 2:
            printf("Decrypted message: %s\n", decrypt(message, key));
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

char *encrypt(char *message, char *key)
{
    int i, j, k, length;
    char *result = (char *)malloc(LENGTH * sizeof(char));

    length = strlen(message);

    for(i = 0, j = 0; i < length; i++)
    {
        if(isalpha(message[i]))
        {
            result[j] = tolower(message[i]) + tolower(key[i % strlen(key)]);
            j++;
        }
        else
        {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

char *decrypt(char *message, char *key)
{
    int i, j, k, length;
    char *result = (char *)malloc(LENGTH * sizeof(char));

    length = strlen(message);

    for(i = 0, j = 0; i < length; i++)
    {
        if(isalpha(message[i]))
        {
            result[j] = (tolower(message[i]) - tolower(key[i % strlen(key)])) % 26 + 'a';
            j++;
        }
        else
        {
            result[j] = message[i];
            j++;
        }
    }

    result[j] = '\0';

    return result;
}