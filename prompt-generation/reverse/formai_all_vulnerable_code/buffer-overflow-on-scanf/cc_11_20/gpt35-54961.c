//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char message[100];
    int key, i;
    
    printf("Enter message: ");
    fgets(message, 100, stdin);
    
    printf("Enter key: ");
    scanf("%d", &key);
    
    // Encryption
    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] += key;
            
            if(message[i] > 'z')
                message[i] = message[i] - 'z' + 'a' - 1;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] += key;
            
            if(message[i] > 'Z')
                message[i] = message[i] - 'Z' + 'A' - 1;
        }
    }
    
    printf("\nEncrypted message: %s", message);
    
    //Decryption
    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] -= key;
            
            if(message[i] < 'a')
                message[i] = message[i] + 'z' - 'a' + 1;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] -= key;
            
            if(message[i] < 'A')
                message[i] = message[i] + 'Z' - 'A' + 1;
        }
    }
    
    printf("\nDecrypted message: %s", message);

    return 0;
}