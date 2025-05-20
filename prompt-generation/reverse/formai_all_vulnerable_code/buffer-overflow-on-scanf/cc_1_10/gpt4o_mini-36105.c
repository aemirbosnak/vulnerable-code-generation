//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>

void print_hash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void generate_sha256_hash(const char *input, unsigned char *output_hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(output_hash, &sha256);
}

void read_string(char *buffer, size_t size) {
    printf("Enter a string to hash: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

void display_menu() {
    printf("\n--- SHA256 Hash Generator ---\n");
    printf("1. Generate Hash\n");
    printf("2. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char input_string[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear the buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                read_string(input_string, sizeof(input_string));
                generate_sha256_hash(input_string, hash);
                
                printf("Hash for \"%s\": ", input_string);
                print_hash(hash);
                break;
            case 2:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
        
        while (getchar() != '\n'); // clear the buffer from the newline after scanf
    }

    return 0;
}