//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to encrypt text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        
        text[i] = ch;
    }
}

// Function to decrypt text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        
        text[i] = ch;
    }
}

int main() {
    char text[MAX_LENGTH];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice != 1 && choice != 2) {
        printf("Invalid option selected.\n");
        return 1;
    }

    printf("Enter your text (max %d characters): ", MAX_LENGTH - 1);
    getchar(); // to consume the newline from previous input
    fgets(text, MAX_LENGTH, stdin);
    
    // Remove trailing newline if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Ensure the shift value is within the valid range
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted Message: %s\n", text);
    } 
    else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted Message: %s\n", text);
    }

    return 0;
}