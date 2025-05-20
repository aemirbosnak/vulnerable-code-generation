//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash function
#define HASH_FUNCTION(data, length, seed) \
    for (int i = 0; i < length; i++) { \
        seed = (31 * seed) ^ data[i]; \
    }

// Define the hash function with salt
#define HASH_FUNCTION_WITH_SALT(data, length, salt, seed) \
    for (int i = 0; i < length; i++) { \
        seed = (31 * seed) ^ data[i] ^ salt[i]; \
    }

// Define the hash function with multiple salts
#define HASH_FUNCTION_WITH_MULTIPLE_SALTS(data, length, salts, seed) \
    for (int i = 0; i < length; i++) { \
        for (int j = 0; j < sizeof(salts); j++) { \
            seed = (31 * seed) ^ data[i] ^ salts[j]; \
        } \
    }

// Define the hash function with configurable parameters
#define HASH_FUNCTION_CONFIG(data, length, config, seed) \
    for (int i = 0; i < length; i++) { \
        seed = (31 * seed) ^ data[i]; \
        seed ^= config.a; \
        seed = (seed << config.b) | (seed >> (32 - config.b)); \
        seed += config.c; \
    }

// Define a struct for configurable parameters
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} hash_config_t;

// Define the main function
int main() {
    // Define the data to be hashed
    char data[] = "Hello, world!";
    int length = strlen(data);

    // Define the seed
    unsigned int seed = 0;

    // Define the salt
    char salt[] = "SALT";

    // Define the multiple salts
    char salts[] = {'S', 'A', 'L', 'T'};

    // Define the configurable parameters
    hash_config_t config = {0xdeadbeef, 0x12345678, 0x87654321};

    // Hash the data with the salt
    HASH_FUNCTION_WITH_SALT(data, length, salt, seed);
    printf("Hash with salt: %08x\n", seed);

    // Hash the data with multiple salts
    HASH_FUNCTION_WITH_MULTIPLE_SALTS(data, length, salts, seed);
    printf("Hash with multiple salts: %08x\n", seed);

    // Hash the data with configurable parameters
    HASH_FUNCTION_CONFIG(data, length, config, seed);
    printf("Hash with configurable parameters: %08x\n", seed);

    return 0;
}