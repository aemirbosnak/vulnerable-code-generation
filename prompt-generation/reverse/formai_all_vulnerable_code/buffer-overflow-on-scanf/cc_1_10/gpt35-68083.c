//FormAI DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 10

int encrypt(char *message, char *key);
int decrypt(char *message, char *key);

int main()
{
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];
    int choice;

    printf("Enter the message:\n");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter the key:\n");
    fgets(key, KEY_LENGTH, stdin);

    printf("Menu:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

int encrypt(char *message, char *key)
{
    int i, j, message_length, key_length, k[KEY_LENGTH], temp;
    char encrypted_message[MAX_LENGTH];
    
    message_length = strlen(message);
    key_length = strlen(key);
    
    for (i = 0; i < key_length; i++)
    {
        k[i] = key[i];
    }
    
    j = 0;
    
    for (i = 0; i < message_length; i++)
    {
        if (j == key_length)
        {
            j = 0;
        }
        
        temp = message[i] + k[j];
        
        if (temp > 126)
        {
            temp -= 95;
        }
        
        encrypted_message[i] = temp;
        
        j++;
    }
    
    encrypted_message[i] = '\0';
    
    printf("Encrypted message:\n%s\n", encrypted_message);
    
    return 0;
}

int decrypt(char *message, char *key)
{
    int i, j, message_length, key_length, k[KEY_LENGTH], temp;
    char decrypted_message[MAX_LENGTH];
    
    message_length = strlen(message);
    key_length = strlen(key);
    
    for (i = 0; i < key_length; i++)
    {
        k[i] = key[i];
    }
    
    j = 0;
    
    for (i = 0; i < message_length; i++)
    {
        if (j == key_length)
        {
            j = 0;
        }
        
        temp = message[i] - k[j];
        
        if (temp < 32)
        {
            temp += 95;
        }
        
        decrypted_message[i] = temp;
        
        j++;
    }
    
    decrypted_message[i] = '\0';
    
    printf("Decrypted message:\n%s\n", decrypted_message);
    
    return 0;
}