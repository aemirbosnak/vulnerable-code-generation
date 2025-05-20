//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
// Welcome to my unique C Encryption program!
// This program uses a unique algorithm to encrypt and decrypt text messages.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
char *encrypt(char *message, int key)
{
    int i;
    char *result = (char *)malloc(strlen(message) * sizeof(char));
    strcpy(result, message);
    
    for (i = 0; i < strlen(result); i++)
    {
        result[i] = result[i] + key;
    }
    
    return result;
}

// Function to decrypt the message
char *decrypt(char *message, int key)
{
    int i;
    char *result = (char *)malloc(strlen(message) * sizeof(char));
    strcpy(result, message);
    
    for (i = 0; i < strlen(result); i++)
    {
        result[i] = result[i] - key;
    }
    
    return result;
}

int main()
{
    char message[100], *encrypted, *decrypted;
    int key;
    
    printf("Enter the message you want to encrypt: ");
    gets(message); // Warning: unsafe function. Replace with fgets() for better security.
    
    printf("Enter the key you want to use for encryption: ");
    scanf("%d", &key);
    
    encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    
    decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    
    return 0;
}