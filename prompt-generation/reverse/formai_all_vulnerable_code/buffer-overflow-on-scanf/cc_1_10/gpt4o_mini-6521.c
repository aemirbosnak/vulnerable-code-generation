//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

void encrypt(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            input[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            input[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Other characters remain unchanged
    }
}

void decrypt(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            input[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            input[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Other characters remain unchanged
    }
}

int main() {
    char input[MAX_LENGTH];
    int shift;
    char choice;

    printf("Welcome to the Caesar Cipher Encryptor/Decryptor!\n");

    while (1) {
        printf("Please enter your message: ");
        fgets(input, sizeof(input), stdin);
        // Remove the newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        // Validate shift value
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value! Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer after reading integer

        printf("Would you like to (e)ncrypt or (d)ecrypt the message? ");
        scanf("%c", &choice);
        while (getchar() != '\n'); // Clear buffer

        if (choice == 'e' || choice == 'E') {
            encrypt(input, shift);
            printf("Encrypted message: %s\n", input);
        } else if (choice == 'd' || choice == 'D') {
            decrypt(input, shift);
            printf("Decrypted message: %s\n", input);
        } else {
            printf("Invalid choice! Please enter 'e' to encrypt or 'd' to decrypt.\n");
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf("%c", &choice);
        while (getchar() != '\n'); // Clear buffer

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    
    printf("Thank you for using the Caesar Cipher!\n");
    return 0;
}