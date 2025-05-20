//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Function to perform the encryption
void encrypt(char message[], int key)
{
    int i;
    char ch;
    
    for(i = 0; message[i] != '\0'; i++) {
        // Change the character based on the key
        ch = message[i] + key;
        
        // Handle overflows
        if(ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
        }
        
        // Update the encrypted message
        message[i] = ch;
    }
}

// Function to perform the decryption
void decrypt(char message[], int key)
{
    int i;
    char ch;
    
    for(i = 0; message[i] != '\0'; i++) {
        // Change the character based on the key
        ch = message[i] - key;
        
        // Handle underflows
        if(ch < 'a') {
            ch = ch + 'z' - 'a' + 1;
        }
        
        // Update the decrypted message
        message[i] = ch;
    }
}

int main()
{
    char message[100], choice;
    int key, len;
    
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    len = strlen(message);
    message[len-1] = '\0'; // Replace new line with null terminator
    
    printf("Enter the key: ");
    scanf("%d", &key);
    
    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    // Prompt for decryption
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);
    
    // Decrypt if requested
    if(choice == 'y' || choice == 'Y') {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    
    return 0;
}