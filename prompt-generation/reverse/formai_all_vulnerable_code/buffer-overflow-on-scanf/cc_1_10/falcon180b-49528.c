//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[i] = '\0';
}

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, char* key, char* encrypted_message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((int) message[i] + (int) key[i % strlen(key)] - 97 % 26 + 97);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i;
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (char) ((int) encrypted_message[i] - (int) key[i % strlen(key)] + 97 % 26 - 97);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[i] = '\0';
}

// Function to display the menu
void display_menu() {
    printf("Enter your choice:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int choice;
    bool valid_choice = TRUE;

    printf("Welcome to the Modern Encryption program!\n");
    printf("This program uses the Caesar cipher to encrypt and decrypt messages.\n");

    // Generate a random key
    generate_key(key);
    printf("Your key is: %s\n", key);

    // Main loop
    while (valid_choice) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Encrypt message
                printf("Enter your message:\n");
                scanf("%[^\n]", message);
                encrypt(message, key, encrypted_message);
                printf("Encrypted message: %s\n", encrypted_message);
                break;

            case 2: // Decrypt message
                printf("Enter your encrypted message:\n");
                scanf("%[^\n]", encrypted_message);
                decrypt(encrypted_message, key, decrypted_message);
                printf("Decrypted message: %s\n", decrypted_message);
                break;

            case 3: // Exit
                valid_choice = FALSE;
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}