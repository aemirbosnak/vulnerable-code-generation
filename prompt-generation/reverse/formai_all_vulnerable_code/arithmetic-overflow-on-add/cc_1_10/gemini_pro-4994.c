//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 hash function
uint32_t sha256(const uint8_t *data, size_t len) {
    uint32_t h0, h1, h2, h3, h4, h5, h6, h7;
    uint32_t k[64];
    uint8_t padded[64 + 8];

    // Initialize hash values
    h0 = 0x6a09e667;
    h1 = 0xbb67ae85;
    h2 = 0x3c6ef372;
    h3 = 0xa54ff53a;
    h4 = 0x510e527f;
    h5 = 0x9b05688c;
    h6 = 0x1f83d9ab;
    h7 = 0x5be0cd19;

    // Initialize round constants
    for (int i = 0; i < 64; i++) {
        k[i] = 0x428a2f98 + (i < 20 ? 0x5a827999 * i : 0);
    }

    // Pad the data
    memcpy(padded, data, len);
    padded[len] = 0x80;
    memset(padded + len + 1, 0, 63 - len);
    uint64_t bit_len = len * 8;
    memcpy(padded + 56, &bit_len, 8);

    // Process the data
    for (int i = 0; i < (len + 64) / 64; i++) {
        uint32_t w[64];
        memcpy(w, padded + i * 64, 64);

        // Process the message block
        for (int j = 16; j < 64; j++) {
            uint32_t s0 = (w[j - 15] >> 7) | (w[j - 15] << 25);
            uint32_t s1 = (w[j - 2] >> 17) | (w[j - 2] << 15);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        uint32_t a, b, c, d, e, f, g, h;
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;

        for (int j = 0; j < 64; j++) {
            uint32_t s1 = (e >> 6) | (e << 26);
            uint32_t s2 = (a >> 2) | (a << 30);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t ch = (e & f) ^ (~e & g);
            h = g;
            g = f;
            f = e;
            e = d + s1 + ch + k[j] + w[j];
            d = c;
            c = b;
            b = a;
            a = s2 + maj;
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

    // Return the hash value
    return h0;
}

int main() {
    // Compute the hash of a string
    char *str = "Hello, world!";
    uint32_t hash = sha256((uint8_t *)str, strlen(str));

    // Print the hash value
    printf("SHA-256 hash: %08x\n", hash);

    return 0;
}