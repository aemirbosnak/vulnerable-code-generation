//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h> 
#include <string.h> 

#define MAX_SIZE 1000 

int main() 
{ 
    char message[MAX_SIZE], encryptedMessage[MAX_SIZE], decryptedMessage[MAX_SIZE]; 
    int key, i, length; 
    
    printf("Enter a message to encrypt: "); 
    fgets(message, MAX_SIZE, stdin); 
    
    printf("Enter encryption key: "); 
    scanf("%d", &key); 
    
    length = strlen(message); 

    // Encryption process
    for(i=0; i<length; i++)
    {
        if(message[i] != ' ')
        {
            if(message[i] >= 'a' && message[i] <= 'z')
            {
                encryptedMessage[i] = ((message[i] - 'a' + key) % 26) + 'a'; 
            }
            else if(message[i] >= 'A' && message[i] <= 'Z')
            {
                encryptedMessage[i] = ((message[i] - 'A' + key) % 26) + 'A'; 
            }
        }
        else
        {
            encryptedMessage[i] = ' ';
        }
    }
    encryptedMessage[i] = '\0';
    
    printf("Encrypted message: %s\n", encryptedMessage); 
    
    // Decryption process
    for(i=0; i<length; i++)
    {
        if(encryptedMessage[i] != ' ')
        {
            if(encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z')
            {
                decryptedMessage[i] = (((encryptedMessage[i] - 'a') - key + 26) % 26) + 'a'; 
            }
            else if(encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z')
            {
                decryptedMessage[i] = (((encryptedMessage[i] - 'A') - key + 26) % 26) + 'A'; 
            }
        }
        else
        {
            decryptedMessage[i] = ' ';
        }
    }
    decryptedMessage[i] = '\0';
    
    printf("Decrypted message: %s\n", decryptedMessage); 
    
    return 0; 
}