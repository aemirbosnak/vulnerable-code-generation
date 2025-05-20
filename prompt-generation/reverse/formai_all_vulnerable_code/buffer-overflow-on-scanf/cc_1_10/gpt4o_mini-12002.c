//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

void encrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        // Encrypt only alphabetical characters
        if ((text[i] >= 'a' && text[i] <= 'z')) {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        } else if ((text[i] >= 'A' && text[i] <= 'Z')) {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
    text[i] = '\0'; // Null terminate the string
}

void decrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        // Decrypt only alphabetical characters
        if ((text[i] >= 'a' && text[i] <= 'z')) {
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        } else if ((text[i] >= 'A' && text[i] <= 'Z')) {
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
    text[i] = '\0'; // Null terminate the string
}

void get_input(char *buffer, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, MAX_TEXT_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character
}

int main() {
    char text[MAX_TEXT_SIZE];
    int key;
    char choice;

    printf("Welcome to the Curious C Encryption Program!\n");
    printf("This program will guide you to encrypt and decrypt text.\n");

    get_input(text, "Enter the text to encrypt (max 1023 characters): ");
    
    printf("Enter a key for encryption (0-25): ");
    while (scanf("%d", &key) != 1 || key < 0 || key > 25) {
        printf("Invalid key! Please enter a valid key (0-25): ");
        while (getchar() != '\n'); // Clear the buffer
    }

    printf("You chose to encrypt the text: %s with key: %d\n", text, key);
    
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

    // Reset for decryption
    printf("Would you like to decrypt the text? (y/n): ");
    while (getchar() != '\n'); // Clear the buffer
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("No decryption will be performed. You can try again later!\n");
    }

    printf("Thank you for using the Curious C Encryption Program!\n");
    return 0;
}