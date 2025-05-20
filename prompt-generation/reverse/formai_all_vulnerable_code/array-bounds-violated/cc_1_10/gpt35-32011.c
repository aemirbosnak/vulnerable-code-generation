//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, char *key);

int main()
{
    char message[1000], key[1000];
    
    printf("Enter the message to be encrypted: ");
    fgets(message, 1000, stdin);
    // replace newline character with null character
    message[strlen(message)-1] = '\0';
    
    printf("Enter the key to encrypt the message: ");
    fgets(key, 1000, stdin);
    // replace newline character with null character
    key[strlen(key)-1] = '\0';
    
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, char *key)
{
    int keyIndex, messageIndex;
    for (messageIndex = 0, keyIndex = 0; message[messageIndex] != '\0'; ++messageIndex, ++keyIndex)
    {
        if (key[keyIndex] == '\0')
        {
            keyIndex = 0;
        }

        if (isalpha(message[messageIndex]))
        {
            if (isupper(message[messageIndex]))
            {
                message[messageIndex] = (((message[messageIndex] - 'A') + (toupper(key[keyIndex]) - 'A')) % 26) + 'A';
            }
            else
            {
                message[messageIndex] = (((message[messageIndex] - 'a') + (tolower(key[keyIndex]) - 'a')) % 26) + 'a';
            }
        }
    }
}