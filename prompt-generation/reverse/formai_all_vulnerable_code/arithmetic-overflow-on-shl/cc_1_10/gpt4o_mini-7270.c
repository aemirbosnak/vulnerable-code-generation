//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define HASH_SIZE 32

// Function to create a cryptographic hash of the input string
void createHash(const char *input, char *output) {
    uint32_t hash = 0;
    uint32_t temp = 0;

    // Process each character in the input string
    for (size_t i = 0; i < strlen(input); i++) {
        hash ^= (input[i] << (i % 32)); // Bitwise XOR and left shift
        temp = (hash * 31) + input[i];  // Multiplying by a prime number
        hash = temp ^ (temp >> 16);      // Mixing with the higher bits
    }

    // Convert the hash integer to a hexadecimal string representation
    snprintf(output, HASH_SIZE, "%08x", hash);
}

// Function that performs basic statistical analysis on the input string
void statisticalAnalysis(const char *input) {
    int frequency[256] = {0};
    size_t length = strlen(input);

    // Calculate frequency of each character
    for (size_t i = 0; i < length; i++) {
        frequency[(unsigned char)input[i]]++;
    }

    printf("Statistical Analysis:\n");
    printf("Character Frequencies:\n");

    // Display the frequency of each character
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("Character '%c' (ASCII %d): %d\n", i, i, frequency[i]);
        }
    }

    // Calculate and display some basic statistics
    float mean = length / 256.0;
    printf("Mean frequency: %.2f\n", mean);
}

// Main function
int main() {
    const char *text = "This is a sample string for hashing. Let's create a hash value!";
    char hashOutput[HASH_SIZE];

    // Perform statistical analysis on the input string
    statisticalAnalysis(text);

    // Create a hash of the input string
    createHash(text, hashOutput);

    // Output the created hash
    printf("\nGenerated Hash: %s\n", hashOutput);

    return 0;
}