//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple Caesar Cipher Implementation in C
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            ciphertext[i] = (c - 'a' + shift) % 26 + 'a';
        }
        // Copy non-alphabetical characters
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            plaintext[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            plaintext[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
        // Copy non-alphabetical characters
        else {
            plaintext[i] = c;
        }
    }
    plaintext[i] = '\0'; // Null terminate the plaintext string
}

void print_menu() {
    printf("Simple Caesar Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
}

int main() {
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];
    int choice, shift;

    while (1) {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Encrypt
                printf("Enter plaintext: ");
                scanf(" %[^\n]", plaintext); // Read string with spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25!\n");
                    break;
                }
                encrypt(plaintext, shift, ciphertext);
                printf("Ciphertext: %s\n", ciphertext);
                break;
            case 2: // Decrypt
                printf("Enter ciphertext: ");
                scanf(" %[^\n]", ciphertext); // Read string with spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25!\n");
                    break;
                }
                decrypt(ciphertext, shift, decryptedtext);
                printf("Plaintext: %s\n", decryptedtext);
                break;
            case 3: // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}