//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 256
#define ALPHABET_SIZE 26

// Function to encrypt a message using a Caesar cipher
void encryptCaesar(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - base + shift) % ALPHABET_SIZE + base;
        }
    }
}

// Function to decrypt a message using a Caesar cipher
void decryptCaesar(char *message, int shift) {
    encryptCaesar(message, ALPHABET_SIZE - shift); // Decrypt by shifting back
}

// Function to print the menu
void printMenu() {
    printf("Cryptography Program Menu:\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("3. Exit\n");
}

// Function to get user input for the shift amount
int getShift() {
    int shift;
    printf("Enter the shift amount (1-%d): ", ALPHABET_SIZE - 1);
    scanf("%d", &shift);
    while (shift < 1 || shift >= ALPHABET_SIZE) {
        printf("Invalid shift amount. Please enter a value (1-%d): ", ALPHABET_SIZE - 1);
        scanf("%d", &shift);
    }
    return shift;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int choice, shift;

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Encrypt Message
                printf("Enter the message to encrypt: ");
                getchar(); // To consume the newline character left by scanf
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character

                shift = getShift();
                encryptCaesar(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2: // Decrypt Message
                printf("Enter the message to decrypt: ");
                getchar(); // To consume the newline character
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character

                shift = getShift();
                decryptCaesar(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}