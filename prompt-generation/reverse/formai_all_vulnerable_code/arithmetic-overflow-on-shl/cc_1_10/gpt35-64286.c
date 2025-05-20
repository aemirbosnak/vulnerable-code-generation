//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x,y) ((x >> y) | (x << (32 - y)))
#define ROTL64(x,y) ((x << y) | (x >> (64 - y)))
#define ROTR64(x,y) ((x >> y) | (x << (64 - y)))

#define BIG_ENDIAN

#if defined(BIG_ENDIAN)
#define SWAP32(x) (x)
#define SWAP64(x) (x)
#elif defined(LITTLE_ENDIAN)
#define SWAP32(x) ((x >> 24) & 0xff) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) | (x << 24)
#define SWAP64(x) ((x >> 56) & 0xff) | ((x >> 40) & 0xff00) | ((x >> 24) & 0xff0000) | ((x >> 8) & 0xff000000) | ((x << 8) & 0xff00000000) | ((x << 24) & 0xff0000000000) | ((x << 40) & 0xff000000000000) | (x << 56)
#else
#error "Endianness not defined!"
#endif

uint32_t k[4] = {
    0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

uint32_t h[5] = {
    0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0
};

uint32_t w[80];

void sha1_process_message_block() {
    int t;
    uint32_t temp, a, b, c, d, e;

    for (t = 16; t < 80; ++t)
        w[t] = ROTL32(w[t-3] ^ w[t-8] ^ w[t-14] ^ w[t-16], 1);

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];

    for (t = 0; t < 80; ++t) {
        if (t < 20) {
            temp = ROTL32(a, 5) + ((b & c) | (~b & d)) + e + w[t] + k[0];
        }
        else if (t < 40) {
            temp = ROTL32(a, 5) + (b ^ c ^ d) + e + w[t] + k[1];
        }
        else if (t < 60) {
            temp = ROTL32(a, 5) + ((b & c) | (b & d) | (c & d)) + e + w[t] + k[2];
        }
        else {
            temp = ROTL32(a, 5) + (b ^ c ^ d) + e + w[t] + k[3];
        }
        e = d;
        d = c;
        c = ROTL32(b, 30);
        b = a;
        a = temp;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
}

void sha1_generate_hash(uint8_t message[], uint64_t length, uint32_t hash[]) {
    int i, j;
    uint64_t bit_length = length * 8;
    uint32_t message_words[length / 4 + 1];

    for (i = 0, j = 0; i < length; ++i, j = (i % 4 == 3 ? j + 1 : j)) {
        message_words[j] = (message_words[j] << 8) | message[i];
    }

    message_words[length / 4] |= 1 << 31 - (bit_length % 32);
    message_words[length / 4] = SWAP32(message_words[length / 4]);

    if (length % 4 == 3) {
        message_words[length / 4] |= 0xff << 8;
    }
    else if (length % 4 == 2) {
        message_words[length / 4] |= 0xffff;
    }
    else if (length % 4 == 1) {
        message_words[length / 4] |= 0xff << 24;
    }

    for (i = 0; i < length / 4 + 1; ++i) {
        w[i / 4] = message_words[i];
        if (i % 4 == 3)
            sha1_process_message_block();
    }

    for (; i % 16 != 14; ++i)
        w[i / 4] = 0;

    w[14] = SWAP32((uint32_t)(bit_length >> 32));
    w[15] = SWAP32((uint32_t)bit_length);

    sha1_process_message_block();

    for (i = 0; i < 5; ++i) {
        hash[i] = SWAP32(h[i]);
    }
}

int main() {
    uint8_t message[] = "Test message";
    uint32_t hash[5];
    int i;

    sha1_generate_hash(message, strlen((char*)message), hash);

    printf("The hash is: ");
    for (i = 0; i < 5; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}