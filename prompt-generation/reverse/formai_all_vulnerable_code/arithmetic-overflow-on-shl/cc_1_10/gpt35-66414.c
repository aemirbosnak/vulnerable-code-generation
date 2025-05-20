//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROT_L(x,n) (((x) << (n)) | ((x) >> (32 - (n))))

typedef struct {
    unsigned int h[8];
} hash_ctx;

void sha256_init(hash_ctx *ctx) {
    ctx->h[0] = 0x6a09e667;
    ctx->h[1] = 0xbb67ae85;
    ctx->h[2] = 0x3c6ef372;
    ctx->h[3] = 0xa54ff53a;
    ctx->h[4] = 0x510e527f;
    ctx->h[5] = 0x9b05688c;
    ctx->h[6] = 0x1f83d9ab;
    ctx->h[7] = 0x5be0cd19;
}

void sha256_transform(hash_ctx *ctx, const unsigned char *msg, unsigned int len) {
    unsigned int i, j, t1, t2, m[64], w[64];
    unsigned int a, b, c, d, e, f, g, h;

    for (i = 0, j = 0; i < len; i++, j = (j + 1) % 4) {
        m[i / 4] |= msg[i] << (24 - (j * 8));
    }

    for (i = 0; i < 16; i++) {
        w[i] = m[i];
    }

    for (; i < 64; i++) {
        w[i] = w[i - 16] + ROT_L(w[i - 15], 7) + w[i - 7] + ROT_L(w[i - 2], 15);
    }

    a = ctx->h[0];
    b = ctx->h[1];
    c = ctx->h[2];
    d = ctx->h[3];
    e = ctx->h[4];
    f = ctx->h[5];
    g = ctx->h[6];
    h = ctx->h[7];

    for (i = 0; i < 64; i++) {
        t1 = h + (ROT_L(e, 6) ^ ROT_L(e, 11) ^ ROT_L(e, 25)) + ((e & f) ^ ((~e) & g)) + w[i] + 0x428a2f98;
        t2 = (ROT_L(a, 2) ^ ROT_L(a, 13) ^ ROT_L(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
    ctx->h[4] += e;
    ctx->h[5] += f;
    ctx->h[6] += g;
    ctx->h[7] += h; 
}

void sha256_final(hash_ctx *ctx, unsigned char *hash) {
    unsigned int i;
    unsigned char buffer[64];

    buffer[0] = 0x80;
    memset(buffer + 1, 0, 63 - 4);

    unsigned int msg_bits = strlen(buffer) * 8;

    for (i = 0; i < 4; i++) {
        buffer[64 - (4 - i)] = (msg_bits >> (24 - (i * 8))) & 0xff;
    }

    sha256_transform(ctx, buffer, 64);

    for (i = 0; i < 8; i++) {
        hash[4 * i] = (ctx->h[i] >> 24) & 0xff;
        hash[4 * i + 1] = (ctx->h[i] >> 16) & 0xff;
        hash[4 * i + 2] = (ctx->h[i] >> 8) & 0xff;
        hash[4 * i + 3] = (ctx->h[i]) & 0xff;
    }
}

void sha256(const unsigned char *msg, unsigned int len, unsigned char *hash) {
    hash_ctx ctx;
    sha256_init(&ctx);
    sha256_transform(&ctx, msg, len);
    sha256_final(&ctx, hash);
}

int main() {
    unsigned char hash[32];
    unsigned char msg[] = "Hello world";
    sha256(msg, strlen(msg), hash);

    printf("SHA256 hash of \"%s\" is:\n", msg);
    for (int i = 0; i < sizeof(hash); i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}