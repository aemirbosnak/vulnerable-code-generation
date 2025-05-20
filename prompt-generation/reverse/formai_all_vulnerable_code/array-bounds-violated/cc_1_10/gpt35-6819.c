//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

const uint64_t keccakf_rndc[24] = {
    0x0000000000000001, 0x0000000000008082, 0x800000000000808a,
    0x8000000080008000, 0x000000000000808b, 0x0000000080000001,
    0x8000000080008081, 0x8000000000008009, 0x000000000000008a,
    0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
    0x000000008000808b, 0x800000000000008b, 0x8000000000008089,
    0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
    0x000000000000800a, 0x800000008000000a, 0x8000000080008081,
    0x8000000000008080, 0x0000000080000001, 0x8000000080008008
};

const uint8_t keccakf_rotc[24] = {
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14,
    27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44
};

const uint8_t keccakf_piln[24] = {
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4,
    15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1
};

void keccakf(uint64_t st[25])
{
    int i, j, round;
    uint64_t t, bc[5];

    for (round = 0; round < 24; round++) {
        for (i = 0; i < 5; i++) {
            bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15] ^ st[i + 20];
        }

        for (i = 0; i < 5; i++) {
            t = bc[(i + 4) % 5] ^ ROTL64(bc[(i + 1) % 5], 1);
            for (j = 0; j < 25; j += 5) {
                st[j + i] ^= t;
            }
        }

        t = st[1];
        for (i = 0; i < 24; i++) {
            j = keccakf_piln[i];
            bc[0] = st[j];
            st[j] = ROTL64(t, keccakf_rotc[i]);
            t = bc[0];
        }

        for (j = 0; j < 25; j += 5) {
            for (i = 0; i < 5; i++) {
                bc[i] = st[j + i];
            }

            for (i = 0; i < 5; i++) {
                st[j + i] ^= (~bc[(i + 1) % 5]) & bc[(i + 2) % 5];
            }
        }

        st[0] ^= keccakf_rndc[round];
    }
}

void sha3_256(const void *input, size_t len, uint8_t output[32])
{
    uint64_t st[25] = {0};
    const uint8_t *data = (const uint8_t *)input;
    size_t i, r;
    uint8_t temp[136], *t;

    /* Absorb input */
    for (i = 0; i < len; ++i) {
        st[i / 8 % 17 * 5 + i % 5] ^= (uint64_t)data[i] << (8 * (i % 8));
    }

    /* Padding */
    st[i / 8 % 17 * 5 + i % 5] ^= (uint64_t)1 << (8 * (i % 8));
    st[15 * 5] ^= 0x8000000000000000ull;
    keccakf(st);

    /* Squeeze output */
    for (i = 0; i < 32; ++i) {
        output[i] = st[i / 8 % 17 * 5 + i % 5] >> (8 * (i % 8));
    }
}

int main()
{
    char input[] = "Hello World";
    uint8_t output[32] = {0};

    sha3_256(input, sizeof(input) - 1, output);

    for (int i = 0; i < 32; ++i) {
        printf("%02x", output[i]);
    }

    printf("\n");

    return 0;
}