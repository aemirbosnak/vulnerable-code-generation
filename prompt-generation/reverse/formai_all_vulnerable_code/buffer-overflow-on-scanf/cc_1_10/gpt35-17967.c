//FormAI DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int key)
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        if(i % 2 == 0)
        {
            message[i] = (message[i] + key) % 127;
        }
        else
        {
            message[i] = (message[i] - key) % 127;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key)
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        if(i % 2 == 0)
        {
            message[i] = (message[i] - key) % 127;
        }
        else
        {
            message[i] = (message[i] + key) % 127;
        }
    }
}

int main()
{
    char message[1000];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    
    // Encrypt the message
    encrypt(message, key);
    
    // Print the encrypted message
    printf("\nEncrypted message: ");
    for(int i=0; i<strlen(message); i++)
    {
        printf("%c", message[i]);
    }
    
    // Decrypt the message
    decrypt(message, key);
    
    // Print the decrypted message
    printf("\nDecrypted message: ");
    for(int i=0; i<strlen(message); i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");
    return 0;
}