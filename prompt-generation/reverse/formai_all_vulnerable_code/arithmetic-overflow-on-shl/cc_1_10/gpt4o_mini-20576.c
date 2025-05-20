//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32 // Size for SHA-256 hash
#define BLOCK_SIZE 64 // Size of each block (in bytes) for SHA-256

// SHA-256 constants
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
    0x19b4b6a8, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Right Rotate function
uint32_t right_rotate(uint32_t value, uint32_t amount) {
    return (value >> amount) | (value << (32 - amount));
}

// SHA-256 functions
uint32_t sha256_bsig0(uint32_t x) {
    return right_rotate(x, 7) ^ right_rotate(x, 18) ^ (x >> 3);
}

uint32_t sha256_bsig1(uint32_t x) {
    return right_rotate(x, 17) ^ right_rotate(x, 19) ^ (x >> 10);
}

uint32_t sha256_ssig0(uint32_t x) {
    return right_rotate(x, 2) ^ right_rotate(x, 13) ^ right_rotate(x, 22);
}

uint32_t sha256_ssig1(uint32_t x) {
    return right_rotate(x, 6) ^ right_rotate(x, 11) ^ right_rotate(x, 25);
}

// SHA-256 main function
void sha256(const uint8_t *data, size_t len, uint8_t *digest) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint64_t bit_length = len * 8;
    size_t total_len = len + 1 + (BLOCK_SIZE - 1) - (len + 1) % BLOCK_SIZE + 8; 
    uint8_t *buffer = (uint8_t *)calloc(total_len, sizeof(uint8_t));

    memcpy(buffer, data, len);
    buffer[len] = 0x80; // Append the bit '1' to the message

    // Append length
    memcpy(buffer + total_len - 8, &bit_length, sizeof(bit_length));

    for (size_t i = 0; i < total_len; i += BLOCK_SIZE) {
        uint32_t w[64] = {0};
        for (size_t j = 0; j < 16; j++) {
            w[j] = (buffer[i + j * 4] << 24) | (buffer[i + j * 4 + 1] << 16) |
                   (buffer[i + j * 4 + 2] << 8) | (buffer[i + j * 4 + 3]);
        }

        for (size_t j = 16; j < 64; j++) {
            w[j] = sha256_bsig1(w[j - 2]) + w[j - 7] + sha256_bsig0(w[j - 15]) + w[j - 16];
        }

        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h0 = h[7];

        for (size_t j = 0; j < 64; j++) {
            uint32_t t1 = h0 + sha256_ssig1(e) + ((e & f) ^ (~e & g)) + k[j] + w[j];
            uint32_t t2 = sha256_ssig0(a) + ((a & b) ^ (a & c) ^ (b & c));
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

    for (size_t i = 0; i < 8; i++) {
        digest[i * 4] = (h[i] >> 24) & 0xff;
        digest[i * 4 + 1] = (h[i] >> 16) & 0xff;
        digest[i * 4 + 2] = (h[i] >> 8) & 0xff;
        digest[i * 4 + 3] = h[i] & 0xff;
    }
    free(buffer);
}

// Main function to test the SHA-256
int main() {
    const char *input = "Hello, World!";
    uint8_t output[HASH_SIZE];

    sha256((const uint8_t *)input, strlen(input), output);

    printf("SHA-256 hash of '%s': ", input);
    for (size_t i = 0; i < HASH_SIZE; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}