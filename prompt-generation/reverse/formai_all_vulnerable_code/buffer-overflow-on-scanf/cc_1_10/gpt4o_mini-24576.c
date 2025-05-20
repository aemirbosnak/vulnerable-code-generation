//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *plainText, int shift, char *encryptedText);
void decrypt(char *encryptedText, int shift, char *decryptedText);
void displayMenu();

// Main program
int main() {
    char plainText[100], encryptedText[100], decryptedText[100];
    int shift, choice;

    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter plain text: ");
                fgets(plainText, sizeof(plainText), stdin);
                plainText[strcspn(plainText, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                encrypt(plainText, shift, encryptedText);
                printf("Encrypted text: %s\n", encryptedText);
                break;

            case 2:
                printf("Enter encrypted text: ");
                fgets(encryptedText, sizeof(encryptedText), stdin);
                encryptedText[strcspn(encryptedText, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                decrypt(encryptedText, shift, decryptedText);
                printf("Decrypted text: %s\n", decryptedText);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}

// Function to encrypt the plain text using Caesar cipher
void encrypt(char *plainText, int shift, char *encryptedText) {
    int i;
    for (i = 0; plainText[i] != '\0'; ++i) {
        char currentChar = plainText[i];

        // Encrypt uppercase letters
        if (currentChar >= 'A' && currentChar <= 'Z') {
            encryptedText[i] = (currentChar + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (currentChar >= 'a' && currentChar <= 'z') {
            encryptedText[i] = (currentChar + shift - 'a') % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            encryptedText[i] = currentChar;
        }
    }
    encryptedText[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the encrypted text using Caesar cipher
void decrypt(char *encryptedText, int shift, char *decryptedText) {
    int i;
    for (i = 0; encryptedText[i] != '\0'; ++i) {
        char currentChar = encryptedText[i];

        // Decrypt uppercase letters
        if (currentChar >= 'A' && currentChar <= 'Z') {
            decryptedText[i] = (currentChar - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (currentChar >= 'a' && currentChar <= 'z') {
            decryptedText[i] = (currentChar - shift - 'a' + 26) % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            decryptedText[i] = currentChar;
        }
    }
    decryptedText[i] = '\0'; // Null-terminate the string
}

// Function to display the menu
void displayMenu() {
    printf("Cryptography Program\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
}