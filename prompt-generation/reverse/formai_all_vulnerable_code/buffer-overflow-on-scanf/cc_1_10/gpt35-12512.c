//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void encrypt(char*, int);

int main()
{
    char input[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(input, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(input, key);

    printf("Encrypted message: %s\n", input);

    return 0;
}

void encrypt(char* message, int key)
{
    int i, sum = 0, index;
    char encrypted[100];

    for(i = 0; i < strlen(message); i++)
    {
        sum += (int)message[i]; //Calculate sum of ASCII values
    }

    index = sum % 26; //Calculate shift index

    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z') //Encrypt lower case letters
        {
            encrypted[i] = 'a' + (message[i] - 'a' + index) % 26;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') //Encrypt upper case letters
        {
            encrypted[i] = 'A' + (message[i] - 'A' + index) % 26;
        }
        else //Do not encrypt other characters
        {
            encrypted[i] = message[i];
        }
    }

    strcpy(message, encrypted); //Copy encrypted message to original message array
}