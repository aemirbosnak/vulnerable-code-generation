//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void encrypt(char *input, char *output, int key) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        output[i] = input[i] ^ key; // XOR encryption
    }
    output[len] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output, int key) {
    encrypt(input, output, key); // Decryption uses the same function as encryption
}

void getUserInput(char *buffer, int size) {
    printf("Enter your text (max %d characters): ", size - 1);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character if present
}

int main() {
    char input[MAX_INPUT_SIZE];
    char encrypted[MAX_INPUT_SIZE];
    char decrypted[MAX_INPUT_SIZE];
    int key;

    printf("Simple XOR Encryption Program\n");
    
    // Get user input
    getUserInput(input, MAX_INPUT_SIZE);

    // Get encryption key
    printf("Enter the encryption key (integer): ");
    scanf("%d", &key);

    // Encrypt the input string
    encrypt(input, encrypted, key);
    printf("Encrypted text: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%02X ", (unsigned char)encrypted[i]); // Print as hex
    }
    printf("\n");

    // Decrypt the previously encrypted string
    decrypt(encrypted, decrypted, key);
    printf("Decrypted text: %s\n", decrypted);

    // Provide feedback based on the outcome
    if (strcmp(input, decrypted) == 0) {
        printf("Success! The decrypted text matches the original input.\n");
    } else {
        printf("Failure! The decrypted text does not match the original input.\n");
    }

    // Extra: Provide options for multiple encryptions
    while (1) {
        char choice;
        printf("\nWould you like to encrypt another message? (y/n): ");
        getchar(); // Clear newline from previous input
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            getUserInput(input, MAX_INPUT_SIZE);
            printf("Enter the encryption key (integer): ");
            scanf("%d", &key);

            encrypt(input, encrypted, key);
            printf("Encrypted text: ");
            for (int i = 0; i < strlen(input); i++) {
                printf("%02X ", (unsigned char)encrypted[i]); // Print as hex
            }
            printf("\n");

            decrypt(encrypted, decrypted, key);
            printf("Decrypted text: %s\n", decrypted);
            
            if (strcmp(input, decrypted) == 0) {
                printf("Success! The decrypted text matches the original input.\n");
            } else {
                printf("Failure! The decrypted text does not match the original input.\n");
            }

        } else if (choice == 'n' || choice == 'N') {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}