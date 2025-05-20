//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERS 10
#define MAX_INPUT_LENGTH 256

void compute_hash(const char *input, unsigned char *output) {
    SHA256((unsigned char*)input, strlen(input), output);
}

void print_hash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    int num_users;
    char usernames[MAX_USERS][50];
    char inputs[MAX_USERS][MAX_INPUT_LENGTH];
    unsigned char hashes[MAX_USERS][SHA256_DIGEST_LENGTH];

    printf("Enter the number of users (max %d): ", MAX_USERS);
    scanf("%d", &num_users);

    if (num_users <= 0 || num_users > MAX_USERS) {
        printf("Number of users must be between 1 and %d.\n", MAX_USERS);
        return 1;
    }

    // Clear the input buffer
    while (getchar() != '\n');

    for (int i = 0; i < num_users; i++) {
        printf("Enter username for user %d: ", i + 1);
        fgets(usernames[i], sizeof(usernames[i]), stdin);
        usernames[i][strcspn(usernames[i], "\n")] = '\0'; // Remove newline

        printf("Enter input data for %s: ", usernames[i]);
        fgets(inputs[i], sizeof(inputs[i]), stdin);
        inputs[i][strcspn(inputs[i], "\n")] = '\0'; // Remove newline

        // Compute the hash for the input data
        compute_hash(inputs[i], hashes[i]);
    }

    printf("\nUser Data Hashes:\n");
    for (int i = 0; i < num_users; i++) {
        printf("Username: %s -> Hash: ", usernames[i]);
        print_hash(hashes[i]);
    }

    return 0;
}