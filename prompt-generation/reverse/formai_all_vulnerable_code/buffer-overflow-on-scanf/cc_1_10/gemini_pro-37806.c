//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character using a given key
char encryptChar(char ch, int key) {
    return (ch + key) % 128;
}

// Function to decrypt a character using a given key
char decryptChar(char ch, int key) {
    return (ch - key) % 128;
}

// Function to encrypt a string using a given key
char* encryptString(char* str, int key) {
    int len = strlen(str);
    char* encryptedStr = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encryptedStr[i] = encryptChar(str[i], key);
    }
    encryptedStr[len] = '\0';
    return encryptedStr;
}

// Function to decrypt a string using a given key
char* decryptString(char* str, int key) {
    int len = strlen(str);
    char* decryptedStr = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        decryptedStr[i] = decryptChar(str[i], key);
    }
    decryptedStr[len] = '\0';
    return decryptedStr;
}

// Main function
int main() {
    // Get the plaintext and the encryption key from the user
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the encryption key (an integer between 0 and 127): ");
    scanf("%d", &key);

    // Encrypt the plaintext using the given key
    char* encryptedText = encryptString(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", encryptedText);

    // Decrypt the ciphertext using the given key
    char* decryptedText = decryptString(encryptedText, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decryptedText);

    // Free the allocated memory
    free(encryptedText);
    free(decryptedText);

    return 0;
}