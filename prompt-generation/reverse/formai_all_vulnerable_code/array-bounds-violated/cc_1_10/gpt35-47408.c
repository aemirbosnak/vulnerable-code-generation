//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_SIZE 4
#define BLOCK_SIZE 64
#define ROUNDS 16
#define KEY_LENGTH 16

// Constants used in the SHA256 algorithm
const unsigned int K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4,
    0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
    0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
    0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116,
    0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
    0xc67178f2
};

// Helper functions
unsigned int rotate_right(unsigned int i, unsigned int n) {
    return (i >> n) | (i << (32 - n));
}

unsigned int ch(unsigned int x, unsigned int y, unsigned int z) {
    return (x & y) ^ (~x & z);
}

unsigned int maj(unsigned int x, unsigned int y, unsigned int z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

unsigned int sigma_0(unsigned int x) {
    return rotate_right(x, 2) ^ rotate_right(x, 13) ^ rotate_right(x, 22);
}

unsigned int sigma_1(unsigned int x) {
    return rotate_right(x, 6) ^ rotate_right(x, 11) ^ rotate_right(x, 25);
}

unsigned int gamma_0(unsigned int x) {
    return rotate_right(x, 7) ^ rotate_right(x, 18) ^ (x >> 3);
}

unsigned int gamma_1(unsigned int x) {
    return rotate_right(x, 17) ^ rotate_right(x, 19) ^ (x >> 10);
}

void sha256(unsigned char *data, size_t length, unsigned int *hash) {
    // Initialize working variables
    unsigned int h[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Pre-processing
    size_t padded_length = length + 1;
    while (padded_length % BLOCK_SIZE != 56) {
        padded_length++;
    }
    unsigned char *padded_data = calloc(padded_length + 8, sizeof(unsigned char));
    memcpy(padded_data, data, length);
    padded_data[length] = 0x80;
    for (size_t i = length + 1; i < padded_length; i++) {
        padded_data[i] = 0x00;
    }
    size_t *length_ptr = (size_t *)(padded_data + padded_length);
    *length_ptr = length * 8;

    // Process message in 512-bit blocks
    for (size_t i = 0; i < padded_length; i += BLOCK_SIZE) {
        unsigned int w[ROUNDS];
        for (int j = 0; j < WORD_SIZE; j++) {
            w[j] = (padded_data[i + (j * 4)] << 24) |
                   (padded_data[i + (j * 4) + 1] << 16) |
                   (padded_data[i + (j * 4) + 2] << 8) |
                   (padded_data[i + (j * 4) + 3]);
        }
        for (int j = WORD_SIZE; j < ROUNDS; j++) {
            w[j] = gamma_1(w[j - 2]) + w[j - 7] + gamma_0(w[j - 15]) + w[j - 16];
        }

        unsigned int a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h0 = h[7];
        for (int j = 0; j < ROUNDS; j++) {
            unsigned int t1 = h0 + sigma_1(e) + ch(e, f, g) + K[j] + w[j];
            unsigned int t2 = sigma_0(a) + maj(a, b, c);
            h0 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
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

    // Convert hash to bytes
    for (int i = 0; i < 8; i++) {
        hash[i] = ((h[i] >> 24) & 0xff) |
                  ((h[i] >> 8) & 0xff00) |
                  ((h[i] << 8) & 0xff0000) |
                  ((h[i] << 24) & 0xff000000);
    }

    // Deallocate memory
    free(padded_data);
}

int main() {
    unsigned char data[] = "Hello, world!";
    unsigned int hash[8];

    sha256(data, strlen(data), hash);

    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }

    return 0;
}