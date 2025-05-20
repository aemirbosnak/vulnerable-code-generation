//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>

// Function to compute SHA-256 hash of a given input
void compute_sha256(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
    SHA256((unsigned char *)input, strlen(input), output);
}

// Function to print the SHA-256 output in hex format
void print_sha256(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to dynamically read input from the user
char* read_input() {
    size_t size = 256;  // Initial size of the buffer
    char *buffer = (char *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the string to be hashed: ");
    getline(&buffer, &size, stdin);  // Read input with dynamic allocation
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character if present
    return buffer;
}

// A simple menu-driven interface to compute SHA-256 hash
void show_menu() {
    printf("---- SHA-256 Hash Generator ----\n");
    printf("1. Compute hash\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

int main() {
    char *input = NULL;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    int choice;

    while (1) {
        show_menu();
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear newline character from buffer

        if (choice == 1) {
            input = read_input();  // Dynamically read user input
            compute_sha256(input, hash);  // Compute hash
            printf("SHA-256 Hash: ");
            print_sha256(hash);  // Print hash
            free(input);  // Free dynamically allocated memory
        } else if (choice == 2) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}