//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64 // Block size in bytes
#define HASH_SIZE 32 // Hash size in bytes
#define WORD_SIZE 4 // Word size in bytes
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n)))) // Rotate right
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z))) // Choose
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))) // Majority
#define BSIG0(x) (ROTR((x), 2) ^ ROTR((x), 13) ^ ROTR((x), 22)) // Big sigma 0
#define BSIG1(x) (ROTR((x), 6) ^ ROTR((x), 11) ^ ROTR((x), 25)) // Big sigma 1
#define SSIG0(x) (ROTR((x), 7) ^ ROTR((x), 18) ^ ((x) >> 3)) // Small sigma 0
#define SSIG1(x) (ROTR((x), 17) ^ ROTR((x), 19) ^ ((x) >> 10)) // Small sigma 1

typedef struct state_t {
    unsigned char data[BLOCK_SIZE];
    unsigned int datalen;
    unsigned long long bitlen;
    unsigned int state[HASH_SIZE / WORD_SIZE];
} state;

const unsigned int K[] = {
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

void init(state *s) {
    s->datalen = 0;
    s->bitlen = 0;
    s->state[0] = 0x6a09e667;
    s->state[1] = 0xbb67ae85;
    s->state[2] = 0x3c6ef372;
    s->state[3] = 0xa54ff53a;
    s->state[4] = 0x510e527f;
    s->state[5] = 0x9b05688c;
    s->state[6] = 0x1f83d9ab;
    s->state[7] = 0x5be0cd19;
}

void transform(state *s, const unsigned char* data) {
    unsigned int a, b, c, d, e, f, g, h, i, j, t1, t2, m[HASH_SIZE / WORD_SIZE];

    for (i = 0, j = 0; i < BLOCK_SIZE; ++i, j += 4) {
        m[i / WORD_SIZE] |= (unsigned int)data[j] << ((i % WORD_SIZE) * 8);
    }

    a = s->state[0];
    b = s->state[1];
    c = s->state[2];
    d = s->state[3];
    e = s->state[4];
    f = s->state[5];
    g = s->state[6];
    h = s->state[7];

    for (i = 0; i < 64; ++i) {
        if (i < 16) {
            t1 = m[i];
        } else {
            t1 = m[(i + 1) % 16];
            t1 = SSIG0(t1);
            t1 += m[(i + 14) % 16];
            t1 = SSIG1(t1);
            t1 += m[i % 16];
        }

        t1 += h;
        t1 += BSIG1(e);
        t1 += CH(e, f, g);
        t1 += K[i];
        t2 = BSIG0(a);
        t2 += MAJ(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    s->state[0] += a;
    s->state[1] += b;
    s->state[2] += c;
    s->state[3] += d;
    s->state[4] += e;
    s->state[5] += f;
    s->state[6] += g;
    s->state[7] += h;
}

void update(state *s, const unsigned char *data, unsigned int len) {
    for (unsigned int i = 0; i < len; ++i) {
        s->data[s->datalen] = data[i];
        ++s->datalen;
        if (s->datalen == BLOCK_SIZE) {
            transform(s, s->data);
            s->bitlen += BLOCK_SIZE * 8;
            s->datalen = 0;
        }
    }
}

void final(state *s, unsigned char *hash) {
    unsigned int i;

    i = s->datalen;

    // Pad whatever data is left in the buffer.
    if (s->datalen < 56) {
        s->data[i++] = 0x80;
        while (i < 56) {
            s->data[i++] = 0x00;
        }
    } else {
        s->data[i++] = 0x80;
        while (i < BLOCK_SIZE) {
            s->data[i++] = 0x00;
        }
        transform(s, s->data);
        memset(s->data, 0, 56);
    }

    // Append to the padding the total message's length in bits and transform.
    s->bitlen += s->datalen * 8;
    s->data[63] = s->bitlen;
    s->data[62] = s->bitlen >> 8;
    s->data[61] = s->bitlen >> 16;
    s->data[60] = s->bitlen >> 24;
    s->data[59] = s->bitlen >> 32;
    s->data[58] = s->bitlen >> 40;
    s->data[57] = s->bitlen >> 48;
    s->data[56] = s->bitlen >> 56;
    transform(s, s->data);

    // Since this implementation uses little endian byte ordering and SHA uses big endian,
    // reverse all the bytes when copying the final state to the output hash.
    for (i = 0; i < 4; ++i) {
        hash[i] = (s->state[0] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 4] = (s->state[1] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 8] = (s->state[2] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 12] = (s->state[3] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 16] = (s->state[4] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 20] = (s->state[5] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 24] = (s->state[6] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 28] = (s->state[7] >> (24 - i * 8)) & 0x000000ff;
    }
}

int main() {
    state s;
    unsigned char hash[HASH_SIZE];
    char message[] = "The quick brown fox jumps over the lazy dog";
    init(&s);
    update(&s, (unsigned char*)message, strlen(message));
    final(&s, hash);

    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}