//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch + shift - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[256];
    int shift;
    
    printf("==========================================\n");
    printf("   Welcome to the Caesar Cipher Tool!   \n");
    printf("==========================================\n");

    // Input the message to be encrypted
    printf("Enter a message (up to 255 characters): ");
    fgets(message, sizeof(message), stdin);
    
    // Remove the newline character
    message[strcspn(message, "\n")] = 0;

    // Input the shift value
    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure valid shift value
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please restart the program.\n");
        return 1;
    }

    printf("\nYour original message: \"%s\"\n", message);
    
    // Encrypt the message
    encrypt(message, shift);
    printf("Encrypted message: \"%s\"\n", message);
    
    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted message: \"%s\"\n", message);
    
    printf("==========================================\n");
    printf("Thank you for using the Caesar Cipher Tool!\n");
    printf("==========================================\n");

    return 0;
}