//FormAI DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

/* function prototyping */
char* encrypt(char* text, int key);
char* decrypt(char* text, int key);

int main()
{
    char message[MAX_BUF_SIZE];
    int key;

    /* read message and key from user */
    printf("Enter a message: ");
    fgets(message, MAX_BUF_SIZE, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    /* encrypt the message with given key */
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    /* decrypt the message with given key */
    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    /* free dynamic memory allocation */
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}

/* function to encrypt the given text with given key */
char* encrypt(char* text, int key)
{
    int length = strlen(text);
    char* result = (char*) malloc(length * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        result[i] = text[i] + key; /* add key to each character of text */
    }

    return result;
}

/* function to decrypt the given text with given key */
char* decrypt(char* text, int key)
{
    int length = strlen(text);
    char* result = (char*) malloc(length * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        result[i] = text[i] - key; /* subtract key to each character of text */
    }

    return result;
}