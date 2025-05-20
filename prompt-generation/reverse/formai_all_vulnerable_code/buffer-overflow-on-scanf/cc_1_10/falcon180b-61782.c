//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32
#define MAX_INPUT_SIZE 4096

void hash_string(char* input, char* output) {
    int i, j;
    unsigned char hash[HASH_SIZE];
    unsigned char input_hash[MAX_INPUT_SIZE];
    unsigned char final_hash[HASH_SIZE];

    if (strlen(input) > MAX_INPUT_SIZE) {
        printf("Input string is too long.\n");
        return;
    }

    for (i = 0; i < strlen(input); i++) {
        input_hash[i] = input[i];
    }

    for (i = 0; i < strlen(input); i++) {
        hash[i] = input_hash[i] ^ (i + 1);
    }

    for (i = 0; i < strlen(input); i++) {
        final_hash[i] = hash[i] ^ (i + 2);
    }

    for (i = 0; i < HASH_SIZE; i++) {
        output[i] = final_hash[i];
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[HASH_SIZE];

    printf("Enter a string to hash: ");
    scanf("%s", input);

    hash_string(input, output);

    printf("Hashed string: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02X", (unsigned int)output[i]);
    }

    return 0;
}