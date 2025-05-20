//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a Caesar Cipher with a dynamic key
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift each character by the key
        message[i] = (message[i] + key) % 256; // Wrap around using modulo 256
    }
}

// Function to decrypt the message using the same key
void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Reverse the shift by subtracting the key
        message[i] = (message[i] - key + 256) % 256; // Ensure positive value
    }
}

// Function to calculate the dynamic key based on message
int calculate_dynamic_key(char *message) {
    int sum = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        sum += (int)message[i]; // Accumulate ASCII values
    }
    return sum % 26; // Use modulo 26 to keep key within bounds of alphabet
}

// Function to display help information
void display_help() {
    printf("Simple Caesar Cipher Encryption/Decryption\n");
    printf("Usage:\n");
    printf("1. Input message to encrypt.\n");
    printf("2. To decrypt, input the encrypted message back.\n");
    printf("3. The key is dynamically calculated.\n");
}

int main() {
    char message[256];
    int choice;

    display_help();

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline after choice

        switch(choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character

                int encrypt_key = calculate_dynamic_key(message);
                encrypt(message, encrypt_key);
                printf("Encrypted message: ");
                for (int i = 0; message[i] != '\0'; i++) {
                    printf("%02X ", (unsigned char)message[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("Enter the encrypted message (hex format, space separated): ");
                for (int i = 0; i < sizeof(message) / 3; i++) {
                    unsigned int num;
                    if(scanf("%2X", &num) != 1) break; // Read hex
                    message[i] = (char)num; // Store as character
                }
                message[sizeof(message) / 3] = '\0'; // Null terminate the message

                int decrypt_key = calculate_dynamic_key(message);
                decrypt(message, decrypt_key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}