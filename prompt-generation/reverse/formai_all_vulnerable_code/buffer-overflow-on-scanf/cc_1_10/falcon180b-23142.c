//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define HASH_LENGTH 64
#define SALT_LENGTH 32

// Function to generate a random salt
void generate_salt(unsigned char *salt) {
    unsigned int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = rand() % 256;
    }
}

// Function to calculate the SHA-256 hash of a string with a given salt
void sha256_hash(const char *input_string, const unsigned char *salt, unsigned char *hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, salt, SALT_LENGTH);
    SHA256_Update(&ctx, input_string, strlen(input_string));
    SHA256_Final(hash, &ctx);
}

// Function to compare two hashes
int compare_hashes(const unsigned char *hash1, const unsigned char *hash2) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Generate a random salt
    unsigned char salt[SALT_LENGTH];
    generate_salt(salt);

    // Prompt the user for a password
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the hash of the password with the salt
    unsigned char hash[HASH_LENGTH];
    sha256_hash(password, salt, hash);

    // Print the hash and salt
    printf("Hash: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    printf("Salt: ");
    for (int i = 0; i < SALT_LENGTH; i++) {
        printf("%02x", salt[i]);
    }
    printf("\n");

    // Verify the password
    char verify_password[100];
    printf("Enter a password to verify: ");
    scanf("%s", verify_password);

    unsigned char verify_hash[HASH_LENGTH];
    sha256_hash(verify_password, salt, verify_hash);

    if (compare_hashes(hash, verify_hash)) {
        printf("Passwords match.\n");
    } else {
        printf("Passwords do not match.\n");
    }

    return 0;
}