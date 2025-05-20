//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 32

// Function to convert a string to lowercase
void str_to_lower(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to convert a string to uppercase
void str_to_upper(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to calculate the hash of a given string
char* calculate_hash(char* input) {
    char* hash = malloc(HASH_LENGTH + 1);
    memset(hash, 0, HASH_LENGTH + 1);

    int i = 0;
    while (input[i]!= '\0') {
        hash[i % HASH_LENGTH] ^= input[i];
        i++;
    }

    return hash;
}

int main() {
    char* input = "Hello, world!";

    // Convert input string to uppercase
    str_to_upper(input);

    // Calculate the hash of the input string
    char* hash = calculate_hash(input);

    // Print the hash
    printf("Hash: %s\n", hash);

    return 0;
}