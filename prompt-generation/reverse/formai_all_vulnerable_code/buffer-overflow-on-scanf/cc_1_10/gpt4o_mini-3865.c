//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1024
#define ENCRYPTION_KEY 0xAB // Simple XOR key for demonstration

void encrypt(char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY; // XOR encryption
    }
    output[strlen(input)] = '\0'; // Null terminate the string
}

void decrypt(char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY; // XOR decryption
    }
    output[strlen(input)] = '\0'; // Null terminate the string
}

void displayMenu() {
    printf("\n--- Simple C Encryption Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("-----------------------------------\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    int choice;

    printf("Welcome to the visionary C Encryption tool!\n");
    printf("This program allows you to encrypt and decrypt messages.\n");

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                strtok(input, "\n"); // Remove trailing newline
                
                encrypt(input, output);
                printf("Encrypted message: ");
                for (int i = 0; i < strlen(input); i++)
                    printf("%02X ", (unsigned char) output[i]); // Print as hexadecimal
                printf("\n");
                break;

            case 2:
                printf("Enter the message to decrypt (in hex format): ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                char *ptr = strtok(input, " ");
                int index = 0;

                while (ptr != NULL && index < MAX_INPUT_LENGTH) {
                    output[index++] = (char) strtol(ptr, NULL, 16); // Convert hex back to char
                    ptr = strtok(NULL, " ");
                }
                output[index] = '\0'; // Null terminate

                decrypt(output, input); // Decode the encrypted output
                printf("Decrypted message: %s\n", input);
                break;

            case 3:
                printf("Exiting the program. Thank you for using our encryption tool!\n");
                exit(0);

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}