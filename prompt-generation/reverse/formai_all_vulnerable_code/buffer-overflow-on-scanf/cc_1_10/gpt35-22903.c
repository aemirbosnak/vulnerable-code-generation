//FormAI DATASET v1.0 Category: modern Encryption ; Style: excited
// Welcome to the world of modern encryption!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These are the required variables
char password[16];
int key = 5;
char message[100];
char encrypted_message[100];
char decrypted_message[100];

// Function to encrypt the message
char* encryptMessage(char* message, int key)
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        encrypted_message[i] = message[i] + key;
    }
    encrypted_message[i] = '\0';
    return encrypted_message;
}

// Function to decrypt the message
char* decryptMessage(char* message, int key)
{
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        decrypted_message[i] = message[i] - key;
    }
    decrypted_message[i] = '\0';
    return decrypted_message;
}

// The main function
int main()
{
    printf("Welcome to the world of modern encryption!\n");
    
    // Take the password input from the user
    printf("Enter your password (max 15 characters): ");
    scanf("%s", password);
    printf("Your password is %s\n", password);
    
    // Encrypt the password using the key
    char* encrypted_password = encryptMessage(password, key);
    printf("Your encrypted password is: %s\n", encrypted_password);
    
    // Decrypt the password using the key
    char* decrypted_password = decryptMessage(encrypted_password, key);
    printf("Your decrypted password is: %s\n", decrypted_password);
    
    // Take the message input from the user
    printf("Enter your message (max 99 characters): ");
    scanf("%s", message);
    printf("Your message is %s\n", message);
    
    // Encrypt the message using the key
    char* encrypted_message = encryptMessage(message, key);
    printf("Your encrypted message is: %s\n", encrypted_message);
    
    // Decrypt the message using the key
    char* decrypted_message = decryptMessage(encrypted_message, key);
    printf("Your decrypted message is: %s\n", decrypted_message);
    
    return 0;
}