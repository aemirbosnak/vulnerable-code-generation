//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x, n) ((x) >> (n) | (x) << (32 - (n))) // right rotate

uint32_t h0, h1, h2, h3, h4; // initial hash values

void sha1_process(uint32_t *w); // process a block of data

void sha1(uint8_t *data, size_t len) {
    uint32_t *w = calloc(80, sizeof(uint32_t)); // message schedule array
    uint8_t *p = data; // pointer to current byte
    size_t n = len; // number of remaining bytes

    // initialize hash values
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    h4 = 0xC3D2E1F0;

    // process each block of data
    while (n >= 64) {
        // prepare message schedule array
        int i;
        for (i = 0; i < 16; i++)
            w[i] = (p[i * 4] << 24) | (p[i * 4 + 1] << 16) | (p[i * 4 + 2] << 8) | (p[i * 4 + 3]);

        // extend message schedule array
        for (i = 16; i < 80; i++)
            w[i] = ROTR(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

        sha1_process(w); // process block

        p += 64; // advance pointer
        n -= 64; // reduce remaining bytes
    }

    // pad last block of data
    uint8_t block[64] = {0};
    memcpy(block, p, n);
    block[n] = 0x80;
    if (n >= 56) {
        sha1_process((uint32_t *)block);
        memset(block, 0, 64);
    }
    uint64_t bitlen = ((uint64_t)len) * 8;
    block[56] = bitlen >> 56;
    block[57] = bitlen >> 48;
    block[58] = bitlen >> 40;
    block[59] = bitlen >> 32;
    block[60] = bitlen >> 24;
    block[61] = bitlen >> 16;
    block[62] = bitlen >> 8;
    block[63] = bitlen;
    sha1_process((uint32_t *)block); // process last block

    free(w);
}

void sha1_process(uint32_t *w) {
    uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f, k, temp;
    int i;

    for (i = 0; i < 80; i++) {
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        } else if (i < 40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        } else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        } else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        temp = ROTR(a, 5) + f + e + k + w[i];
        e = d;
        d = c;
        c = ROTR(b, 30);
        b = a;
        a = temp;
    }

    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;
}

int main() {
    char input[1024]; // buffer to hold user input
    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    input[len - 1] = '\0'; // remove newline character

    sha1((uint8_t *)input, len); // compute SHA-1 hash

    printf("SHA-1 hash: %08X%08X%08X%08X%08X\n", h0, h1, h2, h3, h4);
    return 0;
}