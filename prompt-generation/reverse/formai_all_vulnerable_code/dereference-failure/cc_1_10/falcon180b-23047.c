//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

// Function to generate a hash from a string
char* generateHash(char* input) {
    char* hash = malloc(HASH_SIZE + 1);
    memset(hash, 0, HASH_SIZE + 1);

    toLowerCase(input);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        hash[i % HASH_SIZE] ^= input[i];
    }

    return hash;
}

// Function to check if two hashes are equal
int compareHashes(char* hash1, char* hash2) {
    int len = strlen(hash1);
    for (int i = 0; i < len; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* input = "Hello, world!";
    char* hash = generateHash(input);

    printf("Input: %s\n", input);
    printf("Hash: %s\n", hash);

    char* input2 = "Hello, world!";
    char* hash2 = generateHash(input2);

    if (compareHashes(hash, hash2)) {
        printf("Hashes match!\n");
    } else {
        printf("Hashes do not match.\n");
    }

    free(hash);
    free(hash2);

    return 0;
}