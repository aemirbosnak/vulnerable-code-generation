//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 64

/*
 * A simple hash function that converts a string into a fixed-length
 * hash value. This is not a secure hash function and should not be
 * used for cryptographic purposes.
 */
char* hash(const char* input) {
    unsigned char hash[HASH_LENGTH];
    size_t i, j;
    char* result = malloc(HASH_LENGTH * 2 + 1); // Allocate memory for the hash string, plus a null terminator

    if (result == NULL) {
        printf("Error: Could not allocate memory for hash.\n");
        exit(1);
    }

    memset(hash, 0, HASH_LENGTH); // Initialize the hash to all zeros

    // Convert the input string to lowercase
    char* lowercase_input = malloc(strlen(input) + 1);
    if (lowercase_input == NULL) {
        printf("Error: Could not allocate memory for lowercase input.\n");
        exit(1);
    }

    strcpy(lowercase_input, input);
    for (i = 0; i < strlen(lowercase_input); i++) {
        lowercase_input[i] = tolower(lowercase_input[i]);
    }

    // Calculate the hash value
    for (i = 0; i < strlen(lowercase_input); i++) {
        hash[i % HASH_LENGTH] ^= lowercase_input[i];
    }

    // Convert the hash to a string
    for (i = 0; i < HASH_LENGTH; i++) {
        sprintf(&result[i * 2], "%02x", hash[i]);
    }

    free(lowercase_input);
    return result;
}

int main() {
    char* input;
    char* hash_value;

    printf("Enter a string to hash: ");
    if (scanf("%s", input)!= 1) {
        printf("Error: Invalid input.\n");
        exit(1);
    }

    hash_value = hash(input);
    printf("Hash value: %s\n", hash_value);

    free(hash_value);
    return 0;
}