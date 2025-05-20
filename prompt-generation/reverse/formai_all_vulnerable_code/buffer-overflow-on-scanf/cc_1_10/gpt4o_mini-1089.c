//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encryptCaesarCipher(char *message, int shift) {
    char encryptedMessage[256]; // Array to hold the encrypted message
    int i = 0; // Initialize counter

    // Loop through each character in the message
    while (message[i] != '\0') {
        char currentCharacter = message[i];

        // Encrypt alphabetic characters
        if (currentCharacter >= 'a' && currentCharacter <= 'z') {
            encryptedMessage[i] = (currentCharacter - 'a' + shift) % 26 + 'a';
        } else if (currentCharacter >= 'A' && currentCharacter <= 'Z') {
            encryptedMessage[i] = (currentCharacter - 'A' + shift) % 26 + 'A';
        } else {
            encryptedMessage[i] = currentCharacter; // Non-alphabetic characters remain unchanged
        }
        
        // Move to the next character in the message
        i++;
    }
    encryptedMessage[i] = '\0'; // Null-terminate the encrypted message

    // Print the encrypted message
    printf("Encrypted Message: %s\n", encryptedMessage);
}

int main() {
    char message[256]; // Array to hold the user's message
    int shift; // Variable for the shift amount

    // Welcome to the cipher kingdom!
    printf("Welcome, brave traveler, to the land of encryption!\n");
    
    // Prompt user for the message
    printf("Please enter your message: ");
    fgets(message, sizeof(message), stdin); // Reads the input message including spaces
    
    // Removing the newline caused by fgets
    message[strcspn(message, "\n")] = '\0'; // Removing the trailing newline

    // Prompt user for the shift value
    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);

    // Normalize the shift value
    shift = shift % 26; // To ensure the shift is within 0-25

    // Alert the user of the impending encryption!
    printf("Encrypting the message with a shift of %d...\n", shift);
    
    // Call the encryption function
    encryptCaesarCipher(message, shift);

    // A farewell to end the adventure
    printf("Thank you for visiting the cipher kingdom! Until next time!\n");
    
    return 0; // Exiting the program
}