//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024

void generate_sha256_hash(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
    SHA256((unsigned char*)input, strlen(input), output);
}

void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void encrypt_decrypt_xor(const char *input, const char *key, char *output) {
    size_t key_length = strlen(key);
    for(size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void menu() {
    printf("1. Generate SHA-256 Hash\n");
    printf("2. XOR Encrypt/Decrypt\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char output[BUFFER_SIZE];
    int choice;

    while(1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch(choice) {
            case 1:
                printf("Enter string to hash: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                generate_sha256_hash(input, hash);
                printf("SHA-256 Hash: ");
                print_hash(hash);
                break;

            case 2:
                printf("Enter string to encrypt/decrypt: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                printf("Enter key: ");
                fgets(key, BUFFER_SIZE, stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline
                
                encrypt_decrypt_xor(input, key, output);
                printf("Output: %s\n", output);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}