//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

// Function to encrypt the message
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        
        message[i] = ch; // Assign the encrypted character back
    }
}

// Function to decrypt the message
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';
        }
        
        message[i] = ch; // Assign the decrypted character back
    }
}

// Function to display the menu
void displayMenu() {
    printf("====================================\n");
    printf("      Welcome to Cipher Tool       \n");
    printf("====================================\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("====================================\n");
    printf("Please choose an option: ");
}

// Function to get valid shift value
int getShiftValue() {
    int shift;
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Validate the shift value
    while (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please select a value between 1 and 25: ");
        scanf("%d", &shift);
    }
    
    return shift;
}

// Main function
int main() {
    char message[MAX_LENGTH];
    int choice, shift;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                getchar(); // Clear newline from buffer
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline from string
                
                shift = getShiftValue();
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter a message to decrypt: ");
                getchar(); // Clear newline from buffer
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline from string
                
                shift = getShiftValue();
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the Cipher Tool. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}