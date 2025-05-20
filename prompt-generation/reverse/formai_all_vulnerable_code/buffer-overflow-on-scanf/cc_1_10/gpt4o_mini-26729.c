//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void print_hexadecimal(const unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void hash_input(const char *input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);

    printf("Input: %s\n", input);
    printf("SHA-256 Hash: ");
    print_hexadecimal(hash);
}

void hash_file(const char *filename) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    SHA256_Init(&sha256);
    
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        SHA256_Update(&sha256, buffer, bytesRead);
    }

    SHA256_Final(hash, &sha256);
    fclose(file);

    printf("File: %s\n", filename);
    printf("SHA-256 Hash: ");
    print_hexadecimal(hash);
}

int main() {
    printf("Welcome to the SHA-256 Hashing Program!\n");
    printf("Please choose an option:\n");
    printf("1. Hash a string input\n");
    printf("2. Hash a file\n");
    printf("3. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input

        if (choice == 1) {
            char input[256];
            printf("Enter the string you want to hash: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // Remove the newline character
            hash_input(input);
        } else if (choice == 2) {
            char filename[256];
            printf("Enter the filename to hash: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove the newline character
            hash_file(filename);
        } else if (choice == 3) {
            printf("Exiting the program. Stay secure!\n");
            break;
        } else {
            printf("Invalid choice. Please choose again.\n");
        }
        printf("\n"); // New line for better formatting
    }

    return 0;
}