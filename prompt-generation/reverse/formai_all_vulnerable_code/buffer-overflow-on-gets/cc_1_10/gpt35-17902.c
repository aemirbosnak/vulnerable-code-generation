//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
/*
Author: [Your Name]
Date: [Current Date]
Description: An example program to implement digital watermarking in C language
*/

#include <stdio.h>
#include <stdlib.h>

/**
* function to encode the message with given key
*/
void encode(char *message, char *key)
{
    for(int i = 0; message[i]; i++)
    {
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

/**
* function to decode the message with given key
*/
void decode(char *message, char *key)
{
    for(int i = 0; message[i]; i++)
    {
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

int main()
{
    char message[100], key[100];
    printf("Enter a message: ");
    gets(message);

    printf("Enter a key: ");
    gets(key);

    // encode the message
    encode(message, key);

    printf("Encoded message: %s\n", message);

    // decode the message
    decode(message, key);

    printf("Decoded message: %s\n", message);

    return 0;
}