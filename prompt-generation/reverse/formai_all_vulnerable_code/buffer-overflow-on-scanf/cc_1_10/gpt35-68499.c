//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
char* encrypt(char* message, int key);

int main() {
    char message[100];
    int key;

    // Ask user for message and encryption key
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin); // read string with spaces
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Call the encrypt function
    char* encrypted_message = encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s", encrypted_message);

    // Free up memory of malloc
    free(encrypted_message);

    return 0;
}

/*
    Function to encrypt the message using given key.
*/
char* encrypt(char* message, int key) {
    // Create string to store the encrypted message
    char* encrypted_message = (char*)malloc(strlen(message) + 1); // +1 for null terminator

    // Loop through each character in message
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];

        // If character is uppercase
        if (c >= 'A' && c <= 'Z') {
            // Apply encryption formula
            c = ((c - 'A') + key) % 26 + 'A';
        }
        // If character is lowercase
        else if(c >= 'a' && c <= 'z') {
            // Apply encryption formula
            c = ((c - 'a') + key) % 26 + 'a';
        }

        // Add the encrypted character to the encrypted_message
        encrypted_message[i] = c;
    }

    // Add the null terminator at the end of the encrypted_message
    encrypted_message[strlen(message)] = '\0';

    return encrypted_message;
}