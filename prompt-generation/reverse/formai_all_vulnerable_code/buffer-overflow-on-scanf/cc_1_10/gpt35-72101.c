//FormAI DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message)
{
    int key = 5; // The encryption key
    int n = strlen(message); // Length of the message
  
    // Loop through each character of the message
    for (int i = 0; i < n; i++)
    {
        // Shift the character by the key value
        if (message[i] >= 'a' && message[i] <= 'z')
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        else if (message[i] >= 'A' && message[i] <= 'Z')
            message[i] = (message[i] + key - 'A') % 26 + 'A';
    }
    
    printf("Encrypted message: %s\n", message);
}

// Function to decrypt the message
void decrypt(char* message)
{
    int key = 5; // The decryption key
    int n = strlen(message); // Length of the message
  
    // Loop through each character of the message
    for (int i = 0; i < n; i++)
    {
        // Shift the character back by the key value
        if (message[i] >= 'a' && message[i] <= 'z')
            message[i] = (message[i] - key - 'a' + 26) % 26 + 'a';
        else if (message[i] >= 'A' && message[i] <= 'Z')
            message[i] = (message[i] - key - 'A' + 26) % 26 + 'A';
    }
    
    printf("Decrypted message: %s\n", message);
}

int main()
{
    char message[100];
  
    printf("Welcome to the cheerful modern encryption program!\n");
    printf("Please enter the message to be encrypted: ");
    scanf("%s", message);
  
    encrypt(message);
  
    decrypt(message);
    
    printf("Thanks for using our program. Have a wonderful day!\n");
  
    return 0;
}