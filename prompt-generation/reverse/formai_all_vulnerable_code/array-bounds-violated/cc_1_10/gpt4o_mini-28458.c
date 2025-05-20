//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 constants
#define SHA256_BLOCK_SIZE 32
#define SHA256_ROUNDS 64

// Hash functions
uint32_t K[SHA256_ROUNDS] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
    0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
    0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
    0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
    0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x913f3d5a,
    0x1a0e6c87, 0x2c6ef372, 0x4c6c6067, 0x5b0a6f4f, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3,
    0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138,
};

// Functions for SHA-256
void sha256(const uint8_t *data, size_t len, uint8_t *hash) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint8_t padded[64];
    uint64_t bit_len = len * 8;
    size_t i;

    // Padding
    for (i = 0; i < len; i++) {
        padded[i] = data[i];
    }
    padded[len] = 0x80;

    for (i = len + 1; i < 56; i++) {
        padded[i] = 0x00;
    }

    // Append length
    for (i = 0; i < 8; i++) {
        padded[56 + i] = (bit_len >> (56 - i * 8)) & 0xff;
    }

    // Process in 512-bit chunks
    for (i = 0; i < 64; i += 16) {
        uint32_t w[64] = {0};

        for (size_t j = 0; j < 16; j++) {
            w[j] = (padded[i + j * 4] << 24) | (padded[i + j * 4 + 1] << 16) |
                   (padded[i + j * 4 + 2] << 8) | (padded[i + j * 4 + 3]);
        }
        
        for (size_t j = 16; j < 64; ++j) {
            uint32_t s0 = (w[j - 15] >> 7) ^ (w[j - 15] >> 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = (w[j - 2] >> 17) ^ (w[j - 2] >> 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h0 = h[7];

        // Main loop
        for (size_t j = 0; j < 64; j++) {
            uint32_t S1 = (e >> 6) ^ (e >> 11) ^ (e >> 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h0 + S1 + ch + K[j] + w[j];
            uint32_t S0 = (a >> 2) ^ (a >> 13) ^ (a >> 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h0 = g; 
            g = f; 
            f = e; 
            e = d + temp1; 
            d = c; 
            c = b; 
            b = a; 
            a = temp1 + temp2;
        }

        h[0] += a; 
        h[1] += b; 
        h[2] += c; 
        h[3] += d; 
        h[4] += e; 
        h[5] += f; 
        h[6] += g; 
        h[7] += h0;
    }

    // Produce final hash value
    for (i = 0; i < 8; i++) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }
}

void print_hash(const uint8_t *hash) {
    for (size_t i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    const char *input = "The quick brown fox jumps over the lazy dog";
    size_t input_len = strlen(input);
    
    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256((const uint8_t *)input, input_len, hash);
    
    printf("Input: %s\n", input);
    printf("SHA-256 Hash: ");
    print_hash(hash);

    return 0;
}