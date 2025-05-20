//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A'; // Encrypt upper case
        } else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a'; // Encrypt lower case
        } else {
            ciphertext[i] = ch; // Non-alphabetical characters are unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null terminate the ciphertext
}

// Function to decrypt the ciphertext using Caesar cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // Decrypt upper case
        } else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // Decrypt lower case
        } else {
            plaintext[i] = ch; // Non-alphabetical characters are unchanged
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null terminate the plaintext
}

int main() {
    char text[256];
    char result[256];
    int shift;
    int option;

    printf("Welcome to the Simple Caesar Cipher Tool!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &option);
    getchar(); // consume newline after reading option

    if (option != 1 && option != 2) {
        printf("Invalid option! Please run the program again.\n");
        return 1; // Exit with error
    }

    printf("Enter the text (max 255 characters): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please run the program again.\n");
        return 1; // Exit with error
    }

    if (option == 1) {
        encrypt(text, shift, result);
        printf("Encrypted text: %s\n", result);
    } else {
        decrypt(text, shift, result);
        printf("Decrypted text: %s\n", result);
    }

    return 0; // Exit successfully
}