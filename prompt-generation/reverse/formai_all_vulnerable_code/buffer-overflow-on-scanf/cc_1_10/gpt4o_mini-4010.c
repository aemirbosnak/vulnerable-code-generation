//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    char result[1024];
    int i = 0;

    // Loop through each character in the string
    while (text[i] != '\0') {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        // Leave other characters unchanged
        else {
            result[i] = text[i];
        }
        i++;
    }
    result[i] = '\0';  // Null terminate the string
    printf("Encrypted text: %s\n", result);
}

void decrypt(char *text, int shift) {
    char result[1024];
    int i = 0;

    // Loop through each character in the string
    while (text[i] != '\0') {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
        // Leave other characters unchanged
        else {
            result[i] = text[i];
        }
        i++;
    }
    result[i] = '\0';  // Null terminate the string
    printf("Decrypted text: %s\n", result);
}

int main() {
    char text[1024];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Encryption Tool!\n");
    printf("Please enter the text you want to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove trailing newline character

    printf("How many positions would you like to shift? ");
    scanf("%d", &shift);
    
    // Sanitize shift
    shift = shift % 26;
    
    // User input for encryption or decryption
    printf("\nWould you like to:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            encrypt(text, shift);
            break;
        case 2:
            decrypt(text, shift);
            break;
        default:
            printf("Invalid choice! Please restart the program and choose 1 or 2.\n");
    }

    printf("\nThank you for using the Caesar Cipher Tool! Stay secure!\n");
    return 0;
}