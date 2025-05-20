//FormAI DATASET v1.0 Category: Encryption ; Style: standalone
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

int main()
{
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    char cipher_text[MAX_SIZE];
    
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_SIZE, stdin);

    int message_len = strlen(message);
    int key_len = strlen(key);

    // Remove trailing newline character
    if(message[message_len-1] == '\n')
    {
        message[message_len-1] = '\0';
        message_len--;
    }

    if(key[key_len-1] == '\n')
    {
        key[key_len-1] = '\0';
        key_len--;
    }

    char padded_key[MAX_SIZE];
    int padding_len = message_len - key_len;

    if(padding_len < 0)
    {
        printf("Error: Key length is greater than message length!\n");
        return 1;
    }

    // Add padding to key by repeating it
    for(int i=0; i<padding_len; i++)
    {
        padded_key[i] = key[i % key_len];
    }

    // Copy original key to padded key
    for(int i=padding_len; i<key_len; i++)
    {
        padded_key[i] = key[i];
    }
    
    // Encrypt message using XOR with padded key
    for(int i=0; i<message_len; i++)
    {
        cipher_text[i] = message[i] ^ padded_key[i];
    }

    printf("Encrypted cipher text is: %s", cipher_text);

    return 0;
}