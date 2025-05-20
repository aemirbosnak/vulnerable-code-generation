//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 32

void paranoid_hash(const char* input, char* output) {
    unsigned char hash[HASH_LENGTH];
    memset(hash, 0, HASH_LENGTH);

    // Generate a random salt
    unsigned char salt[16];
    if (RAND_bytes(salt, sizeof(salt))!= 1) {
        printf("Error: Failed to generate random salt\n");
        exit(1);
    }

    // Concatenate input and salt
    char* concatenated = malloc(strlen(input) + sizeof(salt));
    if (concatenated == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    strcpy(concatenated, input);
    strcat(concatenated, (char*)salt);

    // Hash the concatenated string
    if (EVP_Digest(concatenated, strlen(concatenated), hash, NULL, EVP_sha256(), NULL)!= 1) {
        printf("Error: Failed to hash input\n");
        exit(1);
    }

    // Convert hash to hexadecimal string
    char hex[HASH_LENGTH * 2 + 1];
    for (int i = 0; i < HASH_LENGTH; i++) {
        sprintf(&hex[i * 2], "%02x", hash[i]);
    }
    hex[HASH_LENGTH * 2] = '\0';

    // Copy hash to output
    strcpy(output, hex);

    free(concatenated);
}

int main() {
    char input[1024];
    char hash[HASH_LENGTH * 2 + 1];

    printf("Enter input to hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    paranoid_hash(input, hash);

    printf("Hash: %s\n", hash);

    return 0;
}