//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <openssl/sha.h>
#include <stdio.h>

// Define the maximum length of the input string
#define MAX_INPUT_LEN 1024

// Define the length of the SHA-256 hash in bytes
#define SHA256_DIGEST_LEN 32

// This function calculates the SHA-256 hash of an input string and stores the result in a buffer.
void calculate_sha256(char *input, unsigned char *hash) {
    // Create a SHA-256 context
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Update the context with the input string
    SHA256_Update(&ctx, input, strlen(input));

    // Finalize the context and get the hash
    SHA256_Final(hash, &ctx);
}

// This function prints the SHA-256 hash of an input string.
void print_sha256(char *input) {
    // Allocate a buffer for the hash
    unsigned char hash[SHA256_DIGEST_LEN];

    // Calculate the SHA-256 hash of the input string
    calculate_sha256(input, hash);

    // Print the hash
    for (int i = 0; i < SHA256_DIGEST_LEN; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");
}

// This function demonstrates how to use the calculate_sha256() and print_sha256() functions.
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_LEN];
    printf("Enter a string: ");
    scanf("%s", input);

    // Print the SHA-256 hash of the input string
    printf("SHA-256 hash: ");
    print_sha256(input);

    return 0;
}