//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function prototypes
void encrypt(char message[], int shift);
void decrypt(char message[], int shift);
void getShift(int *shift);

int main() {
    char message[MAX_LENGTH];
    int choice, shift;

    printf("Welcome to the Simple Caesar Cipher Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the number

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                getShift(&shift);
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                getShift(&shift);
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void encrypt(char message[], int shift) {
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

void decrypt(char message[], int shift) {
    // To decrypt, we negate the shift
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A'; // +26 to avoid negative modulo
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a'; // +26 to avoid negative modulo
        }

        message[i] = ch;
    }
}

void getShift(int *shift) {
    printf("Enter the shift value (1-25): ");
    scanf("%d", shift);
    // Ensure the shift is within the valid range
    if (*shift < 1 || *shift > 25) {
        printf("Invalid value! Defaulting shift to 3.\n");
        *shift = 3; // Default shift
    }
}