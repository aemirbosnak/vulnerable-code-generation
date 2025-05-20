//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *plainText, char *cipherText, int key) {
    int i = 0;
    while (plainText[i] != '\0') {
        // Encrypt uppercase letters
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = (plainText[i] - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = (plainText[i] - 'a' + key) % 26 + 'a';
        } else {
            cipherText[i] = plainText[i];  // Copy other characters unchanged
        }
        i++;
    }
    cipherText[i] = '\0';  // Null-terminate the string
}

void decrypt(char *cipherText, char *plainText, int key) {
    int i = 0;
    while (cipherText[i] != '\0') {
        // Decrypt uppercase letters
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z') {
            plainText[i] = (cipherText[i] - 'A' - key + 26) % 26 + 'A';  // +26 to handle negative values
        }
        // Decrypt lowercase letters
        else if (cipherText[i] >= 'a' && cipherText[i] <= 'z') {
            plainText[i] = (cipherText[i] - 'a' - key + 26) % 26 + 'a';  // +26 to handle negative values
        } else {
            plainText[i] = cipherText[i];  // Copy other characters unchanged
        }
        i++;
    }
    plainText[i] = '\0';  // Null-terminate the string
}

int main() {
    char plainText[MAX_LEN];
    char cipherText[MAX_LEN];
    char decryptedText[MAX_LEN];
    int key;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter your message (max length %d characters): ", MAX_LEN - 1);
    fgets(plainText, MAX_LEN, stdin);
    
    // Remove newline character if it exists
    size_t len = strlen(plainText);
    if (len > 0 && plainText[len - 1] == '\n') {
        plainText[len - 1] = '\0';
    }

    printf("Enter the encryption key (number): ");
    scanf("%d", &key);

    // Ensure key is positive
    if (key < 0) {
        printf("Key must be a positive integer. Converting to positive.\n");
        key = -key;
    }

    printf("\nEncrypting your message...\n");
    encrypt(plainText, cipherText, key);
    printf("Encrypted Message: %s\n", cipherText);

    printf("\nDecrypting your message...\n");
    decrypt(cipherText, decryptedText, key);
    printf("Decrypted Message: %s\n", decryptedText);

    printf("\nThank you for using the Caesar Cipher Encryption Program! Goodbye!\n");
    
    return 0;
}