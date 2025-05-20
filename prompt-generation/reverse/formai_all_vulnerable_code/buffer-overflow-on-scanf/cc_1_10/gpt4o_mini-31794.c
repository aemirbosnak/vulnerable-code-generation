//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define KEY 5 // Simple key for Caesar cipher

// Function to encrypt the input text using a Caesar cipher
void encryptCaesar(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        // Encrypt lowercase letters
        if (c >= 'a' && c <= 'z') {
            // Wrap around if necessary
            c = ((c - 'a' + key) % 26) + 'a';
        }
        // Encrypt uppercase letters
        else if (c >= 'A' && c <= 'Z') {
            // Wrap around if necessary
            c = ((c - 'A' + key) % 26) + 'A';
        }
        text[i] = c; // Store the encrypted character back into the text
    }
}

// Function to decrypt the input text using a Caesar cipher
void decryptCaesar(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        // Decrypt lowercase letters
        if (c >= 'a' && c <= 'z') {
            // Wrap around if necessary
            c = ((c - 'a' - key + 26) % 26) + 'a';
        }
        // Decrypt uppercase letters
        else if (c >= 'A' && c <= 'Z') {
            // Wrap around if necessary
            c = ((c - 'A' - key + 26) % 26) + 'A';
        }
        text[i] = c; // Store the decrypted character back into the text
    }
}

// Function to read text from the user
void readInput(char *buffer, size_t size) {
    printf("Enter text: ");
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove the newline character if it's present
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// Function to display the menu for the user
void displayMenu() {
    printf("Caesar Cipher Menu:\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Main function to drive the program
int main() {
    char text[MAX_LENGTH];
    int choice;

    // Start the interactive menu
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        // Clear the input buffer
        getchar();

        switch (choice) {
            case 1:
                readInput(text, MAX_LENGTH);
                encryptCaesar(text, KEY);
                printf("Encrypted text: %s\n", text);
                break;
            case 2:
                readInput(text, MAX_LENGTH);
                decryptCaesar(text, KEY);
                printf("Decrypted text: %s\n", text);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}