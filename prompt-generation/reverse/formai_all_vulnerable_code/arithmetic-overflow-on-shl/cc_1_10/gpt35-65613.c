//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

// ROTL (rotate left)
#define ROTL(x,y) ((x << y) | (x >> (32 - y)))

// Ch
#define CH(x,y,z) ((x & y) ^ (~x & z))

// Majority
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))

// Sigma0
#define S0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))

// Sigma1
#define S1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))

// sigma0
#define s0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3))

// sigma1
#define s1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10))

// SHA-256 constant words
const uint32_t K[64] = {
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
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 initial hash values
const uint32_t H[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// SHA-256 message schedule
void sha256_msg_schedule(uint32_t *x)
{
    for (int i = 16; i < 64; ++i)
        x[i] = s1(x[i-2]) + x[i-7] + s0(x[i-15]) + x[i-16];
}

// SHA-256 compression function
void sha256_compress(uint32_t *x, uint32_t *h)
{
    uint32_t a, b, c, d, e, f, g, h0, h1, t1, t2;

    // Initialize hash values
    h0 = h[0];
    h1 = h[1];
    uint32_t h2 = h[2];
    uint32_t h3 = h[3];
    uint32_t h4 = h[4];
    uint32_t h5 = h[5];
    uint32_t h6 = h[6];
    uint32_t h7 = h[7];

    // Compute temporary values
    for (int i = 0; i < 64; ++i) {
        t1 = h7 + S1(h4) + CH(h4,h5,h6) + K[i] + x[i];
        t2 = S0(h0) + MAJ(h0,h1,h2);

        h7 = h6;
        h6 = h5;
        h5 = h4;
        h4 = h3 + t1;
        h3 = h2;
        h2 = h1;
        h1 = h0;
        h0 = t1 + t2;
    }

    // Update hash values
    h[0] += h0;
    h[1] += h1;
    h[2] += h2;
    h[3] += h3;
    h[4] += h4;
    h[5] += h5;
    h[6] += h6;
    h[7] += h7;
}

// SHA-256 hash function
char* sha256(uint8_t *msg, size_t msg_len)
{
    // Message padding
    size_t new_len = msg_len * 8 + 1;
    while (new_len % 512 != 448)
        ++new_len;
    new_len /= 8;

    uint8_t *msg_padded = calloc(new_len + 64, sizeof(uint8_t));
    memcpy(msg_padded, msg, msg_len);
    msg_padded[msg_len] = 0x80;
    uint32_t bit_len = msg_len * 8;
    memcpy(msg_padded + new_len, &bit_len, 4);

    // Initialize hash values
    uint32_t h[8];
    memcpy(h, H, sizeof(H));

    // Process message in 512-bit blocks
    for (size_t i = 0; i < new_len; i += 64) {
        uint32_t x[64];
        for (int j = 0; j < 16; ++j)
            x[j] = (msg_padded[i+j*4] << 24) | (msg_padded[i+j*4+1] << 16) |
                   (msg_padded[i+j*4+2] << 8) | (msg_padded[i+j*4+3]);
        sha256_msg_schedule(x);
        sha256_compress(x, h);
    }

    // Convert hash values to hexadecimal string
    char *hash = calloc(65, sizeof(char));
    snprintf(hash, 65, "%08x%08x%08x%08x%08x%08x%08x%08x", h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7]);

    free(msg_padded);
    return hash;
}

int main() {
    char str[] = "hello world";
    char *hash = sha256(str, 11);
    printf("SHA-256 Hash: %s\n", hash);
    free(hash);
    return 0;
}