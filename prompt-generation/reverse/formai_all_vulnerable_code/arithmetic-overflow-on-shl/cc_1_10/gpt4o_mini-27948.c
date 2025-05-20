//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32 // Size of the hash in bytes (256 bits)
#define BUFFER_SIZE 1024 // Size of the buffer for input data

// Function prototypes
void compute_hash(const char *input, uint8_t output[HASH_SIZE]);
void print_hash(uint8_t hash[HASH_SIZE]);
void to_hex(uint8_t byte, char *output);
void free_memory(char *ptr);

// A simple implementation of the SHA-256 hash algorithm
void compute_hash(const char *input, uint8_t output[HASH_SIZE]) {
    // Initialize the hash values (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..313)
    uint32_t k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19b4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x7ca5a022, 0x8c1f9b88,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    size_t len = strlen(input);
    uint8_t *msg = malloc(len + 128);
    if (!msg) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Padding the input
    memcpy(msg, input, len);
    msg[len] = 0x80; // Append a single '1' bit
    memset(msg + len + 1, 0, ((len + 9) % 64)); // Append '0' bits
    uint64_t bit_length = len * 8;
    memcpy(msg + (len + 9) / 8, &bit_length, 8); // Append length in bits

    // Initialize hash values
    uint32_t h[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Process each 512-bit chunk (64 bytes)
    for (size_t i = 0; i < len / 64 + 1; ++i) {
        uint32_t w[64] = {0};
        for (size_t j = 0; j < 16; ++j) {
            if (j + i * 16 < len / 64 + 1) {
                w[j] = (msg[i * 64 + j * 4] << 24) |
                        (msg[i * 64 + j * 4 + 1] << 16) |
                        (msg[i * 64 + j * 4 + 2] << 8) |
                        (msg[i * 64 + j * 4 + 3]);
            }
        }

        for (size_t j = 16; j < 64; ++j) {
            w[j] = w[j - 16] + ( (w[j - 15] >> 7) ^ (w[j - 15] >> 18) ^ (w[j - 15] >> 3) ) + w[j - 7] +
                               ( (w[j - 2] >> 17) ^ (w[j - 2] >> 19) ^ (w[j - 2] >> 10) );
        }

        // Initialize working variables to current hash value
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h1 = h[7];

        // Compression function main loop
        for (size_t j = 0; j < 64; ++j) {
            uint32_t t1 = h1 + ( (e >> 6) ^ (e >> 11) ^ (e >> 25) ) +
                            ( e & f ) + k[j] + w[j];
            uint32_t t2 = ( (a >> 2) ^ (a >> 13) ^ (a >> 22) ) +
                          ( a & b ) + ( a & c ) + ( b & c );

            h1 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Add the compressed chunk to the current hash value
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h1;
    }

    // Copy the final hash value to the output
    for (int i = 0; i < 8; ++i) {
        output[i * 4] = (h[i] >> 24) & 0xff;
        output[i * 4 + 1] = (h[i] >> 16) & 0xff;
        output[i * 4 + 2] = (h[i] >> 8) & 0xff;
        output[i * 4 + 3] = h[i] & 0xff;
    }

    free_memory(msg);
}

// Convert a byte to hex representation
void to_hex(uint8_t byte, char *output) {
    const char hex_chars[] = "0123456789abcdef";
    output[0] = hex_chars[(byte >> 4) & 0x0f];
    output[1] = hex_chars[byte & 0x0f];
}

// Print the hash in hex format
void print_hash(uint8_t hash[HASH_SIZE]) {
    char hex_output[HASH_SIZE * 2 + 1];
    for (int i = 0; i < HASH_SIZE; ++i) {
        to_hex(hash[i], &hex_output[i * 2]);
    }
    hex_output[HASH_SIZE * 2] = '\0'; // Null-terminate the string
    printf("Hash: %s\n", hex_output);
}

// Memory free function with error check
void free_memory(char *ptr) {
    if (ptr) {
        free(ptr);
    }
}

int main() {
    // Get user input for hashing
    char input[BUFFER_SIZE];
    printf("Enter string to hash (max %d characters): ", BUFFER_SIZE - 1);
    fgets(input, BUFFER_SIZE, stdin);

    // Remove newline character if present
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }

    // Compute the SHA-256 hash
    uint8_t hash[HASH_SIZE];
    compute_hash(input, hash);
    
    // Print the computed hash
    print_hash(hash);

    return 0;
}