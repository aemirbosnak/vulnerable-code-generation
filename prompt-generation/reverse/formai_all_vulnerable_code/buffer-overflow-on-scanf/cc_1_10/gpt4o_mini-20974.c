//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

void encrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }

        text[i] = ch;
    }
}

void decrypt(char *text, int shift) {
    // To decrypt, simply shift in the opposite direction
    encrypt(text, 26 - (shift % 26));
}

int main() {
    char text[MAX_LENGTH];
    int shift;
    
    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter the text you would like to encrypt:\n");
    
    // Get user input for text
    fgets(text, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    text[strcspn(text, "\n")] = 0;

    printf("Please enter the shift value (1-25):\n");
    scanf("%d", &shift);

    // Ensure the shift is within the proper bounds
    if (shift < 1 || shift > 25) {
        printf("Please enter a valid shift value (1-25).\n");
        return 1;
    }

    encrypt(text, shift);
    
    printf("Encrypted text: %s\n", text);
    
    // Decrypt for demonstration purposes
    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    return 0;
}