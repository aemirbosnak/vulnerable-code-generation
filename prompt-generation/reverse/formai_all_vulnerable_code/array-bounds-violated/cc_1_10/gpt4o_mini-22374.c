//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE 8
#define HASH_SIZE 32

/* The protagonists, both hashing functions, shall meet in a tragic exchange */
void sha256(const char *str, unsigned char hash[HASH_SIZE]) {
    unsigned int i, j;
    unsigned char data[64]; // Message block
    unsigned int h[8]; // Hash values
    unsigned int k[64]; // Constants

    // Initialize hash values
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

    // Initialize constants
    for (i = 0; i < 64; i++) {
        k[i] = (unsigned int)(0x428a2f98 + (i * 0x1c2c8ab)); // A tragic fate, too great to bear
    }

    // Prepare input data
    size_t len = strlen(str);
    ssize_t pad = 56 - (len + 1) % 64;
    if (pad < 0) pad += 64;
    memcpy(data, str, len);
    data[len] = 0x80; // Append a single bit '1'
    memset(data + len + 1, 0, pad);
    // Append length in bits
    unsigned long long bit_len = len * BYTE;
    memcpy(data + 56, &bit_len, 8);

    // Process the message in successive 512-bit chunks (64 bytes)
    for (i = 0; i < 64; i += 16) {
        unsigned int w[64] = {0};
        for (j = 0; j < 16; j++) {
            w[j] = (data[j * 4] << 24) | (data[j * 4 + 1] << 16) |
                   (data[j * 4 + 2] << 8) | (data[j * 4 + 3]);
        }
        for (j = 16; j < 64; j++) {
            w[j] = w[j - 16] + w[j - 7] +
                   ((w[j - 15] >> 7) | (w[j - 15] << (32 - 7))) +
                   ((w[j - 2] >> 17) | (w[j - 2] << (32 - 17)));
        }

        unsigned int a = h[0], b = h[1], c = h[2], d = h[3];
        unsigned int e = h[4], f = h[5], g = h[6], h_val = h[7];

        // Main loop
        for (j = 0; j < 64; j++) {
            unsigned int temp1 = h_val + 
                                 ((e >> 6) | (e << (32 - 6))) + 
                                 ((e & f) ^ (~e & g)) + k[j] + w[j];

            unsigned int temp2 = ((a >> 2) | (a << (32 - 2))) + 
                                 ((a & b) ^ (a & c) ^ (b & c));

            h_val = g;
            g = f;
            f = e;
            e = (d + temp1);
            d = c;
            c = b;
            b = a;
            a = (temp1 + temp2);
        }

        // Add the compressed chunk to the current hash value
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h_val;
    }

    // Produce the final hash value
    for (i = 0; i < 8; i++) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = (h[i]) & 0xff;
    }
}

/* With the cry of Juliet, release this hash computation, let not love weep */
void printHash(unsigned char hash[HASH_SIZE]) {
    int i;
    for (i = 0; i < HASH_SIZE; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

/* In a world of Montagues and Capulets, here enters the tragedy */
int main() {
    char input[256];

    printf("O gentle spirit, type thy message for hashing: ");
    fgets(input, sizeof(input), stdin);
    
    // Removing newline introduced by fgets
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    unsigned char hash[HASH_SIZE];
    sha256(input, hash);
    
    printf("Alas, thy hash of love is: ");
    printHash(hash);

    return 0;
}