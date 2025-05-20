//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_TEXT_SIZE 1024
#define SHIFT 3    // Default shift for Caesar cipher, can be changed

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current = text[i];
        if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' + shift) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current = text[i];
        if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' - shift + 26) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

// Function to get configuration from user
int get_shift_value() {
    int shift;
    printf("Enter shift value (0-25): ");
    while (1) {
        scanf("%d", &shift);
        if (shift >= 0 && shift <= 25) {
            break;
        }
        printf("Invalid value. Please enter a shift value (0-25): ");
    }
    return shift;
}

// Function to get the text input from user
void get_text_input(char *text) {
    printf("Enter text (max %d characters): ", MAX_TEXT_SIZE - 1);
    scanf(" %[^\n]", text);  // Read until newline
}

// Main function to demonstrate the Caesar cipher
int main() {
    char text[MAX_TEXT_SIZE];
    int shift;

    printf("Caesar Cipher Implementation\n");
    shift = get_shift_value();

    get_text_input(text);

    printf("Original Text: %s\n", text);
    
    // Encrypt the text
    encrypt(text, shift);
    printf("Encrypted Text: %s\n", text);
    
    // Decrypt the text
    decrypt(text, shift);
    printf("Decrypted Text: %s\n", text);

    return 0;
}