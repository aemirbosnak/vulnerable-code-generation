//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define SHIFT 4 // The number of positions to shift in the encryption

void encrypt(char *input, char *output) {
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + SHIFT) % 26) + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters are unchanged
        }
    }
    output[length] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output) {
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' - SHIFT + 26) % 26) + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters are unchanged
        }
    }
    output[length] = '\0'; // Null-terminate the output string
}

void menu() {
    printf("====== Modern Encryption Program ======\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=======================================\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline after entering choice

        switch (choice) {
            case 1:
                printf("Enter message to encrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                encrypt(input, output);
                printf("Encrypted message: %s\n", output);
                break;
            case 2:
                printf("Enter message to decrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                decrypt(input, output);
                printf("Decrypted message: %s\n", output);
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}