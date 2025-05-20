//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

// Function prototypes
void encryptMessage(const char* message, int shift, char* encryptedMessage);
void decryptMessage(const char* encryptedMessage, int shift, char* decryptedMessage);
void getShiftValue(int *shift);
void getMessage(char* message);
void displayResults(const char* encryptedMessage, const char* decryptedMessage);

// Main function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encryptedMessage[MAX_MESSAGE_LENGTH];
    char decryptedMessage[MAX_MESSAGE_LENGTH];
    int shift;

    // Get the message to encrypt
    getMessage(message);
    
    // Get the shift value
    getShiftValue(&shift);
    
    // Perform encryption
    encryptMessage(message, shift, encryptedMessage);
    
    // Perform decryption
    decryptMessage(encryptedMessage, shift, decryptedMessage);
    
    // Display results
    displayResults(encryptedMessage, decryptedMessage);

    return 0;
}

// Function to encrypt the message
void encryptMessage(const char* message, int shift, char* encryptedMessage) {
    int i;
    for (i = 0; message[i] != '\0' && i < MAX_MESSAGE_LENGTH - 1; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = (message[i] - 'A' + shift) % 26 + 'A';
        } else {
            encryptedMessage[i] = message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encryptedMessage[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the message
void decryptMessage(const char* encryptedMessage, int shift, char* decryptedMessage) {
    int i;
    for (i = 0; encryptedMessage[i] != '\0' && i < MAX_MESSAGE_LENGTH - 1; i++) {
        if (encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z') {
            decryptedMessage[i] = (encryptedMessage[i] - 'a' - shift + 26) % 26 + 'a'; // Adding 26 to avoid negative
        } else if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') {
            decryptedMessage[i] = (encryptedMessage[i] - 'A' - shift + 26) % 26 + 'A'; // Adding 26 to avoid negative
        } else {
            decryptedMessage[i] = encryptedMessage[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedMessage[i] = '\0'; // Null-terminate the string
}

// Function to get the shift value
void getShiftValue(int *shift) {
    printf("Enter shift value (1-25): ");
    scanf("%d", shift);
    if (*shift < 1 || *shift > 25) {
        printf("Invalid shift value. Setting to default (3).\n");
        *shift = 3; // Default value if invalid
    }
}

// Function to get the message from user
void getMessage(char* message) {
    printf("Enter a message to encrypt: ");
    getchar(); // Clear the newline from the previous input
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Removing newline character
    message[strcspn(message, "\n")] = 0;
}

// Function to display the results
void displayResults(const char* encryptedMessage, const char* decryptedMessage) {
    printf("\nEncrypted Message: %s\n", encryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);
}