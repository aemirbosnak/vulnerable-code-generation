//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        
        text[i] = ch;  // Update the character in the original text
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';
        }
        
        text[i] = ch;  // Update the character in the original text
    }
}

// Function to display a simple menu
void displayMenu() {
    printf("Welcome to the Caesar Cipher Program!\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

int main() {
    char text[256];
    int shift;
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character after entering choice
        
        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove the newline character
                
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                shift = shift % 26; // Ensure shift is within 0-25
                
                encrypt(text, shift);
                printf("Encrypted text: %s\n\n", text);
                break;
                
            case 2:
                printf("Enter text to decrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove the newline character
                
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                shift = shift % 26; // Ensure shift is within 0-25
                
                decrypt(text, shift);
                printf("Decrypted text: %s\n\n", text);
                break;
                
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please choose again.\n\n");
        }
    }

    return 0;
}