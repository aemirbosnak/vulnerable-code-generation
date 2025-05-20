//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a grateful example of encryption program in C language
int main() {
    
    char message[1000];
    int key, i;
    char encryptedMessage[1000];
    
    // Display a welcome message
    printf("Welcome to C Encryption Program!\n\n");

    // Take input from user
    printf("Please enter the message you want to encrypt: ");
    scanf("%[^\n]", message);
    printf("\n");

    // Take encryption key from user
    printf("Please enter an encryption key (integer value): ");
    scanf("%d", &key);
    printf("\n");

    // Encrypt the message using the key
    for (i = 0; i < strlen(message); i++) {
        encryptedMessage[i] = message[i] + key;
    }

    // Display the encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < strlen(encryptedMessage); i++) {
        printf("%c", encryptedMessage[i]);
    }
    printf("\n\n");

    // Decrypt the message using the key
    for (i = 0; i < strlen(encryptedMessage); i++) {
        message[i] = encryptedMessage[i] - key;
    }
    
    // Display the original message
    printf("Original message: ");
    for (i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
    }
    printf("\n");
    
    return 0;
}