//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 1024

// Function to calculate the SHA-256 hash of a string
unsigned char* sha256(const char *str) {
    // Allocate memory for the hash
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);

    // Calculate the hash
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, str, strlen(str));
    SHA256_Final(hash, &sha256_ctx);

    // Return the hash
    return hash;
}

// Function to convert a byte array to a hexadecimal string
char *byte_array_to_hex_string(const unsigned char *bytes, size_t length) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(length * 2 + 1);

    // Convert the bytes to a hexadecimal string
    for (size_t i = 0; i < length; i++) {
        sprintf(&hex_string[i * 2], "%02x", bytes[i]);
    }

    // Return the hexadecimal string
    return hex_string;
}

// Function to print the hash of a string
void print_hash(const char *str) {
    // Calculate the hash
    unsigned char *hash = sha256(str);

    // Convert the hash to a hexadecimal string
    char *hex_string = byte_array_to_hex_string(hash, SHA256_DIGEST_LENGTH);

    // Print the hexadecimal string
    printf("The SHA-256 hash of '%s' is: %s\n", str, hex_string);

    // Free the memory allocated for the hash and the hexadecimal string
    free(hash);
    free(hex_string);
}

// Main function
int main() {
    // Get the input string from the user
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string to hash: ");
    scanf("%s", input_string);

    // Print the hash of the input string
    print_hash(input_string);

    return 0;
}