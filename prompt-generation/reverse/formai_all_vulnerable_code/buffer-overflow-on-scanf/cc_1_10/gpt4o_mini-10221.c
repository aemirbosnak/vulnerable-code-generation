//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int key, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ciphertext[i] = (ch - offset + key) % 26 + offset;
        } else {
            ciphertext[i] = ch;  // Non-alpha characters remain unchanged
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(char *ciphertext, int key, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            plaintext[i] = (ch - offset - key + 26) % 26 + offset;
        } else {
            plaintext[i] = ch;  // Non-alpha characters remain unchanged
        }
        i++;
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// Function to get the integer key securely
int get_key() {
    int key;
    while (1) {
        printf("Enter a key for encryption (0-25): ");
        if (scanf("%d", &key) == 1 && key >= 0 && key <= 25) {
            break;
        } else {
            printf("Invalid input. Please enter a number between 0 and 25.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
    return key;
}

// Function to read a line of text securely
void read_line(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline character
        }
    }
}

int main() {
    char plaintext[1024];
    char ciphertext[1024];
    char decryptedtext[1024];
    int key;

    // Get the encryption key
    key = get_key();
    
    // Get user input for plaintext
    printf("Enter plaintext: ");
    read_line(plaintext, sizeof(plaintext));

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}