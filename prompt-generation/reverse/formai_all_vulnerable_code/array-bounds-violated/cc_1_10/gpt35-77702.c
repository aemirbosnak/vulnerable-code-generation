//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTR(x,y) (((x) >> (y)) | ((x) << (32-y)))

typedef unsigned int uint32;

uint32 f1(uint32 x, uint32 y, uint32 z) { return x ^ y ^ z; }
uint32 f2(uint32 x, uint32 y, uint32 z) { return (x & y) | (~x & z); }
uint32 f3(uint32 x, uint32 y, uint32 z) { return (x | ~y) ^ z; }
uint32 f4(uint32 x, uint32 y, uint32 z) { return (x & z) | (y & ~z); }
uint32 f5(uint32 x, uint32 y, uint32 z) { return x ^ (y | ~z); }

uint32 a, b, c, d, e, f, g, h; // variables for chaining values
uint32 w[80]; // message schedule array

void sha1(uint32 *hash, uint32 *data, int len) {

    for (int i = 0; i < (len + 8) / 64; i++) {

        // prepare message schedule
        for (int j = 0; j < 16; j++)
            w[j] = data[i*16+j];
        for (int j = 16; j < 80; j++)
            w[j] = ROTR(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1);

        // initialize chain values
        a = hash[0], b = hash[1], c = hash[2], d = hash[3], e = hash[4];

        // main loop
        for (int j = 0; j < 80; j++) {
            if (j < 20) {
                f = f1(b, c, d);
                g = 0x5A827999;
            } else if (j < 40) {
                f = f2(b, c, d);
                g = 0x6ED9EBA1;
            } else if (j < 60) {
                f = f3(b, c, d);
                g = 0x8F1BBCDC;
            } else {
                f = f4(b, c, d);
                g = 0xCA62C1D6;
            }
            h = ROTR(a, 5) + f + e + g + w[j];
            e = d, d = c, c = ROTR(b, 30), b = a, a = h;
        }

        // update chaining values
        hash[0] += a, hash[1] += b, hash[2] += c, hash[3] += d, hash[4] += e;
    }
}

int main() {
    char message[] = "Hello, world!";
    int len = strlen(message);

    // append padding to message
    message[len] = 0x80;
    len++;
    while (len % 64 != 56) {
        message[len] = 0;
        len++;
    }

    // append message length to padding
    uint32 bitlen = strlen(message) * 8;
    memcpy(message + len, &bitlen, 4);
    len += 4;

    // initialize hash values
    uint32 hash[5];
    hash[0] = 0x67452301;
    hash[1] = 0xEFCDAB89;
    hash[2] = 0x98BADCFE;
    hash[3] = 0x10325476;
    hash[4] = 0xC3D2E1F0;

    // hash message
    sha1(hash, (uint32*)message, len);

    // print hash
    for (int i = 0; i < 5; i++)
        printf("%08X", hash[i]);

    return 0;
}