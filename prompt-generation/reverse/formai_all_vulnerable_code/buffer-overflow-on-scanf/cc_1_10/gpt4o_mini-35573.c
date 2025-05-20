//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function Prototypes
void encrypt(char *input, char *output, int shift);
void decrypt(char *input, char *output, int shift);
int mainMenu();
void getInput(char *buffer, size_t length);
int validateShift(int shift);

int main() {
    int choice, shift;
    char input[MAX_LEN], output[MAX_LEN];

    while (1) {
        choice = mainMenu();

        switch (choice) {
            case 1:
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                if (!validateShift(shift)) {
                    printf("Invalid shift value! Please enter a number between 0 and 25.\n");
                    continue;
                }
                printf("Enter the plaintext: ");
                getchar(); // To consume the newline left by scanf
                getInput(input, MAX_LEN);
                encrypt(input, output, shift);
                printf("Encrypted text: %s\n", output);
                break;
            case 2:
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                if (!validateShift(shift)) {
                    printf("Invalid shift value! Please enter a number between 0 and 25.\n");
                    continue;
                }
                printf("Enter the ciphertext: ");
                getchar(); // To consume the newline left by scanf
                getInput(input, MAX_LEN);
                decrypt(input, output, shift);
                printf("Decrypted text: %s\n", output);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void encrypt(char *input, char *output, int shift) {
    int i, length = strlen(input);
    for (i = 0; i < length; i++) {
        char ch = input[i];
        // Shift only letters
        if (ch >= 'a' && ch <= 'z') {
            output[i] = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            output[i] = 'A' + (ch - 'A' + shift) % 26;
        } else {
            output[i] = ch; // Non-letters remain unchanged
        }
    }
    output[length] = '\0'; // Null-terminate the string
}

void decrypt(char *input, char *output, int shift) {
    int i, length = strlen(input);
    for (i = 0; i < length; i++) {
        char ch = input[i];
        // For shifting letters back
        if (ch >= 'a' && ch <= 'z') {
            output[i] = 'a' + (ch - 'a' - shift + 26) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            output[i] = 'A' + (ch - 'A' - shift + 26) % 26;
        } else {
            output[i] = ch; // Non-letters remain unchanged
        }
    }
    output[length] = '\0'; // Null-terminate the string
}

int mainMenu() {
    int choice;
    printf("\nCaesar Cipher Encryption Program\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

void getInput(char *buffer, size_t length) {
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int validateShift(int shift) {
    return shift >= 0 && shift <= 25;
}