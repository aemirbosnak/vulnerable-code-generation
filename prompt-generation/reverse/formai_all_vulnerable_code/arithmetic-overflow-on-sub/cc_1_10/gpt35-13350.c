//FormAI DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include<stdio.h>
#include<string.h>

void encrypt(char* message, int key); // Function prototype for encryption
void decrypt(char* message, int key); // Function prototype for decryption

int main()
{
    char message[100];  // To store message
    int key, choice;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); // Reading input from user
    
    printf("Enter key: ");
    scanf("%d", &key); // Reading encryption key
    
    printf("Enter\n");
    printf("1 for encryption\n");
    printf("2 for decryption\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); // Reading choice
    
    switch(choice)
    {
        case 1: // Encryption
                encrypt(message, key);
                printf("\nEncrypted message: %s", message);
                break;
                
        case 2: // Decryption
                decrypt(message, key);
                printf("\nDecrypted message: %s", message);
                break;
                
        default: printf("\nInvalid choice!");
    }
    
    return 0;
}

void encrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a'; // Encryption formula
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A'; // Encryption formula
        }
    }
}

void decrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a'; // Decryption formula
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A'; // Decryption formula
        }
    }
}