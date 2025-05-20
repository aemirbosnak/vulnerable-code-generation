//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* rotate left function */
#define ROTL(value, shift) ((value << shift) | (value >> (32 - shift)))

/* SHA-256 Constants */
const uint32_t k[] = {
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

/* SHA-256 Functions */
#define Ch(x, y, z) ((x & y) ^ (~x & z)) 
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define Sigma0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))
#define Sigma1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))
#define sigma0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3))
#define sigma1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10))

/* Hash Computation */
void sha256(uint8_t *data, uint32_t length, uint8_t *hash)
{
    uint32_t h0, h1, h2, h3, h4, h5, h6, h7, i;
    uint32_t a, b, c, d, e, f, g, h, s0, s1, t1, t2, m[64];

    /* Initialize Hash Values */
    h0 = 0x6a09e667;
    h1 = 0xbb67ae85;
    h2 = 0x3c6ef372;
    h3 = 0xa54ff53a;
    h4 = 0x510e527f;
    h5 = 0x9b05688c;
    h6 = 0x1f83d9ab;
    h7 = 0x5be0cd19;

    /* Message Padding */
    int new_length = ((((length + 8) / 64) + 1) * 64);
    uint8_t *message = (uint8_t*) malloc(new_length);
    memcpy(message, data, length);
    message[length] = 0x80;
    uint64_t bit_length = length * 8;
    memcpy(message + new_length - 8, &bit_length, 8);

    /* Divide Message into 512-bit chunks */
    for (i = 0; i < new_length; i += 64)
    {
        /* Parse Message Chunk */
        for (int j = 0; j < 16; j++)
        {
            m[j] = (message[i + (j * 4)] << 24) | 
                            (message[i + (j * 4) + 1] << 16) |
                            (message[i + (j * 4) + 2] << 8) |
                            (message[i + (j * 4) + 3]);
        }

        /* Extend Message */
        for (int j = 16; j < 64; j++)
        {
            s0 = sigma0(m[j-15]);
            s1 = sigma1(m[j-2]);
            m[j] = m[j-16] + s0 + m[j-7] + s1;
        }

        /* Initialize Working Variables */
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;

        /* Main Hash Loop */
        for (int j = 0; j < 64; j++)
        {
            s0 = Sigma0(a);
            s1 = Sigma1(e);
            t1 = h + s1 + Ch(e, f, g) + k[j] + m[j];
            t2 = s0 + Maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        /* Update Hash Values */
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    /* Final Hash Value */
    memcpy(hash, &h0, 4);
    memcpy(hash + 4, &h1, 4);
    memcpy(hash + 8, &h2, 4);
    memcpy(hash + 12, &h3, 4);
    memcpy(hash + 16, &h4, 4);
    memcpy(hash + 20, &h5, 4);
    memcpy(hash + 24, &h6, 4);
    memcpy(hash + 28, &h7, 4);

    /* Free Memory */
    free(message);
}

int main()
{
    uint8_t data[] = "Hello, World!";
    uint8_t hash[32];

    /* Compute Hash */
    sha256(data, strlen(data), hash);

    /* Print Hash */
    for (int i = 0; i < 32; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}