//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *plaintext, char *ciphertext, int shift);
void decrypt(char *ciphertext, char *plaintext, int shift);
void displayMenu();
void clearBuffer();

int main() {
    char plaintext[256];
    char ciphertext[256];
    int shift, choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer to avoid any hanging input

        switch (choice) {
            case 1:
                printf("Enter the plaintext: ");
                fgets(plaintext, sizeof(plaintext), stdin);
                plaintext[strcspn(plaintext, "\n")] = 0; // Remove the newline character
                
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                
                encrypt(plaintext, ciphertext, shift);
                printf("Encrypted text: %s\n", ciphertext);
                break;

            case 2:
                printf("Enter the ciphertext: ");
                fgets(ciphertext, sizeof(ciphertext), stdin);
                ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove the newline character
                
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                
                decrypt(ciphertext, plaintext, shift);
                printf("Decrypted text: %s\n", plaintext);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void encrypt(char *plaintext, char *ciphertext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

void decrypt(char *ciphertext, char *plaintext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - shift + 26) % 26 + 'A'; // Add 26 for wrap-around
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - shift + 26) % 26 + 'a'; // Add 26 for wrap-around
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}

void displayMenu() {
    printf("\n===== Caesar Cipher Program =====\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}; // Clear the input buffer
}