//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decrypting is simply encrypting with (26 - shift)
}

// Function to get and validate the shift input from the user
int get_shift() {
    int shift;
    printf("Enter shift value (1-25): ");
    while (1) {
        scanf("%d", &shift);
        if (shift >= 1 && shift <= 25) {
            break;
        } else {
            printf("Invalid input. Please enter a valid shift value (1-25): ");
        }
    }
    return shift;
}

// Function to get text input from the user
void get_text(char *text) {
    printf("Enter text to encrypt/decrypt: ");
    getchar(); // Clear the newline left by scanf
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline
}

// Function to display the menu and get user choice
char display_menu() {
    char choice;
    printf("\n--- Caesar Cipher Program ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
    scanf(" %c", &choice);
    return choice;
}

// Main function to run the program
int main() {
    char text[MAX_LENGTH];
    int shift;
    char choice;

    while (1) {
        choice = display_menu();
        switch (choice) {
            case '1':
                get_text(text);
                shift = get_shift();
                encrypt(text, shift);
                printf("Encrypted Text: %s\n", text);
                break;
            case '2':
                get_text(text);
                shift = get_shift();
                decrypt(text, shift);
                printf("Decrypted Text: %s\n", text);
                break;
            case '3':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}