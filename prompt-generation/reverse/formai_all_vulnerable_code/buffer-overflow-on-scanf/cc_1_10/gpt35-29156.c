//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encrypt(char *message, int key)
{
    int i;
    int length = strlen(message);
    char encrypted_message[length];

    for(i = 0; i < length; ++i)
    {
        char c = message[i];
        if('a' <= c && c <= 'z')
            c = (c - 'a' + key) % 26 + 'a';
        else if('A' <= c && c <= 'Z')
            c = (c - 'A' + key) % 26 + 'A';
        encrypted_message[i] = c;
    }
    encrypted_message[length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, int key)
{
    int i;
    int length = strlen(message);
    char decrypted_message[length];

    for(i = 0; i < length; ++i)
    {
        char c = message[i];
        if('a' <= c && c <= 'z')
            c = (c - 'a' - key + 26) % 26 + 'a';
        else if('A' <= c && c <= 'Z')
            c = (c - 'A' - key + 26) % 26 + 'A';
        decrypted_message[i] = c;
    }
    decrypted_message[length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter a key for encryption & decryption: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    decrypt(message, key);

    return 0;
}