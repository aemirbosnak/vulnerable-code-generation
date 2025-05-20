//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for(i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            ciphertext[i] = (c - 'a' + shift) % 26 + 'a';
        }
        // Leave non-alphabetic characters unchanged
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt the ciphertext back into plaintext
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for(i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            plaintext[i] = (c - 'A' - shift + 26) % 26 + 'A'; // +26 to handle negative shift
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            plaintext[i] = (c - 'a' - shift + 26) % 26 + 'a'; // +26 to handle negative shift
        }
        // Leave non-alphabetic characters unchanged
        else {
            plaintext[i] = c;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}

// Function to get valid shift value
int get_valid_shift() {
    int shift;
    while (1) {
        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        if (shift >= 1 && shift <= 25) {
            return shift;
        }
        printf("Invalid shift value. Please try again.\n");
    }
}

// Main function
int main() {
    char plaintext[1024];
    char ciphertext[1024];
    char decrypted[1024];
    int shift;

    printf("Enter the plaintext to encrypt: ");
    getchar(); // To consume newline character left by previous input
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character at the end
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    shift = get_valid_shift();
    
    // Encrypt the input
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    
    // Decrypt the input
    decrypt(ciphertext, shift, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}