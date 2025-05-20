//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    int choice;
    
    printf("Enter message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    
    printf("Enter encryption key: ");
    fgets(key, MAX_STRING_LENGTH, stdin);
    
    do
    {
        printf("Choose an option:\n1. Encrypt message\n2. Decrypt message\n3. Quit\n");
        scanf("%d", &choice);
        getchar(); // to consume the newline character
        
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
                printf("Exiting...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
        
    }while(choice != 3);
    
    return 0;
}

void encrypt(char *message, char *key)
{
    srand(time(NULL));
    
    for(int i=0; i<strlen(message); i++)
    {
        int rand_num = rand() % 256; // generate a random number between 0 and 255
        
        message[i] = message[i] ^ rand_num;
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

void decrypt(char *message, char *key)
{
    srand(time(NULL));
    
    for(int i=0; i<strlen(message); i++)
    {
        int rand_num = rand() % 256; // generate a random number between 0 and 255
        
        message[i] = message[i] ^ key[i % strlen(key)];
        message[i] = message[i] ^ rand_num;
    }
}