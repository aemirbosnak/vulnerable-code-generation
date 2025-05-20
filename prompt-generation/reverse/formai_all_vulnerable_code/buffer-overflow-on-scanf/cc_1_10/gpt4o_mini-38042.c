//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

// The apocalypse left behind remnants of ancient tech.
// A desperate group of survivors huddles around a rusted server
// as they attempt to forge a cryptographic hash function to keep 
// their secrets safe from raiders in the wasteland.

#define HASH_SIZE 32
#define BUFFER_SIZE 256

typedef struct {
    uint8_t hash[HASH_SIZE];
} CryptoHash;

// A helper function to print the hash.
void printHash(uint8_t *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// A simple hash function that combines elements of time and data.
void apocalypticHash(const char *input, CryptoHash *output) {
    uint32_t hash = 0;
    time_t t;
    time(&t); // Time is a fleeting currency now.

    for (size_t i = 0; i < strlen(input); i++) {
        // Create a new hash from input bytes mixed with the current time.
        hash = (hash * 31) + (input[i] + (uint32_t)t);
    }

    // Fill the output hash with pseudo-random bytes
    for (int i = 0; i < HASH_SIZE; i++) {
        output->hash[i] = (hash >> (i % 4 * 8)) & 0xFF;
    }
}

// Simple menu to let the survivors generate hashes for their important messages.
void menu() {
    printf("Welcome to the Hash Forge of the Wasteland!\n");
    printf("1. Generate a hash\n");
    printf("2. Exit\n");
}

int main() {
    char input[BUFFER_SIZE];
    CryptoHash hashOutput;
    int choice;

    while(1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline from the buffer

        if (choice == 2) {
            printf("The server will now power down...\n");
            break;
        } else if (choice == 1) {
            printf("Enter your secret message to hash: ");
            fgets(input, BUFFER_SIZE, stdin);
            // Remove newline character from fgets input
            input[strcspn(input, "\n")] = 0;

            apocalypticHash(input, &hashOutput);
            printf("Your hash:\n");
            printHash(hashOutput.hash);
        } else {
            printf("Lost in the wasteland of choices...\n");
        }
    }

    return 0;
}