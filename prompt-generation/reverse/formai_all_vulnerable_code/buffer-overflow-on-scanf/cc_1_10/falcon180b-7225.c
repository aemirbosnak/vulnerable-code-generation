//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 64

// Function to convert a string to lowercase
void str_to_lower(char* str) {
    int i = 0;
    while(str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to hash the input string
void hash_string(char* input, char* output) {
    int i, j;
    char ch;

    // Convert string to lowercase
    str_to_lower(input);

    // Initialize hash value
    for(i=0; i<HASH_SIZE; i++) {
        output[i] = 0;
    }

    // Calculate hash
    for(i=0; input[i]!='\0'; i++) {
        ch = input[i];
        output[i%HASH_SIZE] ^= ch;
    }
}

int main() {
    char input[100], output[HASH_SIZE];

    printf("Enter the input string: ");
    scanf("%s", input);

    // Hash the input string
    hash_string(input, output);

    // Print the hash value
    printf("Hash value: ");
    for(int i=0; i<HASH_SIZE; i++) {
        printf("%02X", output[i]);
    }
    printf("\n");

    return 0;
}