//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,y) (((x)<<(y))|((x)>>(32-(y))))
#define ROTR(x,y) (((x)>>(y))|((x)<<(32-(y))))
#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0

static uint32_t const K[64] =
{
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

void SHA256(const char *message, uint32_t digest[]) 
{
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;
    uint32_t m[64];
    uint32_t h0, h1, h2, h3, h4, h5, h6, h7;
    uint32_t *w256 = m;

    int n_blocks;

    n_blocks = (((strlen(message) * 8) + 64 + 1 + 512) / 512);

    n_blocks *= 16;

    memset(m, 0, sizeof(m));

    for(i = 0; i < strlen(message); i += 4) 
    {
        w256[i/4] = ((uint32_t)message[i]) << 24;
        if(i + 1 < strlen(message)) 
        {
            w256[i/4] |= ((uint32_t)message[i+1]) << 16;
        }

        if(i + 2 < strlen(message)) 
        {
            w256[i/4] |= ((uint32_t)message[i+2]) << 8;
        }

        if(i + 3 < strlen(message)) 
        {
            w256[i/4] |= ((uint32_t)message[i+3]);
        }
    }

    w256[strlen(message)/4] |= (1 << 31);

    uint32_t pad_size_bits = strlen(message) * 8;

    if(((16 - (strlen(message) / 4) % 16) % 16) < 8)
    {
        n_blocks += 16;
    }

    w256[n_blocks-2] |= pad_size_bits;
    w256[n_blocks-1] |= pad_size_bits >> 32;

    h0 = 0x6a09e667;
    h1 = 0xbb67ae85;
    h2 = 0x3c6ef372;
    h3 = 0xa54ff53a;
    h4 = 0x510e527f;
    h5 = 0x9b05688c;
    h6 = 0x1f83d9ab;
    h7 = 0x5be0cd19;

    for(i = 0; i < n_blocks; i += 16) 
    {
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;

        for(j = 0; j < 64; j++) 
        {
            if (j < 16) 
            {
                t1 = m[j];
            } 
            else 
            {
                t1 = m[(j + 1) & 15];
                t1 += ROTL(m[(j + 14) & 15], 17) ^ ROTL(m[(j + 14) & 15], 19) ^ (m[(j + 14) & 15] >> 10);
                t1 += m[(j + 9) & 15];
                t1 += ROTL(m[(j + 1) & 15], 7) ^ ROTL(m[(j + 1) & 15], 18) ^ (m[(j + 1) & 15] >> 3);
                m[j&15] = t1;
            }

            t1 = h + ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25); 
            t1 += (e & f) ^ ((~e) & g);
            t1 += K[j] + t1;

            t2 = ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22);
            t2 += (a & b) ^ (a & c) ^ (b & c);

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g; 
        h7 += h;
    }

    digest[0] = h0;
    digest[1] = h1;
    digest[2] = h2;
    digest[3] = h3;
    digest[4] = h4;
    digest[5] = h5;
    digest[6] = h6;
    digest[7] = h7;
}

int main() 
{
    char message[1024];
    uint32_t digest[8];

    printf("Enter a message to hash: ");
    scanf("%[^\n]%*c", message);

    SHA256(message, digest);

    printf("The SHA-256 hash of '%s' is:\n", message);
    printf("%08x %08x %08x %08x %08x %08x %08x %08x\n", 
         digest[0], digest[1], digest[2], digest[3], 
         digest[4], digest[5], digest[6], digest[7]);

    return EXIT_SUCCESS;
}