//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024 // Maximum length for the input message.

// Function to encrypt the message
void encrypt(char* message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        
        // Apply the shift for uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Apply the shift for lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        
        message[i] = ch; // Update the character
    }
}

// Function to decrypt the message
void decrypt(char* message, int shift) {
    // Call encrypt with a negative shift to decrypt
    encrypt(message, 26 - (shift % 26));
}

// Function to display a cheerful message
void displayCheerfulMessage() {
    printf("\n🎉 Welcome to the Cheerful Caesar Cipher! 🎉\n");
    printf("Let's encrypt and decrypt some messages together!\n\n");
}

int main() {
    char message[MAX_LEN];
    int shift, choice;

    // Display cheerful welcome message
    displayCheerfulMessage();

    // Get user choice
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    // Get the message and shift value
    printf("Enter your message (up to %d characters): ", MAX_LEN - 1);
    getchar(); // To consume the newline character left by scanf
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline
    
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    shift = shift % 26; // Ensure shift is within the range (0-25)

    // Perform encrypt or decrypt based on user choice
    if (choice == 1) {
        encrypt(message, shift);
        printf("\n🛡️ Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("\n🔑 Decrypted Message: %s\n", message);
    } else {
        printf("🚫 Invalid choice! Please start again!\n");
    }

    printf("\nThank you for playing with our cheerful cipher! 🎈\n");
    return 0;
}