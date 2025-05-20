//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void print_hex(const unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

void handle_errors(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void encrypt(const unsigned char *key, const unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, 128, &encryptKey) < 0) {
        handle_errors("Failed to set encryption key.");
    }
    AES_encrypt(plaintext, ciphertext, &encryptKey);
}

void decrypt(const unsigned char *key, const unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, 128, &decryptKey) < 0) {
        handle_errors("Failed to set decryption key.");
    }
    AES_decrypt(ciphertext, plaintext, &decryptKey);
}

void generate_random_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_BLOCK_SIZE)) {
        handle_errors("Failed to generate random key.");
    }
}

void display_menu() {
    printf("=== Cyberpunk Encryption Terminal ===\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("0. Exit\n");
    printf("=====================================\n");
    printf("Choose an option: ");
}

int main() {
    unsigned char key[AES_BLOCK_SIZE];
    generate_random_key(key);

    unsigned char plaintext[AES_BLOCK_SIZE] = "HACK THE SYSTEM"; // Sample message
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE];

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: {
                printf("Encrypting...\n");
                encrypt(key, plaintext, ciphertext);
                printf("Ciphertext: ");
                print_hex(ciphertext, AES_BLOCK_SIZE);
                break;
            }
            case 2: {
                printf("Decrypting...\n");
                decrypt(key, ciphertext, decryptedtext);
                printf("Decrypted text: %s\n", decryptedtext);
                break;
            }
            case 0: {
                printf("Exiting... Disconnecting from the Net...\n");
                return 0;
            }
            default: {
                printf("Invalid option. Try again.\n");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}