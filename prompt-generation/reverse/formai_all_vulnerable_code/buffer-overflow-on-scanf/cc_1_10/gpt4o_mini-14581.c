//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to encrypt a message using Caesar Cipher
void encrypt(char* input, int shift, char* output) {
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null terminate the output string
}

// Function to decrypt a message using Caesar Cipher
void decrypt(char* input, int shift, char* output) {
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // +26 for wrap around
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // +26 for wrap around
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null terminate the output string
}

// Main function
int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int shift;
    int choice;

    // User choice for encryption/decryption
    printf("Caesar Cipher Encryption/Decryption\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    
    // Taking a shift value from user
    printf("Enter the shift value (1 - 25): ");
    scanf("%d", &shift);

    // Ensuring valid shift value
    shift = shift % 26; // Ensure shift is within 0-25

    // Input the message
    printf("Enter your message (max %d characters): ", MAX_LEN - 1);
    getchar(); // Clear the newline character from input buffer
    fgets(input, MAX_LEN, stdin);
    
    // Remove the newline character from fgets input
    input[strcspn(input, "\n")] = 0;

    // Process based on User Choice
    if(choice == 1) {
        encrypt(input, shift, output);
        printf("Encrypted message: %s\n", output);
    } else if(choice == 2) {
        decrypt(input, shift, output);
        printf("Decrypted message: %s\n", output);
    } else {
        printf("Invalid choice! Please select 1 or 2.\n");
    }

    return 0;
}