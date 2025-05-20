//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);

int main() {
    char text[256];
    int shift;
    int choice;

    printf("🌟 Welcome to the Enchanted Message Protector! 🌟\n");
    printf("Enter the secret text (max 255 characters): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove the newline character

    printf("Enter the magic number (shift value) for encryption (1-25): ");
    scanf("%d", &shift);
    shift = shift % 26;  // Ensure the shift is within the range of 0-25

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Encrypt the message\n");
        printf("2. Decrypt the message\n");
        printf("3. Exit the enchanted realm\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("✨ Encrypted message: ");
                encrypt(text, shift);
                printf("\n");
                break;
            case 2:
                printf("🔑 Decrypted message: ");
                decrypt(text, shift);
                printf("\n");
                break;
            case 3:
                printf("🌌 Farewell, traveler! Until we meet again in the realm of encrypted messages!\n");
                break;
            default:
                printf("🚫 Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

void encrypt(char *text, int shift) {
    char encrypted[256];
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            encrypted[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            encrypted[i] = (c + shift - 'a') % 26 + 'a';
        }
        // Preserve other characters
        else {
            encrypted[i] = c;
        }
    }
    encrypted[i] = '\0';  // Null terminate the string
    printf("%s", encrypted);
}

void decrypt(char *text, int shift) {
    char decrypted[256];
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            decrypted[i] = (c - shift - 'A' + 26) % 26 + 'A'; // wrap around
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            decrypted[i] = (c - shift - 'a' + 26) % 26 + 'a'; // wrap around
        }
        // Preserve other characters
        else {
            decrypted[i] = c;
        }
    }
    decrypted[i] = '\0';  // Null terminate the string
    printf("%s", decrypted);
}