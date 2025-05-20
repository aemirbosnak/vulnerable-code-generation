//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

// Function to encrypt the message
void encrypt(char *message, char *key, char *encrypted_message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = key[message[i] - 'a'];
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = key[message[i] - 'A'] - 32; // Convert to uppercase
        } else {
            encrypted_message[i] = message[i]; // Non-alphabetic characters stay the same
        }
    }
    encrypted_message[strlen(message)] = '\0'; // Null-terminate the string
}

// Function to decrypt the message
void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    for (int i = 0; encrypted_message[i] != '\0'; i++) {
        char *ptr = strchr(key, encrypted_message[i]);
        if (ptr) {
            int index = ptr - key;
            decrypted_message[i] = 'a' + index; // Change to lowercase letter
        } else {
            decrypted_message[i] = encrypted_message[i]; // Non-alphabetic characters stay the same
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0'; // Null-terminate the string
}

// Function to display the menu and get user choice
int menu() {
    int choice;
    printf("\nSimple Encryption/Decryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    char key[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 
                   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 
                   'x', 'c', 'v', 'b', 'n', 'm'}; // Simple substitution key
    char message[MAX_LEN];
    char encrypted_message[MAX_LEN];
    char decrypted_message[MAX_LEN];
    int choice;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // Clear the newline from input buffer
                fgets(message, MAX_LEN, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                encrypt(message, key, encrypted_message);
                printf("Encrypted message: %s\n", encrypted_message);
                break;
            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // Clear the newline from input buffer
                fgets(encrypted_message, MAX_LEN, stdin);
                encrypted_message[strcspn(encrypted_message, "\n")] = 0; // Remove newline character
                decrypt(encrypted_message, key, decrypted_message);
                printf("Decrypted message: %s\n", decrypted_message);
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