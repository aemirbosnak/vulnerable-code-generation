//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function prototypes
void encryptMessage(char *message, int shift);
void decryptMessage(char *message, int shift);
void displayMenu();

// Main function
int main() {
    int choice, shift;
    char message[256];

    printf("Welcome to the Exciting Caesar Cipher Encryption Program!\n");
    printf("---------------------------------\n");

    while (1) {
        displayMenu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter your message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                encryptMessage(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter your message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                decryptMessage(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Thank you for using the Caesar Cipher Program!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
        printf("\n");  // Newline for better output formatting
    }

    return 0;
}

// Function to encrypt the message
void encryptMessage(char *message, int shift) {
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
        message[i] = ch;
    }
}

// Function to decrypt the message
void decryptMessage(char *message, int shift) {
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
        message[i] = ch;
    }
}

// Function to display the main menu
void displayMenu() {
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("---------------------------------\n");
}