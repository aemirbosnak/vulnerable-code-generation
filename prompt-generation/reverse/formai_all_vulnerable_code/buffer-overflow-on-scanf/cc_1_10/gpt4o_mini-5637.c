//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);
void getShift(int *shift);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter a message to encrypt or decrypt:\n");
    
    // Getting user input for the message
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline character

    getShift(&shift); // Function to get the shift value from the user

    printf("\nChoose an operation:\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("Selection: ");
    
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, shift);
            printf("Encrypted Message: %s\n", message);
            break;
        case 2:
            decrypt(message, shift);
            printf("Decrypted Message: %s\n", message);
            break;
        default:
            printf("Invalid choice! Please choose either 1 or 2.\n");
            break;
    }

    return 0;
}

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];
        
        if (current_char >= 'A' && current_char <= 'Z') {
            message[i] = (current_char - 'A' + shift) % 26 + 'A';
        } else if (current_char >= 'a' && current_char <= 'z') {
            message[i] = (current_char - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];

        if (current_char >= 'A' && current_char <= 'Z') {
            message[i] = (current_char - 'A' - shift + 26) % 26 + 'A';
        } else if (current_char >= 'a' && current_char <= 'z') {
            message[i] = (current_char - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

void getShift(int *shift) {
    printf("Enter shift value (1-25): ");
    scanf("%d", shift);
    
    // Validating shift value
    while (*shift < 1 || *shift > 25) {
        printf("Invalid input. Please enter a shift value between 1 and 25: ");
        scanf("%d", shift);
    }
}