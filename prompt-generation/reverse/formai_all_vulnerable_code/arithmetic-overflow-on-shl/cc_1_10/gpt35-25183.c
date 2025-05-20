//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* The FIPS-202 SHA-3 hash function, Keccak permutation with padding and squeezing functions */

typedef struct {
    uint64_t state[25];
    uint32_t rate;
    uint32_t pos;
    uint8_t padding;
} SHA3_CTX;

static const uint64_t keccakf_rndc[] = {
    0x0000000000000001ULL, 0x0000000000008082ULL, 0x800000000000808aULL, 0x8000000080008000ULL,
    0x000000000000808bULL, 0x0000000080000001ULL, 0x8000000080008081ULL, 0x8000000000008009ULL,
    0x000000000000008aULL, 0x0000000000000088ULL, 0x0000000080008009ULL, 0x000000008000000aULL,
    0x000000008000808bULL, 0x800000000000008bULL, 0x8000000000008089ULL, 0x8000000000008003ULL,
    0x8000000000008002ULL, 0x8000000000000080ULL, 0x000000000000800aULL, 0x800000008000000aULL,
    0x8000000080008081ULL, 0x8000000000008080ULL, 0x0000000080000001ULL, 0x8000000080008008ULL
};

static const uint8_t keccakf_rotc[25] = {
     1,  3,  6, 10, 15, 21, 28, 36, 45, 55,  2, 14, 27, 41, 56,  8, 25, 43, 62, 18, 39, 61, 20, 44, 43
};

static const uint8_t keccakf_piln[25] = {
    10,  7, 11, 17, 18,  3,  5, 16,  8, 21, 24,  4, 15, 23, 19, 13, 12,  2, 20, 14, 22,  9,  6,  1, 25
};

/* Rotate left and right operations */
#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))
#define ROTR64(x, y) (((x) >> (y)) | ((x) << (64 - (y))))

/* Keccak permutation */
static void keccakf(uint64_t state[25])
{
    uint8_t i, j, k, l = 0;
    uint64_t t = 0;
    uint64_t bc[5];

    for (i = 0; i < 24; ++i) {
        for (j = 0; j < 5; ++j) {
            bc[j] = state[l + j];
        }
        for (j = 0; j < 5; ++j) {
            state[l + j] ^= bc[(j + 4) % 5] ^ ROTL64(bc[(j + 1) % 5], 1);
        }
        t = state[1];
        for (j = 0; j < 24; ++j) {
            k = keccakf_piln[j];
            bc[0] = state[k];
            state[k] = ROTL64(t, keccakf_rotc[j]);
            t = bc[0];
        }
        for (k = 0; k < 5; ++k) {
            bc[k] = state[l + k];
        }
        for (j = 0; j < 5; ++j) {
            state[l + j] ^= bc[(j + 4) % 5] ^ ROTL64(bc[(j + 1) % 5], 1);
        }
        l = (l + 1) % 5;
    }
}

/* Keccak Squeezing Function */
static void keccakf_squeeze(uint64_t state[25], uint8_t* data, uint32_t count, uint32_t bits)
{
    uint8_t i = 0;
    uint8_t* ptr = data;
    uint64_t t = 0;

    while (count > 0) {
        for (i = 0; i < bits / 8; ++i) {
            if (count > 0) {
                *ptr++ = (state[i / 8] >> (8 * (i % 8))) & 0xff;
                --count;
            }
        }
        if (count == 0) {
            break;
        }
        keccakf(state);
        t += bits;
    }
}

/* Keccak Padding Function */
static uint32_t keccakf_pad(SHA3_CTX* ctx, uint8_t* data, uint32_t count)
{
    uint8_t i, j;
    uint32_t rate = ctx->rate / 8;
    uint32_t remain = count % rate;
    uint32_t padding = rate - remain;

    if (remain == 0) {
        padding = rate;
    }
    if (padding == 1) {
        data[count] |= 1 << 7;
        keccakf_squeeze(ctx->state, data, count + 1, ctx->rate);
    } else {
        data[count] |= 1 << 7;
        for (i = count + 1; i < count + padding - 1; ++i) {
            data[i] = 0;
        }
        data[count + padding - 1] |= 1;
        keccakf_squeeze(ctx->state, data, count + padding, ctx->rate);
    }
    for (i = 0; i < rate / 8; ++i) {
        ctx->state[i] ^= 0x00;
    }
    ctx->state[rate / 8 - 1] ^= 0x80;
    keccakf(ctx->state);
    return padding;
}

/* Keccak Absorbing Function */
static void keccakf_absorb(SHA3_CTX* ctx, uint8_t* data, uint32_t count)
{
    uint8_t i, j, k, r;
    uint32_t rate = ctx->rate / 8;

    for (i = 0; i < count / rate; ++i) {
        for (j = 0; j < rate / 8; ++j) {
            r = 0;
            for (k = 0; k < 8; ++k) {
                r |= (data[i * rate + j * 8 + k] << (8 * k));
            }
            ctx->state[j] ^= r;
        }
        keccakf(ctx->state);
    }
    r = 0;
    if (count % rate != 0) {
        for (j = 0; j < count % rate / 8; ++j) {
            r = 0;
            for (k = 0; k < 8; ++k) {
                r |= (data[i * rate + j * 8 + k] << (8 * k));
            }
            ctx->state[j] ^= r;
        }
    }
    ctx->pos = count % rate;
}

/* SHA3-224 Hash Function */
static void sha3_224(uint8_t* message, uint32_t count, uint8_t* digest)
{
    SHA3_CTX ctx;
    memset(&ctx, 0, sizeof(SHA3_CTX));
    ctx.rate = 1152;
    ctx.pos = 0;
    ctx.padding = 0x06;

    keccakf_absorb(&ctx, message, count);
    keccakf_pad(&ctx, message, count);
    keccakf_squeeze(ctx.state, digest, 28, 224);
}

int main()
{
    /* Example usage */
    uint8_t message[] = {0x32, 0x43, 0xF6, 0xA8, 0x88, 0x5A, 0x30, 0x8D, 0x31, 0x31, 0x98, 0xA2, 0xE0, 0x37, 0x07, 0x34};
    uint8_t digest[28];

    sha3_224(message, sizeof(message), digest);

    printf("SHA3-224: ");
    for (int i = 0; i < 28; i++) {
        printf("%02x", digest[i]);
    }

    return 0;
}