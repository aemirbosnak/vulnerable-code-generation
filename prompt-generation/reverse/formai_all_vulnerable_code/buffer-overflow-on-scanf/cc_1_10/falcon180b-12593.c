//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given message
void encrypt(char* message, int key) {
    int i = 0;

    // Iterate through the message and encrypt each character
    while (message[i]) {
        if (isalpha(message[i])) {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Encrypt the character using the key
            if (isalpha(message[i])) {
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            }
        }
        i++;
    }
}

// Function to decrypt the given message
void decrypt(char* message, int key) {
    int i = 0;

    // Iterate through the message and decrypt each character
    while (message[i]) {
        if (isalpha(message[i])) {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Decrypt the character using the key
            if (isalpha(message[i])) {
                message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            }
        }
        i++;
    }
}

// Function to display the menu
void menu() {
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("3. Exit\n");
}

int main() {
    char message[1000];
    int key, choice;

    // Initialize the key
    key = 3;

    // Loop until the user chooses to exit
    while (1) {
        // Display the menu
        menu();

        // Get the user's choice
        scanf("%d", &choice);

        // Get the message from the user
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        // Remove the newline character from the message
        message[strcspn(message, "\n")] = '\0';

        // Perform the selected operation
        switch (choice) {
            case 1:
                // Encrypt the message
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case 2:
                // Decrypt the message
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            case 3:
                // Exit the program
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice!\n");
        }
    }

    return 0;
}