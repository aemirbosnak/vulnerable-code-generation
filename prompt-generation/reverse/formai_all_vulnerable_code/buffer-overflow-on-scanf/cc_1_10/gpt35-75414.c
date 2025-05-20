//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of the input message

void xor(char *key, char *msg, char *ciphered_msg) // XOR cipher function 
{
    int i;
    int len_key = strlen(key); // Key length
    int len_msg = strlen(msg); // Message length
    
    for(i = 0; i < len_msg; i++) 
    {
        ciphered_msg[i] = msg[i] ^ key[i % len_key]; // XOR operation of the key and message
    }
    ciphered_msg[i] = '\0'; // End the ciphered message with null character
}

void display_menu() // Displaying the menu function
{
    printf("\n");
    printf("Welcome to the XOR Cipher Cryptography Implementation Program!\n");
    printf("Please enter your choice:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() 
{
    char key[MAX_LEN];
    char msg[MAX_LEN];
    char ciphered_msg[MAX_LEN];
    char decrypted_msg[MAX_LEN];
    int choice;
    
    while (1) // Infinite loop until the user exits
    {
        display_menu(); // Display the menu to the user
        scanf("%d", &choice); // Read user input
        
        switch(choice) 
        {
            case 1: // Encryption
                printf("\nEnter the key (only alphabets and spaces are allowed):\n");
                scanf(" %[^\n]%*c", key); // Read the key input
                printf("Enter the message to encrypt:\n");
                scanf(" %[^\n]%*c", msg); // Read the message input
                
                xor(key, msg, ciphered_msg); // Call the XOR cipher function
                printf("\nEncrypted message: %s\n", ciphered_msg); // Display the ciphered message
                break;
                
            case 2: // Decryption
                printf("\nEnter the key (only alphabets and spaces are allowed):\n");
                scanf(" %[^\n]%*c", key); // Read the key input
                printf("Enter the message to decrypt:\n");
                scanf(" %[^\n]%*c", ciphered_msg); // Read the encrypted message input
                
                xor(key, ciphered_msg, decrypted_msg); // Call the XOR cipher function
                printf("\nDecrypted message: %s\n", decrypted_msg); // Display the decrypted message
                break;
                
            case 3: // Exit
                printf("\nExiting Program...\n");
                exit(0); // Terminate the program
                break;
                
            default: // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }
    
    return 0;
}