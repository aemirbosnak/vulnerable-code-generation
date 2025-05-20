//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);
void print_header();
void clear_buffer();

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int shift;
    int choice;

    print_header();

    while (1) {
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clear_buffer(); // Clear input buffer

        if (choice == 3) {
            printf("The world is harsh. Until next time, survivor.\n");
            break;
        }
        
        printf("Enter the secret message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        clear_buffer(); // Clear input buffer

        if (shift < 1 || shift > 25) {
            printf("Invalid shift value! Please enter a number between 1 and 25.\n");
            continue;
        }

        switch (choice) {
            case 1:
                encrypt(message, shift);
                break;
            case 2:
                decrypt(message, shift);
                break;
            default:
                printf("Invalid option! Choose 1, 2 or 3.\n");
        }
    }

    return 0;
}

void encrypt(char *message, int shift) {
    char encrypted[MAX_MESSAGE_LENGTH];
    int i;
    
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + shift) % 26 + 'A';
        } else {
            encrypted[i] = message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encrypted[i] = '\0'; // Null-terminate the encrypted string
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *message, int shift) {
    char decrypted[MAX_MESSAGE_LENGTH];
    int i;

    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        } else {
            decrypted[i] = message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted[i] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted message: %s\n", decrypted);
}

void print_header() {
    printf("========================================\n");
    printf("      Welcome to the Survivor's Code    \n");
    printf("  In a world gone dark, secrets are gold.\n");
    printf("========================================\n");
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer to handle stray newline characters
}