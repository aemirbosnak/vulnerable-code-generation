//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Other characters remain the same
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        }
        // Other characters remain the same
    }
}

int main() {
    char message[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    
    // Inputting the message and shift value
    printf("Enter your message (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    
    // Remove the newline character if it is present
    message[strcspn(message, "\n")] = 0;

    printf("Choose the shift value (1 to 25): ");
    scanf("%d", &shift);
    
    // Ensuring the shift is in valid range
    if (shift < 1 || shift > 25) {
        printf("Please enter a valid shift value between 1 and 25.\n");
        return 1;
    }

    // Asking the user for the operation
    printf("What would you like to do?\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, shift);
        printf("Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("Decrypted Message: %s\n", message);
    } else {
        printf("Invalid choice. Please select either 1 or 2.\n");
    }

    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}