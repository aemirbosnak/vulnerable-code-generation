//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 256

void print_menu() {
    printf("Welcome to the Enigmatic Cryptographer!\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // Random byte
    }
    key[length] = '\0'; // Null-terminate the key
}

void xor_encrypt_decrypt(const char *input, char *output, const char *key, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i]; // XOR operation
    }
}

void encrypt_message() {
    char message[MAX_INPUT_SIZE];
    char key[16];
    char encrypted_message[MAX_INPUT_SIZE];

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_INPUT_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline

    generate_key(key, strlen(message));

    xor_encrypt_decrypt(message, encrypted_message, key, strlen(message));

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%02x", (unsigned char)encrypted_message[i]); // Print hex representation
    }
    printf("\n");
    printf("Key (in hex): ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%02x", (unsigned char)key[i]);
    }
    printf("\n");
}

void decrypt_message() {
    char encrypted_message[MAX_INPUT_SIZE];
    char key[16];
    char decrypted_message[MAX_INPUT_SIZE];

    printf("Enter the encrypted message (in hex): ");
    fgets(encrypted_message, MAX_INPUT_SIZE, stdin);
    encrypted_message[strcspn(encrypted_message, "\n")] = '\0'; // Remove newline

    printf("Enter the key (in hex): ");
    fgets(key, 34, stdin); // Every byte is represented by 2 hex digits, null terminator
    key[strcspn(key, "\n")] = '\0'; // Remove newline

    int length = strlen(encrypted_message) / 2;
    char bytes[length];

    // Convert hex string to byte array
    for (int i = 0; i < length; i++) {
        sscanf(encrypted_message + 2*i, "%2hhx", &bytes[i]);
    }

    xor_encrypt_decrypt(bytes, decrypted_message, key, length);

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input

        switch (choice) {
            case 1:
                encrypt_message();
                break;
            case 2:
                decrypt_message();
                break;
            case 3:
                printf("Exiting the Enigmatic Cryptographer. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}