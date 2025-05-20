//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        // Update the text
        text[i] = ch;
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A'; // Adding 26 to handle negative shift
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a'; // Adding 26 to handle negative shift
        }
        // Update the text
        text[i] = ch;
    }
}

// Function to display a menu for user choices
void displayMenu() {
    printf("Caesar Cipher - Encrypt / Decrypt Tool\n");
    printf("Choose an option:\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    char text[256];
    int shift, choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                getchar(); // To consume the newline character
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Removing newline character from input
                printf("Enter shift value (positive integer): ");
                scanf("%d", &shift);
                
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                getchar(); // To consume the newline character
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Removing newline character from input
                printf("Enter shift value (positive integer): ");
                scanf("%d", &shift);
                
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}