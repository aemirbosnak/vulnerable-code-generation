//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void clearBuffer();

int main() {
    char text[256];
    int shift;
    char choice;

    printf("Welcome to the Simple Caesar Cipher Program!\n");

    // Loop to allow multiple encryptions
    do {
        // Ask the user for the text to encrypt
        printf("Enter the text to encrypt: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;  // Remove newline character

        // Ask the user for the shift value
        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        
        // Validate shift value
        while (shift < 1 || shift > 25) {
            printf("Invalid shift! Please enter a shift value (1-25): ");
            scanf("%d", &shift);
        }
        
        // Encrypt the text
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);

        // Decrypt the text
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);

        // Clear input buffer
        clearBuffer();

        // Ask if the user wants to continue
        printf("Do you want to encrypt another text? (y/n): ");
        choice = getchar();
        clearBuffer();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Caesar Cipher Program! Goodbye!\n");
    return 0;
}

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (isupper(text[i])) {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(text[i])) {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        // Decrypt uppercase letters
        if (isupper(text[i])) {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(text[i])) {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Empty the input buffer
}