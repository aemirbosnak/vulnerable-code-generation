//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void displayMenu();

// Main function
int main() {
    char text[256];
    int shift, choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter text to encrypt: ");
            getchar(); // Consume the newline character from previous input
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0'; // Remove the trailing newline
            
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            shift = shift % 26; // Wrap around shift value
            encrypt(text, shift);
            printf("Encrypted text: %s\n", text);
        } else if (choice == 2) {
            printf("Enter text to decrypt: ");
            getchar(); // Consume the newline
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0'; // Remove the trailing newline
            
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            shift = shift % 26; // Wrap around shift value
            decrypt(text, shift);
            printf("Decrypted text: %s\n", text);
        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    shift = 26 - shift; // Reverse the shift for decryption
    encrypt(text, shift); // Reuse the encrypt function
}

// Function to display menu options
void displayMenu() {
    printf("\n*** Caesar Cipher Menu ***\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
}