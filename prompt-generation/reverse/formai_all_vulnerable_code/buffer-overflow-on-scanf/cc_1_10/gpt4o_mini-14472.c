//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function prototypes
void encrypt_caesar(const char *plaintext, char *ciphertext, int key);
void decrypt_caesar(const char *ciphertext, char *plaintext, int key);
void get_input(char *input, const char *prompt);
int validate_key(int key);

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];
    int key;

    // Get plaintext from the user
    get_input(plaintext, "Enter the plaintext: ");
    
    // Get key for encryption
    printf("Enter the key for encryption (1-25): ");
    scanf("%d", &key);
    
    if (!validate_key(key)) {
        printf("Invalid key! Key must be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    // Perform encryption
    encrypt_caesar(plaintext, ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

    // Perform decryption
    decrypt_caesar(ciphertext, decryptedtext, key);
    printf("Decrypted text: %s\n", decryptedtext);

    return EXIT_SUCCESS;
}

// Function to encrypt plaintext using Caesar cipher
void encrypt_caesar(const char *plaintext, char *ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Keep non-alphabet characters unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt ciphertext using Caesar cipher
void decrypt_caesar(const char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Keep non-alphabet characters unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// Function to safely get input from the user
void get_input(char *input, const char *prompt) {
    printf("%s", prompt);
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character if present
}

// Function to validate the encryption key
int validate_key(int key) {
    return key >= 1 && key <= 25;
}