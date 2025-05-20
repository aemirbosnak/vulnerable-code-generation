//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; ++i) {
        char currentChar = message[i];

        // Encrypt uppercase letters
        if(currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = ((currentChar - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if(currentChar >= 'a' && currentChar <= 'z') {
            currentChar = ((currentChar - 'a' + shift) % 26) + 'a';
        }
        
        // Update the character in the message
        message[i] = currentChar;
    }
}

void decrypt(char *message, int shift) {
    // To decrypt, we can simply shift backwards
    encrypt(message, 26 - (shift % 26));
}

int main() {
    char message[256];
    int shift;
    char option;

    printf("Welcome to the Introspective Caesar Cipher Program!\n\n");

    // Get user input for the message to encrypt or decrypt
    printf("Please enter your message (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    // Remove the newline character, if present
    message[strcspn(message, "\n")] = 0;

    // Ask user for the shift value
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    // Validate the shift
    if(shift < 1 || shift > 25) {
        printf("Invalid shift value! Please enter a value between 1 and 25.\n");
        return 1;
    }

    // Option to encrypt or decrypt
    printf("Do you want to (E)ncrypt or (D)ecrypt the message? ");
    getchar(); // Clear newline character from the buffer
    scanf("%c", &option);
    
    if(option == 'E' || option == 'e') {
        printf("\nEncrypting the message...\n");
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    }
    else if(option == 'D' || option == 'd') {
        printf("\nDecrypting the message...\n");
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    }
    else {
        printf("Invalid option chosen! Please run the program again.\n");
        return 1;
    }

    // Closing remarks
    printf("\nThank you for using the Caesar Cipher Program! Goodbye!\n");
    return 0;
}