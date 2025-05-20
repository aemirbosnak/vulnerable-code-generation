//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[100];
    char key[100];
    int choice;
    
    printf("Enter the message to be encrypted:\n");
    scanf("%[^\n]s", message);
    
    printf("Enter the key for encryption/decryption:\n");
    scanf("%s", key);

    do
    {
        printf("\nEnter your choice:\n(1) Encrypt\n(2) Decrypt\n(3) Exit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
                
            case 3:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}

void encrypt(char *message, char *key)
{
    int i, j = 0;
    char temp;
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    for(i = 0; i < message_len; i++)
    {
        temp = message[i];
        message[i] = (temp + key[j]) % 256;
        j = (j + 1) % key_len;
    }
}

void decrypt(char *message, char *key)
{
    int i, j = 0;
    char temp;
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    for(i = 0; i < message_len; i++)
    {
        temp = message[i];
        message[i] = (temp - key[j] + 256) % 256;
        j = (j + 1) % key_len;
    }
}