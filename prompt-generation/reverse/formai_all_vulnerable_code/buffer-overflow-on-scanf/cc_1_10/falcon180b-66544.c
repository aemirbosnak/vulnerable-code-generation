//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define HASH_LENGTH 64

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to generate a hash
char* generateHash(char* input) {
    char* hash = malloc(HASH_LENGTH + 1);
    if (!hash) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    srand(time(NULL));
    int i = 0;
    while (i < HASH_LENGTH) {
        char randChar = rand() % 26 + 'a';
        hash[i] = randChar;
        i++;
    }

    hash[HASH_LENGTH] = '\0';

    return hash;
}

int main() {
    char input[100];

    printf("Enter a string to hash: ");
    scanf("%s", input);

    toLowerCase(input);

    char* hash = generateHash(input);

    printf("Hash: %s\n", hash);

    free(hash);

    return 0;
}