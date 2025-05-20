//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the plain text
void encrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // Check if character is alphabet
            char offset = islower(text[i]) ? 'a' : 'A'; // Determine if the character is lower or upper case
            text[i] = (text[i] - offset + key) % 26 + offset; // Encrypt the character
        }
    }
}

// Function to decrypt the cipher text
void decrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // Check if character is alphabet
            char offset = islower(text[i]) ? 'a' : 'A'; // Determine if the character is lower or upper case
            text[i] = (text[i] - offset - key + 26) % 26 + offset; // Decrypt the character
        }
    }
}

// Function to get input from user
void getInput(char *text, int *key) {
    printf("Enter the text: ");
    fgets(text, 1024, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter the key (1-25): ");
    scanf("%d", key);
    while (*key < 1 || *key > 25) {
        printf("Invalid key! Please enter a key (1-25): ");
        scanf("%d", key);
    }
}

// Function to display options
void displayOptions() {
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    char text[1024];
    int key;
    int choice;

    do {
        displayOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                getInput(text, &key);
                encrypt(text, key);
                printf("Encrypted text: %s\n", text);
                break;
            case 2:
                getInput(text, &key);
                decrypt(text, key);
                printf("Decrypted text: %s\n", text);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}