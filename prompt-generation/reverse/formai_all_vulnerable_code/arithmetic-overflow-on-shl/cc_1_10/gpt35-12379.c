//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIGMA2(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define SIGMA3(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

const uint32_t K[] = {
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

void sha256_transform(uint32_t state[8], const uint8_t block[64]) {
    uint32_t W[64];
    uint32_t i, t1, t2, A, B, C, D, E, F, G, H;

    for (i = 0; i < 16; ++i)
        W[i] = (block[i * 4 + 0] << 24) |
               (block[i * 4 + 1] << 16) |
               (block[i * 4 + 2] << 8) |
               (block[i * 4 + 3]);

    for (i = 16; i < 64; ++i)
        W[i] = SIGMA3(W[i-2]) + W[i-7] + SIGMA2(W[i-15]) + W[i-16];

    A = state[0];
    B = state[1];
    C = state[2];
    D = state[3];
    E = state[4];
    F = state[5];
    G = state[6];
    H = state[7];

    for (i = 0; i < 64; ++i) {
        t1 = H + SIGMA1(E) + CH(E, F, G) + K[i] + W[i];
        t2 = SIGMA0(A) + MAJ(A, B, C);
        H = G;
        G = F;
        F = E;
        E = D + t1;
        D = C;
        C = B;
        B = A;
        A = t1 + t2;
    }

    state[0] += A;
    state[1] += B;
    state[2] += C;
    state[3] += D;
    state[4] += E;
    state[5] += F;
    state[6] += G;
    state[7] += H;
}

void sha256(const uint8_t *message, size_t message_len, uint8_t hash[32]) {
    uint32_t state[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint64_t bitlen = message_len * 8;
    uint8_t block[64];
    uint64_t i;

    while (message_len >= 64) {
        memcpy(block, message, 64);
        sha256_transform(state, block);
        message += 64;
        message_len -= 64;
    }

    memcpy(block, message, message_len);
    block[message_len] = 0x80;
    if (message_len < 56) {
        memset(block + message_len + 1, 0, 56 - message_len - 1);
    } else {
        memset(block + message_len + 1, 0, 64 - message_len - 1);
        sha256_transform(state, block);
        memset(block, 0, 56);
    }

    *(uint64_t*)(block + 56) = htobe64(bitlen);
    sha256_transform(state, block);

    for (i = 0; i < 8; ++i) {
        hash[i*4+0] = state[i] >> 24;
        hash[i*4+1] = state[i] >> 16;
        hash[i*4+2] = state[i] >> 8;
        hash[i*4+3] = state[i];
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s message\n", argv[0]);
        return 0;
    }

    uint8_t hash[32];
    sha256((uint8_t*)argv[1], strlen(argv[1]), hash);

    printf("SHA256 hash of \"%s\":\n", argv[1]);
    for (int i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}