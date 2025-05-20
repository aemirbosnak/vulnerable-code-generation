//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        }
        text[i] = ch;
    }
}

// Function to decrypt the input text using Caesar Cipher
void decrypt(char *text, int shift) {
    // To decrypt, we shift back by the same amount
    encrypt(text, 26 - shift);
}

// Function to take user input for text and shift value
void userInput(char *text, int *shift) {
    printf("Enter the text: ");
    fgets(text, 1024, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character
    
    printf("Enter the shift value (1-25): ");
    scanf("%d", shift);
    
    if (*shift < 1 || *shift > 25) {
        printf("Invalid shift value. It must be between 1 and 25.\n");
        exit(1);
    }
}

int main() {
    char text[1024];
    int shift;
    
    printf("Welcome to the Surprise Cryptography Program!\n");
    userInput(text, &shift);
    
    printf("\nOriginal Text: %s\n", text);
    
    // Encrypt the message
    encrypt(text, shift);
    printf("Encrypted Text: %s\n", text);
    
    // Decrypt the message
    decrypt(text, shift);
    printf("Decrypted Text: %s\n", text);
    
    printf("\nThank you for using our program! Surprise is everywhere!\n");
    
    return 0;
}