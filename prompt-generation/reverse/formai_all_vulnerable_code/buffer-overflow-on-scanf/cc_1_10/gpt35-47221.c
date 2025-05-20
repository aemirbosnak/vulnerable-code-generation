//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: unmistakable
/*
 * This is a unique C Cryptographic hash function utilizing the SHA-3 algorithm.
 * It takes a string input and outputs a 128-bit hash value.
 * Developed by [Your Name], [Date], for [Purpose/Project Name]
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

#define KECCAK_SPONGE_WORDS 25
#define KECCAK_ROUNDS 24
#define KECCAK_DIGEST_WORDS 2

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

static const u64 keccakf_rndc[24] =
{
    0x0000000000000001, 0x0000000000008082, 0x800000000000808a,
    0x8000000080008000, 0x000000000000808b, 0x0000000080000001,
    0x8000000080008081, 0x8000000000008009, 0x000000000000008a,
    0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
    0x000000008000808b, 0x800000000000008b, 0x8000000000008089,
    0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
    0x000000000000800a, 0x800000008000000a, 0x8000000080008081,
    0x8000000000008080, 0x0000000080000001, 0x8000000080008008
};

static const int keccakf_rotc[24] =
{
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14,
    27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44
};

static const int keccakf_piln[24] =
{
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4,
    15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1
};

void keccakf(u64 st[KECCAK_SPONGE_WORDS])
{
    int i, j, round;
    u64 t, bc[5];

    for (round = 0; round < KECCAK_ROUNDS; round++)
    {
        // Theta
        for (i = 0; i < 5; i++)
            bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15] ^ st[i + 20];

        for (i = 0; i < 5; i++)
        {
            t = bc[(i + 4) % 5] ^ ROTL(bc[(i + 1) % 5], 1);
            for (j = 0; j < 25; j += 5)
                st[j + i] ^= t;
        }

        // Rho Pi
        t = st[1];
        for (i = 0; i < 24; i++)
        {
            j = keccakf_piln[i];
            bc[0] = st[j];
            st[j] = ROTL(t, keccakf_rotc[i]);
            t = bc[0];
        }

        // Chi
        for (j = 0; j < 25; j += 5)
        {
            for (i = 0; i < 5; i++)
                bc[i] = st[j + i];
            for (i = 0; i < 5; i++)
                st[j + i] ^= (~bc[(i + 1) % 5]) & bc[(i + 2) % 5];
        }

        // Iota
        st[0] ^= keccakf_rndc[round];
    }
}

void keccak(const u8 *in, int inlen, u8 *md, int mdlen)
{
    u64 st[KECCAK_SPONGE_WORDS];
    u8 temp[144];
    int i;
    memset(st, 0, sizeof(st));
    for (i = 0; i < KECCAK_ROUNDS/8; i++)
    {
        st[i] = ((u64)in[8*i+7+inlen%8]) << 56
              | ((u64)in[8*i+6+inlen%8]) << 48
              | ((u64)in[8*i+5+inlen%8]) << 40
              | ((u64)in[8*i+4+inlen%8]) << 32
              | ((u64)in[8*i+3+inlen%8]) << 24
              | ((u64)in[8*i+2+inlen%8]) << 16
              | ((u64)in[8*i+1+inlen%8]) << 8
              | ((u64)in[8*i+0+inlen%8]);
    }
    st[inlen/8] |= 1ull << (inlen%8);
    st[KECCAK_SPONGE_WORDS-1] |= 0x8000000000000000ull;
    keccakf(st);
    for (i = 0; i < mdlen/8; i++)
    {
        md[8*i+0] = (st[i>>3] >> ((i&7)*8+0)) & 0xff;
        md[8*i+1] = (st[i>>3] >> ((i&7)*8+1)) & 0xff;
        md[8*i+2] = (st[i>>3] >> ((i&7)*8+2)) & 0xff;
        md[8*i+3] = (st[i>>3] >> ((i&7)*8+3)) & 0xff;
        md[8*i+4] = (st[i>>3] >> ((i&7)*8+4)) & 0xff;
        md[8*i+5] = (st[i>>3] >> ((i&7)*8+5)) & 0xff;
        md[8*i+6] = (st[i>>3] >> ((i&7)*8+6)) & 0xff;
        md[8*i+7] = (st[i>>3] >> ((i&7)*8+7)) & 0xff;
    }
}

int main()
{
    char str[100];
    printf("Enter a string to hash: ");
    scanf("%s", str);

    // Calculate the hash
    u8 hash[KECCAK_DIGEST_WORDS * 8];
    keccak((u8*)str, strlen(str), hash, KECCAK_DIGEST_WORDS * 8);

    // Print the hash in hexadecimal format
    printf("Hash value: ");
    for (int i = 0; i < KECCAK_DIGEST_WORDS * 8; ++i)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}