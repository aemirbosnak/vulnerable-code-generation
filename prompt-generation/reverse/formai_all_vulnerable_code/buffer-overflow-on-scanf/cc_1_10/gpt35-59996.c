//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTION_KEY 7 // Key for encryption algorithm

// Function to encrypt the string 
void encrypt(char *str) 
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = str[i] + ENCRYPTION_KEY; 
        i++;
    }
}

// Function to decrypt the string 
void decrypt(char *str) 
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = str[i] - ENCRYPTION_KEY; 
        i++;
    }
}

int main()
{
    char message[100]; // Message to be encrypted
    char choice; // User's choice whether to encrypt or decrypt
    srand(time(NULL)); // Seed for rand() function

    // Get user message to encrypt
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove new line character from message input 
    message[strcspn(message, "\n")] = 0; 

    // Generate random password for encryption key
    int password = rand() % 100 + 1;

    // Encrypt message
    encrypt(message);

    // Print encrypted message and password
    printf("Your encrypted message is: %s\n", message);
    printf("Your encryption key is: %d\n", password);

    // Ask user if they want to decrypt the message
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        int user_password;

        // Get encryption key from user
        printf("Enter your encryption key: ");
        scanf("%d", &user_password);

        if (user_password == password) {
            // Decrypt message
            decrypt(message);
            printf("Your decrypted message is: %s\n", message);
        } else {
            printf("Incorrect encryption key. Cannot decrypt message.\n");
        }
    }

    return 0;
}