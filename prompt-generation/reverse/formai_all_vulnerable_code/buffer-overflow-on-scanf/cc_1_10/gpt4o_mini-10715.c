//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a simple Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
        // Leave any other characters unchanged
    }
}

// Function to decrypt a message using a simple Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        }
        // Leave any other characters unchanged
    }
}

int main() {
    int shift;
    char message[256];

    printf("Welcome to the Retro Cipher Program!\n");
    printf("-------------------------------------\n");

    // Input the message
    printf("Enter your message (up to 255 characters): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline character

    // Input the shift value for cipher
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    if(shift < 1 || shift > 25) {
        printf("Invalid shift value! It must be between 1 and 25.\n");
        return 1;
    }

    // Encrypt the message
    encrypt(message, shift);
    printf("\nEncrypted Message: %s\n", message);

    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted Message: %s\n", message);

    printf("-------------------------------------\n");
    printf("Thank you for using the Retro Cipher Program!\n");

    return 0;
}