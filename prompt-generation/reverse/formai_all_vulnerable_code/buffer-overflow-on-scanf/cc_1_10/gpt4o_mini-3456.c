//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the input text using XOR cipher
void xorCipher(char *input, const char *key, char *output) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    output[inputLen] = '\0'; // Null-terminate the output string
}

// Function to read input from the user
void readInput(char *buffer, size_t size) {
    printf("Enter text: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Function to display usage instructions
void displayInstructions() {
    printf("Simple XOR Encryption/Decryption Program\n");
    printf("1. Enter text to be encrypted.\n");
    printf("2. Enter a key for encryption/decryption.\n");
    printf("3. The same key is used for both encrypting and decrypting.\n");
}

int main() {
    char inputText[256];
    char key[64];
    char encryptedText[256];
    char decryptedText[256];

    displayInstructions();
    
    // Read the input text from the user
    readInput(inputText, sizeof(inputText));
    
    // Request key for encryption/decryption
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    // Encrypt the input text
    xorCipher(inputText, key, encryptedText);
    printf("Encrypted Text: %s\n", encryptedText);

    // Decrypt the encrypted text
    xorCipher(encryptedText, key, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText);

    // Bonus: Allow user to retry with new input and key
    char choice;
    while (1) {
        printf("Would you like to encrypt/decrypt another text? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clear buffer

        if (choice == 'y' || choice == 'Y') {
            readInput(inputText, sizeof(inputText));
            printf("Enter key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = 0; // Remove newline character
            
            xorCipher(inputText, key, encryptedText);
            printf("Encrypted Text: %s\n", encryptedText);
            xorCipher(encryptedText, key, decryptedText);
            printf("Decrypted Text: %s\n", decryptedText);
        } else {
            break;
        }
    }

    printf("Thank you for using the encryption program!\n");
    return 0;
}