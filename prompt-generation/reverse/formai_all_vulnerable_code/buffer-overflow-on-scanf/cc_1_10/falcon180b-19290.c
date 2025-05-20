//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 32

// Function prototypes
void hash(char* input, char* output);

int main() {
    char input[100];
    char output[HASH_LENGTH];

    // Get user input
    printf("Enter a string to hash: ");
    scanf("%s", input);

    // Hash the input
    hash(input, output);

    // Print the hash
    printf("Hash: %s\n", output);

    return 0;
}

// Hash function
void hash(char* input, char* output) {
    int i, j;
    unsigned int hash = 0;

    // Initialize the hash value to zero
    for (i = 0; i < strlen(input); i++) {
        hash += input[i];
    }

    // Apply the hash function to the input
    for (i = 0; i < strlen(input); i++) {
        hash += (hash << 10) + input[i];
        hash ^= (hash >> 6);
    }

    // Convert the hash value to a string
    for (i = 0; i < HASH_LENGTH; i++) {
        j = hash % 16;
        if (j < 10) {
            output[i] = j + '0';
        } else {
            output[i] = j - 10 + 'A';
        }
        hash /= 16;
    }
    output[HASH_LENGTH - 1] = '\0';
}