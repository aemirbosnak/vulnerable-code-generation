//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_TEXT_SIZE 256
#define SHIFT_AMOUNT 3

// Function prototypes
void encryptText(char *text, int shift);
void decryptText(char *text, int shift);
void displayMenu();

int main() {
    char inputText[MAX_TEXT_SIZE];
    int choice;

    // Welcome message
    printf("🎉 Welcome to Happy Encryption Tool! 🎉\n");
    printf("Let's keep your messages safe and sound! 🛡️\n");
    
    // Main loop
    do {
        displayMenu();
        printf("Please choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer
        
        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(inputText, sizeof(inputText), stdin);
                inputText[strcspn(inputText, "\n")] = 0; // Remove newline char
                encryptText(inputText, SHIFT_AMOUNT);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                fgets(inputText, sizeof(inputText), stdin);
                inputText[strcspn(inputText, "\n")] = 0; // Remove newline char
                decryptText(inputText, SHIFT_AMOUNT);
                break;

            case 3:
                printf("Thank you for using Happy Encryption Tool! 💖\n");
                break;

            default:
                printf("🚫 Oops! Please select a valid option. 🚫\n");
                break;
        }

        printf("\n"); // New line for better readability
    } while (choice != 3);

    return 0;
}

void encryptText(char *text, int shift) {
    char encrypted[MAX_TEXT_SIZE];
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        // Encrypt only letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted[i] = (text[i] - 'A' + shift) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else {
            // Non-alphabetical characters are not changed
            encrypted[i] = text[i];
        }
    }
    encrypted[i] = '\0'; // Null-terminate the string

    printf("✨ Encrypted Text: %s ✨\n", encrypted);
}

void decryptText(char *text, int shift) {
    char decrypted[MAX_TEXT_SIZE];
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        // Decrypt only letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            decrypted[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            decrypted[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        } else {
            // Non-alphabetical characters are not changed
            decrypted[i] = text[i];
        }
    }
    decrypted[i] = '\0'; // Null-terminate the string

    printf("✨ Decrypted Text: %s ✨\n", decrypted);
}

void displayMenu() {
    printf("\n🌟 Menu 🌟\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}