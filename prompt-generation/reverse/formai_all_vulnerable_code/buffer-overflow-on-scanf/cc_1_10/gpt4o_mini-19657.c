//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt/decrypt the text using XOR cipher
void xor_cipher(char *input, char *output, char *key) {
    int key_length = strlen(key);
    for(int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to read a line of input
void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    }
}

// Main function
int main() {
    char input[256], output[256], key[32];
    int choice;

    printf("Simple XOR Cipher Program\n");
    printf("Enter a key (max 31 characters): ");
    read_line(key, sizeof(key));

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                read_line(input, sizeof(input));
                xor_cipher(input, output, key);
                printf("Encrypted result: %s\n", output);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                read_line(input, sizeof(input));
                xor_cipher(input, output, key);
                printf("Decrypted result: %s\n", output);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}