//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 32

void hash(char* input, char* output) {
    int i, j;
    char temp[HASH_SIZE];

    // Convert input to lowercase
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
    }

    // Initialize hash variable
    for (i = 0; i < HASH_SIZE; i++) {
        output[i] = 0;
    }

    // Calculate hash value
    for (i = 0; i < strlen(input); i++) {
        output[i % HASH_SIZE] ^= input[i];
    }

    // Convert hash value to hexadecimal string
    for (i = 0; i < HASH_SIZE; i++) {
        sprintf(temp + (2 * i), "%02x", output[i]);
    }

    // Copy hash value to output
    for (i = 0; i < HASH_SIZE; i++) {
        output[i] = temp[i];
    }
}

int main() {
    char input[100], output[HASH_SIZE * 2 + 1];

    printf("Enter input string: ");
    scanf("%s", input);

    hash(input, output);

    printf("Hash value: %s\n", output);

    return 0;
}