//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Simple Caesar cipher encryption
        output[i] = input[i] + key;
    }
    output[i] = '\0'; // Null-terminate the encrypted string
}

void decrypt(const char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Simple Caesar cipher decryption
        output[i] = input[i] - key;
    }
    output[i] = '\0'; // Null-terminate the decrypted string
}

void generate_key(int *key) {
    *key = rand() % 26; // Generate a simple key in the range of 0-25
}

void display_menu() {
    printf("Simple Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char message[256];
    char encrypted_message[256];
    char decrypted_message[256];
    int key;
    int choice;

    srand(time(0)); // Seed the random number generator

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
        case 1:
            printf("Enter the message to encrypt: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Strip newline character

            generate_key(&key);
            encrypt(message, encrypted_message, key);
            printf("Encrypted message: %s\n", encrypted_message);
            printf("Encryption key used: %d\n", key);
            break;

        case 2:
            printf("Enter the message to decrypt: ");
            fgets(encrypted_message, sizeof(encrypted_message), stdin);
            encrypted_message[strcspn(encrypted_message, "\n")] = 0; // Strip newline character

            printf("Enter the key used for encryption: ");
            scanf("%d", &key);
            getchar(); // Consume newline character after key input

            decrypt(encrypted_message, decrypted_message, key);
            printf("Decrypted message: %s\n", decrypted_message);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 3);

    return 0;
}