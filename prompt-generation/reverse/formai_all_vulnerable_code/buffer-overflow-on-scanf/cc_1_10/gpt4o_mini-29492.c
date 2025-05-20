//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

// Function prototypes
void encrypt(char *message, int key);
void decrypt(char *message, int key);
void printPoeticMessage();

// Main function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key;
    int choice;

    printPoeticMessage();

    printf("Enter your love letter to encrypt (max %d characters):\n", MAX_MESSAGE_LENGTH - 1);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    // Remove newline character from the input
    message[strcspn(message, "\n")] = 0;

    printf("Enter the shift key for the cipher (1 to 25):\n");
    scanf("%d", &key);

    // Ensure the key is valid
    if (key < 1 || key > 25) {
        printf("Invalid key! Please choose a key between 1 and 25.\n");
        return 1;
    }

    printf("Choose an option: \n1. Encrypt the letter \n2. Decrypt the letter\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Original Message: %s\n", message);
        encrypt(message, key);
        printf("Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        printf("Encrypted Message: %s\n", message);
        decrypt(message, key);
        printf("Decrypted Message: %s\n", message);
    } else {
        printf("Invalid choice! Please select 1 or 2.\n");
    }

    return 0;
}

// Function to encrypt the message using a Caesar cipher
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Encrypt only alphabetic characters
        if (c >= 'A' && c <= 'Z') {
            message[i] = 'A' + (c - 'A' + key) % 26;
        } else if (c >= 'a' && c <= 'z') {
            message[i] = 'a' + (c - 'a' + key) % 26;
        }
    }
}

// Function to decrypt the message using a Caesar cipher
void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Decrypt only alphabetic characters
        if (c >= 'A' && c <= 'Z') {
            message[i] = 'A' + (c - 'A' - key + 26) % 26;
        } else if (c >= 'a' && c <= 'z') {
            message[i] = 'a' + (c - 'a' - key + 26) % 26;
        }
    }
}

// Function to print a romantic message
void printPoeticMessage() {
    printf("In fair Verona, where we lay our scene,\n");
    printf("A love to treasure, a tale serene.\n");
    printf("The whispers of hearts in shadows they plight,\n");
    printf("Two souls entwined, lost in the night.\n");
    printf("Now, let us craft our words with care,\n");
    printf("For love is a cipher beyond compare.\n");
    printf("Speak now your truth, let your spirit fly,\n");
    printf("For in this moment, true love shall not die.\n");
}