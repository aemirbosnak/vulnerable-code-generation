//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function prototypes
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);
void get_input(char *buffer, const char *prompt);

int main() {
    char input[BUFFER_SIZE];
    int shift;
    char choice;

    printf("Welcome to the simple Caesar Cipher Program!\n");

    do {
        get_input(input, "Enter the message (max 255 characters): ");
        printf("Enter the shift value (1 to 25): ");
        scanf("%d", &shift);
        getchar(); // Clear newline from buffer
        
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. Please enter a value between 1 and 25.\n");
            continue;
        }

        // Encrypt the message
        char encrypted[BUFFER_SIZE];
        strcpy(encrypted, input);
        encrypt(encrypted, shift);
        printf("Encrypted Message: %s\n", encrypted);

        // Decrypt the message
        char decrypted[BUFFER_SIZE];
        strcpy(decrypted, encrypted);
        decrypt(decrypted, shift);
        printf("Decrypted Message: %s\n", decrypted);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clear newline from buffer

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}

// Function to encrypt the message
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        message[i] = ch;
    }
}

// Function to decrypt the message
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a'; // +26 to avoid negative number
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A'; // +26 to avoid negative number
        }
        message[i] = ch;
    }
}

// Function to get input string from the user
void get_input(char *buffer, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, BUFFER_SIZE, stdin);
    
    size_t len = strlen(buffer);
    // Remove newline character from the input if present
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}