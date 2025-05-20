//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        input[i] = ch; // Update character to encrypted character
    }
}

void decrypt(char *input, int shift) {
    // To decrypt, we just shift in the opposite direction
    encrypt(input, 26 - (shift % 26));
}

int main() {
    char text[256];
    int shift;
    char choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    
    do {
        printf("\nPlease enter a string to encrypt (or type 'exit' to quit): ");
        fgets(text, sizeof(text), stdin);
        
        // Remove newline character if present
        text[strcspn(text, "\n")] = 0;

        // Check if user wants to exit
        if (strcmp(text, "exit") == 0) {
            break;
        }

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        getchar(); // Clear the newline character left in the input buffer

        // Validate shift value
        if (shift < 1 || shift > 25) {
            printf("Please enter a valid shift value between 1 and 25.\n");
            continue;
        }

        // Encrypting the text
        printf("\nOriginal Text: %s\n", text);
        encrypt(text, shift);
        printf("Encrypted Text: %s\n", text);

        // Decrypting the text
        decrypt(text, shift);
        printf("Decrypted Back: %s\n", text);

        // Ask the user if they want to continue
        printf("\nWould you like to encrypt another string? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clear the newline character left in the input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Caesar Cipher Program! Goodbye!\n");
    return 0;
}