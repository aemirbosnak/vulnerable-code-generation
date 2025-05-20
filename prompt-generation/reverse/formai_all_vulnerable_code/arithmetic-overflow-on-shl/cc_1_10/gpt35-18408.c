//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

// This function generates a random 32-bit integer as a seed.
uint32_t rand32() {
    uint32_t x = rand() & 0xFFFF;
    uint32_t y = rand() & 0xFFFF;
    return (x << 16) | y;
}

// This function initializes the state vector from a given seed.
void init_state(uint32_t *state, uint32_t seed) {
    state[0] = 0x67452301 ^ seed;
    state[1] = 0xEFCDAB89 ^ seed;
    state[2] = 0x98BADCFE ^ seed;
    state[3] = 0x10325476 ^ seed;
}

// This function performs the core hash algorithm.
void hash_block(uint32_t *state, uint32_t *block) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t x[16];

    for (int i = 0; i < 16; i++) {
        x[i] = block[i];
    }

    // Round 1
    for (int i = 0; i < 4; i++) {
        a += ((b & c) | (~b & d)) + x[i] + 0x5A827999;
        a = ROTL(a, 5) + b;
        d = c;
        c = b;
        b = ROTL(b, 30);
    }

    // Round 2
    for (int i = 4; i < 8; i++) {
        a += ((b & c) | (~b & d)) + x[i] + 0x6ED9EBA1;
        a = ROTL(a, 5) + b;
        d = c;
        c = b;
        b = ROTL(b, 30);
    }

    // Round 3
    for (int i = 8; i < 12; i++) {
        a += (b ^ c ^ d) + x[i] + 0x8F1BBCDC;
        a = ROTL(a, 5) + b;
        d = c;
        c = b;
        b = ROTL(b, 30);
    }

    // Round 4
    for (int i = 12; i < 16; i++) {
        a += (c ^ (b | ~d)) + x[i] + 0xCA62C1D6;
        a = ROTL(a, 5) + b;
        d = c;
        c = b;
        b = ROTL(b, 30);
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

// This function pads the input message to a multiple of 512 bits.
// Returns the number of blocks in the padded message.
int pad_message(uint32_t *message, int length) {
    int initial_length = length;
    int blocks = ((length + 8) >> 6) + 1;
    int padded_length = blocks << 6;

    message[length >> 2] |= 0x80 << (24 - (length & 3) * 8);
    message[padded_length >> 2] = length * 8;

    return blocks;
}

// This function computes the hash of the input message.
void sha1(uint32_t *message, int length, uint32_t *hash) {
    uint32_t state[4];
    uint32_t block[16];
    int blocks;

    // Initialize the state vector and constants.
    init_state(state, rand32());

    // Pad the message.
    blocks = pad_message(message, length);

    // Process each block.
    for (int i = 0; i < blocks; i++) {
        int offset = i << 6;
        for (int j = 0; j < 16; j++) {
            block[j] = message[offset + j];
        }
        hash_block(state, block);
    }

    // Write the final hash value.
    for (int i = 0; i < 4; i++) {
        hash[i] = state[i];
    }
}

int main() {
    uint32_t message[16] = {0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70, 0x71727374, 0x75767778, 0x797A};
    uint32_t hash[4];

    // Compute the hash of the message.
    sha1(message, 28, hash);

    // Print the hash value.
    printf("SHA-1 hash: %08X%08X%08X%08X\n", hash[0], hash[1], hash[2], hash[3]);

    return 0;
}