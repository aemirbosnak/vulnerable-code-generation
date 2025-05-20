//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 64 // Length of the hash

// Function to convert a string to lowercase
void str_to_lower(char* str) {
    int i;
    for(i=0; str[i]!= '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

// Function to calculate the hash of a string
void hash_string(char* str, char* hash) {
    int i, j;
    int len = strlen(str);

    // Convert the string to lowercase
    str_to_lower(str);

    // Initialize the hash
    memset(hash, 0, HASH_LENGTH);

    // Calculate the hash
    for(i=0, j=0; i<len; i++) {
        hash[j] ^= str[i];
        j++;
        if(j == HASH_LENGTH) {
            j = 0;
        }
    }
}

int main() {
    char input[100];
    char hash[HASH_LENGTH];

    // Get input from user
    printf("Enter a string to hash: ");
    scanf("%s", input);

    // Calculate the hash
    hash_string(input, hash);

    // Print the hash
    printf("Hash: ");
    for(int i=0; i<HASH_LENGTH; i++) {
        printf("%02X", hash[i]);
    }
    printf("\n");

    return 0;
}