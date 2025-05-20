//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "abcdefghijklmnopqrstuvwxyz"

// Function to encrypt the message
void encrypt(char *message, char *encrypted_message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        // Convert the message to lowercase
        message[i] = tolower(message[i]);

        // Encrypt the message by shifting each character
        char c = message[i];
        encrypted_message[j++] = (c >= 'a' && c <= 'z')? c + 3 : c;
    }
    encrypted_message[j] = '\0';
}

// Function to decrypt the message
void decrypt(char *encrypted_message, char *decrypted_message) {
    int i, j;
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        // Convert the encrypted message to lowercase
        encrypted_message[i] = tolower(encrypted_message[i]);

        // Decrypt the message by shifting each character
        char c = encrypted_message[i];
        decrypted_message[j++] = (c >= 'a' && c <= 'z')? c - 3 : c;
    }
    decrypted_message[j] = '\0';
}

// Function to display the menu and get the user's choice
void display_menu() {
    printf("Enter your choice:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
}

int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    int choice;

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Get the user's choice
    display_menu();
    scanf("%d", &choice);

    // Perform the chosen operation
    switch (choice) {
        case 1:
            // Encrypt the message
            encrypt(message, encrypted_message);
            printf("Encrypted message: %s\n", encrypted_message);
            break;
        case 2:
            // Decrypt the message
            decrypt(encrypted_message, decrypted_message);
            printf("Decrypted message: %s\n", decrypted_message);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}