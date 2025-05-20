//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer() {
    while (getchar() != '\n');
}

void xor_encrypt_decrypt(char *input, const char *key) {
    size_t key_len = strlen(key);
    for (size_t i = 0; i < strlen(input); i++) {
        input[i] ^= key[i % key_len];
    }
}

void print_menu() {
    printf("Cryptography Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char message[256];
    char key[256];
    int option;

    while (1) {
        print_menu();
        scanf("%d", &option);
        clear_buffer(); // Clear input buffer to avoid getline issues

        switch (option) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the encryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline character

                xor_encrypt_decrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the decryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline character

                xor_encrypt_decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}