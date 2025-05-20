//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);

int main()
{
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s", message);
    
    return 0;
}

void encrypt(char *message, int key)
{
    int i;
    char ch;
    
    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];
        
        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ((ch - 'A') + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
        {
            ch = ((ch - 'a') + key) % 26 + 'a';
        }
        // Do not encrypt symbols or spaces
        else
        {
            continue;
        }
        
        message[i] = ch;
    }
}