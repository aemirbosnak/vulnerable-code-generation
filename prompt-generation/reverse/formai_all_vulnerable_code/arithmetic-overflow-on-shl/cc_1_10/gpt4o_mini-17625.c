//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32  // Size of the hash in bytes (256 bits)
#define BLOCK_SIZE 64 // Block size for the SHA-256 algorithm

// Function prototypes
void sha256(const uint8_t *data, size_t len, uint8_t *output);
void sha256_transform(uint32_t state[8], const uint8_t data[BLOCK_SIZE]);
void process_chunk(uint32_t state[8], const uint8_t chunk[BLOCK_SIZE]);
void pad_message(const uint8_t *data, size_t len, uint8_t **padded_data, size_t *new_length);
void print_hash(const uint8_t *hash);

// SHA-256 utility functions
uint32_t right_rotate(uint32_t value, uint32_t count);
uint32_t sha256_sigma0(uint32_t x);
uint32_t sha256_sigma1(uint32_t x);
uint32_t sha256_delta0(uint32_t x);
uint32_t sha256_delta1(uint32_t x);
uint32_t sha256_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha256_maj(uint32_t x, uint32_t y, uint32_t z);

// Constants for SHA-256
const uint32_t k[64] = {
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
    0x19a4c116, 0x1e376c48, 0x274077a3, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 main function
void sha256(const uint8_t *data, size_t len, uint8_t *output) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint8_t *padded_data = NULL;
    size_t new_length = 0;
    pad_message(data, len, &padded_data, &new_length);

    for (size_t i = 0; i < new_length; i += BLOCK_SIZE) {
        sha256_transform(state, padded_data + i);
    }

    for (int i = 0; i < 8; ++i) {
        output[i * 4] = (state[i] >> 24) & 0xff;
        output[i * 4 + 1] = (state[i] >> 16) & 0xff;
        output[i * 4 + 2] = (state[i] >> 8) & 0xff;
        output[i * 4 + 3] = state[i] & 0xff;
    }

    free(padded_data);
}

// SHA-256 transformation on a single block
void sha256_transform(uint32_t state[8], const uint8_t data[BLOCK_SIZE]) {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | 
               (data[i * 4 + 2] << 8) | data[i * 4 + 3];
    }

    for (int i = 16; i < 64; ++i) {
        w[i] = sha256_delta1(w[i - 2]) + w[i - 7] + sha256_delta0(w[i - 15]) + w[i - 16];
    }

    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];

    for (int i = 0; i < 64; ++i) {
        uint32_t t1 = h + sha256_ch(e, f, g) + k[i] + w[i];
        uint32_t t2 = sha256_maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

// A simple message padding scheme to ensure the message length is congruent to 448 mod 512
void pad_message(const uint8_t *data, size_t len, uint8_t **padded_data, size_t *new_length) {
    size_t original_bit_len = len * 8;
    size_t padding_size = (448 - (original_bit_len + 8) % 512 + 512) % 512;
    size_t total_length = len + 1 + (padding_size / 8) + 8; // 1-byte '1' bit, padding, 8-byte length

    *padded_data = (uint8_t *)calloc(total_length, sizeof(uint8_t));
    memcpy(*padded_data, data, len);
    
    (*padded_data)[len] = 0x80; // Append '1' bit
    for (int i = 0; i < 8; ++i) {
        (*padded_data)[len + 1 + (padding_size / 8) + i] = (original_bit_len >> (56 - i * 8)) & 0xff;
    }

    *new_length = total_length;
}

// Print the hash in hexadecimal format
void print_hash(const uint8_t *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// SHA-256 helper functions
uint32_t right_rotate(uint32_t value, uint32_t count) {
    return (value >> count) | (value << (32 - count));
}

uint32_t sha256_sigma0(uint32_t x) {
    return right_rotate(x, 7) ^ right_rotate(x, 18) ^ (x >> 3);
}

uint32_t sha256_sigma1(uint32_t x) {
    return right_rotate(x, 17) ^ right_rotate(x, 19) ^ (x >> 10);
}

uint32_t sha256_delta0(uint32_t x) {
    return right_rotate(x, 2) ^ right_rotate(x, 13) ^ right_rotate(x, 22);
}

uint32_t sha256_delta1(uint32_t x) {
    return right_rotate(x, 6) ^ right_rotate(x, 11) ^ right_rotate(x, 25);
}

uint32_t sha256_ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t sha256_maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

// Main function to test the SHA-256 implementation
int main() {
    const char *message = "Hello, World!";
    uint8_t hash[HASH_SIZE] = {0};

    printf("Input message: %s\n", message);
    sha256((const uint8_t *)message, strlen(message), hash);
    printf("SHA-256 hash: ");
    print_hash(hash);

    return 0;
}