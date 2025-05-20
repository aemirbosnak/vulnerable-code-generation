//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *input, const char *key);
void decrypt(char *input, const char *key);
void generate_key(char *key, int length);
void print_result(const char *label, const char *result);

int main() {
    char input[256];
    char key[16];
    int choice;

    printf("Welcome to the minimalist C Encryption Program!\n");
    printf("Please enter the text to encrypt/decrypt: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character, if present
    input[strcspn(input, "\n")] = '\0';

    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Generate a new random key\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
            case 1:
                generate_key(key, sizeof(key) - 1);
                encrypt(input, key);
                break;
            case 2:
                decrypt(input, key);
                break;
            case 3:
                generate_key(key, sizeof(key) - 1);
                printf("Generated Key: %s\n", key);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to encrypt the input text using the key
void encrypt(char *input, const char *key) {
    char output[256];
    size_t input_length = strlen(input);
    
    for (size_t i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[input_length] = '\0'; // Null terminate string
    print_result("Encrypted Text", output);
}

// Function to decrypt the input text using the key
void decrypt(char *input, const char *key) {
    char output[256];
    size_t input_length = strlen(input);
    
    for (size_t i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[input_length] = '\0'; // Null terminate string
    print_result("Decrypted Text", output);
}

// Function to generate a random key
void generate_key(char *key, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[length] = '\0'; // Null terminate string
}

// Function to print results
void print_result(const char *label, const char *result) {
    printf("%s: %s\n", label, result);
}