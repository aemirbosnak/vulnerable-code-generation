//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a string using Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char a = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - a + shift) % 26 + a;
        }
    }
}

// Function to decrypt a string using Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char a = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - a - shift + 26) % 26 + a; // Adding 26 to handle negative shifts
        }
    }
}

int main() {
    char message[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Please choose an option (1-3): ");
        
        // Input validation for choice
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear the invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                while (getchar() != '\n'); // Clear the buffer before reading a string
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                
                printf("Enter shift value (1-25): ");
                while (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                    printf("Invalid shift! Enter a value between 1 and 25: ");
                    while(getchar() != '\n'); // Clear the invalid input
                }

                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter a message to decrypt: ");
                while (getchar() != '\n'); // Clear the buffer before reading a string
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                
                printf("Enter shift value (1-25): ");
                while (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                    printf("Invalid shift! Enter a value between 1 and 25: ");
                    while(getchar() != '\n');
                }

                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
                break;
        }
    }

    return 0;
}