//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_decrypt(char *input, char *key) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);
    
    for (int i = 0; i < inputLen; i++) {
        input[i] = input[i] ^ key[i % keyLen];
    }
}

void getInput(char *input) {
    printf("Enter the string to encrypt (max 255 characters): ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove the newline character
}

void getKey(char *key) {
    printf("Enter the encryption key (max 255 characters): ");
    fgets(key, 256, stdin);
    key[strcspn(key, "\n")] = 0;  // Remove the newline character
}

void displayResult(const char *message, const char *result) {
    printf("%s: %s\n", message, result);
}

int main() {
    char input[256];
    char key[256];
    char choice;

    while(1) {
        getInput(input);
        getKey(key);

        // Encrypt the input
        encrypt_decrypt(input, key);
        displayResult("Encrypted String", input);

        // Ask user to decrypt
        printf("Do you want to decrypt? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n');  // Clear input buffer
        
        if (choice == 'y' || choice == 'Y') {
            // Decrypt the input
            encrypt_decrypt(input, key);
            displayResult("Decrypted String", input);
        }

        // Ask to continue or exit
        printf("Do you want to encrypt another string? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n');  // Clear input buffer
        
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Thank you for using the encryption program!\n");
    return 0;
}