//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 64

// Function to convert a string to lower case
void strtolower(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to generate a hash
void generateHash(char* input, char* output) {
    strtolower(input);
    int len = strlen(input);
    int i = 0;
    for (i = 0; i < len; i++) {
        output[i] = input[i];
    }
    output[i] = '\0';
}

// Function to compare two hashes
int compareHashes(char* hash1, char* hash2) {
    int i = 0;
    while (hash1[i] && hash2[i]) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to generate a random salt
void generateSalt(char* salt) {
    srand(time(NULL));
    int i = 0;
    while (i < HASH_SIZE) {
        salt[i] = rand() % 26 + 'a';
        i++;
    }
    salt[i] = '\0';
}

// Main function
int main() {
    char input[100];
    char hash[HASH_SIZE];
    char salt[HASH_SIZE];

    printf("Enter input string: ");
    scanf("%s", input);

    generateSalt(salt);
    printf("Salt: %s\n", salt);

    generateHash(input, hash);
    printf("Hash: %s\n", hash);

    if (compareHashes(hash, input)) {
        printf("Hashes match\n");
    } else {
        printf("Hashes do not match\n");
    }

    return 0;
}