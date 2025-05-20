//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 32

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to generate a hash from a string
char* generateHash(char* input) {
    char* hash = malloc(HASH_LENGTH + 1);
    if (hash == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    toLowerCase(input);

    time_t now = time(NULL);
    srand(now);

    int i = 0;
    while (i < HASH_LENGTH) {
        int random = rand() % 26 + 97;
        hash[i] = random;
        i++;
    }

    hash[HASH_LENGTH] = '\0';

    return hash;
}

// Function to compare two hashes
int compareHashes(char* hash1, char* hash2) {
    int i = 0;
    while (i < HASH_LENGTH) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    char input[100];
    printf("Enter a string to generate a hash: ");
    scanf("%s", input);

    char* hash = generateHash(input);

    if (hash == NULL) {
        return 1;
    }

    printf("Generated hash: %s\n", hash);

    char* input2 = "test";
    char* hash2 = generateHash(input2);

    if (compareHashes(hash, hash2)) {
        printf("Hashes match.\n");
    } else {
        printf("Hashes do not match.\n");
    }

    free(hash);
    free(hash2);

    return 0;
}