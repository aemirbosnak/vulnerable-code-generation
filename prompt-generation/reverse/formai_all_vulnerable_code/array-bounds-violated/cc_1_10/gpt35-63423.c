//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum { false, true } bool; // Define bool data type

// Define macros for left and right rotations
#define ROTL(x, n) ((x << n) | (x >> (32 - n)))
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))

// Define SHA-256 constants (first 32 bits of the fractional parts of the cube roots of the first 64 primes)
const uint32_t K[64] = {
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

// Define initial hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes)
uint32_t H[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Define functions for SHA-256 operations
uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t ep0(uint32_t x) {
    return ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
}

uint32_t ep1(uint32_t x) {
    return ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
}

uint32_t sig0(uint32_t x) {
    return ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3);
}

uint32_t sig1(uint32_t x) {
    return ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10);
}

// Define function to transform message for SHA-256
void sha256_transform(uint32_t* message, uint32_t len) {
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    // Copy message into 64-entry message schedule array (break message into 32-bit big-endian words)
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = (message[j] << 24) | (message[j + 1] << 16) | (message[j + 2] << 8) | (message[j + 3]);
    }
    for (; i < 64; ++i) {
        m[i] = sig1(m[i - 2]) + m[i - 7] + sig0(m[i - 15]) + m[i - 16];
    }

    // Initialize hash value for this chunk
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Main loop
    for (i = 0; i < 64; ++i) {
        t1 = h + ep1(e) + ch(e, f, g) + K[i] + m[i];
        t2 = ep0(a) + maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Add this chunk's hash to result so far
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
}

// Define function to calculate SHA-256 hash of input string
char* sha256(char* input) {
    uint32_t i, j, len = strlen(input);
    uint32_t message[len / 4 + (len % 4 != 0)];
    char* output = (char*)malloc(65 * sizeof(char));

    // Convert input string to message array (byte conversion is little-endian)
    for (i = 0, j = 0; i < len;) {
        message[j++] = (input[i] & 0xff) | ((input[++i] & 0xff) << 8) | ((input[++i] & 0xff) << 16) | ((input[++i] & 0xff) << 24);
    }

    // Pad message (append 0x80 byte followed by 0x00 bytes until length is congruent to 448 mod 512)
    message[j] = 0x80;
    for (++j; j % 16 != 14; ++j) {
        message[j] = 0;
    }

    // Append original message length as 64-bit little-endian integer
    message[j] = len << 3;
    message[j + 1] = len >> 29;

    // Transform message in 512-bit chunks
    for (i = 0; i <= j; i += 16) {
        sha256_transform(&message[i], 16);
    }

    // Output hash as 64-character hex string
    for (i = 0; i < 8; ++i) {
        sprintf(&output[i * 8], "%08x", H[i]);
    }
    output[64] = '\0';

    return output;
}

int main() {
    char* input = "Hello World!";
    char* output = sha256(input);

    printf("%s -> %s", input, output);

    free(output);
    return 0;
}