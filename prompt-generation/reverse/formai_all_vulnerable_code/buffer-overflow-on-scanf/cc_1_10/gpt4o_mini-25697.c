//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int shift, char* encryptedMessage) {
    for (int i = 0; message[i] != '\0'; i++) {
        char currentChar = message[i];

        // Encrypt uppercase letters
        if (currentChar >= 'A' && currentChar <= 'Z') {
            encryptedMessage[i] = (currentChar - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (currentChar >= 'a' && currentChar <= 'z') {
            encryptedMessage[i] = (currentChar - 'a' + shift) % 26 + 'a';
        }
        // Leave non-alphabetic characters unchanged
        else {
            encryptedMessage[i] = currentChar;
        }
    }
    // Null-terminate the encrypted message
    encryptedMessage[strlen(message)] = '\0';
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* encryptedMessage, int shift, char* decryptedMessage) {
    for (int i = 0; encryptedMessage[i] != '\0'; i++) {
        char currentChar = encryptedMessage[i];

        // Decrypt uppercase letters
        if (currentChar >= 'A' && currentChar <= 'Z') {
            decryptedMessage[i] = (currentChar - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (currentChar >= 'a' && currentChar <= 'z') {
            decryptedMessage[i] = (currentChar - 'a' - shift + 26) % 26 + 'a';
        }
        // Leave non-alphabetic characters unchanged
        else {
            decryptedMessage[i] = currentChar;
        }
    }
    // Null-terminate the decrypted message
    decryptedMessage[strlen(encryptedMessage)] = '\0';
}

// Function to validate user input for shift value
int validateShiftValue(int shift) {
    if (shift < 0) {
        return 0; // Return 0 for invalid (negative) shift values
    }
    return shift % 26; // Normalizing shift to fall within 0-25
}

int main() {
    char message[256];
    char encryptedMessage[256];
    char decryptedMessage[256];
    int shift;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");

    // Input message
    printf("Please enter your message (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    
    // Remove newline character if present
    size_t length = strlen(message);
    if (length > 0 && message[length - 1] == '\n') {
        message[length - 1] = '\0';
    }

    // Input shift value
    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    
    // Validate shift value
    shift = validateShiftValue(shift);
    
    // Encrypt the message
    encrypt(message, shift, encryptedMessage);
    printf("Encrypted Message: %s\n", encryptedMessage);

    // Decrypt the message
    decrypt(encryptedMessage, shift, decryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    // Display the shift value used
    printf("Shift value used for encryption and decryption: %d\n", shift);

    return 0;
}