//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* result = (char*) malloc(len * sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            result[i] = ((message[i]-'a'+key)%26) + 'a';
        }
        else if(message[i]>='A' && message[i]<='Z')
        {
            result[i] = ((message[i]-'A'+key)%26) + 'A';
        }
        else
        {
            result[i] = message[i];
        }
    }
    
    return result;
}

// Function to perform decryption
char* decrypt(char* message, int key)
{
    int len = strlen(message);
    char* result = (char*) malloc(len * sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            result[i] = ((message[i]-'a'-key+26)%26) + 'a';
        }
        else if(message[i]>='A' && message[i]<='Z')
        {
            result[i] = ((message[i]-'A'-key+26)%26) + 'A';
        }
        else
        {
            result[i] = message[i];
        }
    }
    
    return result;
}

int main()
{
    char message[100];
    int key;
    
    printf("Enter the message to be encrypted: ");
    gets(message);
    
    printf("Enter the key for encryption: ");
    scanf("%d", &key);
    
    char* encrypted_message = encrypt(message, key);
    
    printf("Encrypted message: %s\n", encrypted_message);
    
    char* decrypted_message = decrypt(encrypted_message, key);
    
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}