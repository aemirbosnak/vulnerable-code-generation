//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define initial values for the SHA-256 hash
uint32_t hash[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

// Define a macro for the SHA-256 "sigma 0" function
#define SHA256_SIGMA_0(x) (ROTR(2,x) ^ ROTR(13,x) ^ ROTR(22,x))

// Define a macro for the SHA-256 "sigma 1" function
#define SHA256_SIGMA_1(x) (ROTR(6,x) ^ ROTR(11,x) ^ ROTR(25,x))

// Define a macro for the SHA-256 "ROTR" function
#define ROTR(n,x) ((x >> n) | (x << (32 - n)))

// Define a function to perform a single SHA-256 round
void sha256_round(uint32_t *h, uint32_t *w, int round) {
    // Define temporary variables for the SHA-256 hash values
    uint32_t a = h[0];
    uint32_t b = h[1];
    uint32_t c = h[2];
    uint32_t d = h[3];
    uint32_t e = h[4];
    uint32_t f = h[5];
    uint32_t g = h[6];
    uint32_t h_old = h[7];

    // Define the SHA-256 round constants
    const uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Fill the message schedule from the input message
    for (int i = 0; i < 16; i++) {
        w[i] = be32toh(w[i]);
    }
    for (int i = 16; i < 64; i++) {
        w[i] = SHA256_SIGMA_1(w[i - 2]) + w[i - 7] + SHA256_SIGMA_0(w[i - 15]) + w[i - 16];
    }

    // Perform the SHA-256 round operations
    for (int i = 0; i < 64; i++) {
        uint32_t t1 = h_old + SHA256_SIGMA_1(e) + ((e & f) ^ (~e & g)) + k[i] + w[i];
        uint32_t t2 = SHA256_SIGMA_0(a) + ((a & b) ^ (a & c) ^ (b & c));

        h_old = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;

    }

    // Update the SHA-256 hash values
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h_old;

    // Clear the message schedule
    for (int i = 0; i < 64; i++) {
        w[i] = 0;
    }

}

// Define a function to compute the SHA-256 hash of a message
void sha256(uint32_t *hash, uint8_t *message, size_t length) {
    // Define variables to store the message length and the number of padding bytes
    uint64_t message_length = length * 8;
    size_t padding_bytes = 64 - ((length + 8) % 64);

    // Allocate a buffer for the padded message
    size_t padded_length = length + padding_bytes + 8;
    uint8_t *padded_message = calloc(padded_length, sizeof(uint8_t));
    if (!padded_message) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    // Copy the original message to the padded message buffer
    for (int i = 0; i < length; i++) {
        padded_message[i] = message[i];
    }

    // Add the padding bytes to the padded message buffer
    padded_message[length] = 0x80;
    for (int i = length + 1; i < padded_length - 8; i++) {
        padded_message[i] = 0x00;
    }

    // Append the message length to the padded message buffer
    padded_message[padded_length - 8] = message_length >> 56;
    padded_message[padded_length - 7] = message_length >> 48;
    padded_message[padded_length - 6] = message_length >> 40;
    padded_message[padded_length - 5] = message_length >> 32;
    padded_message[padded_length - 4] = message_length >> 24;
    padded_message[padded_length - 3] = message_length >> 16;
    padded_message[padded_length - 2] = message_length >> 8;
    padded_message[padded_length - 1] = message_length;

    // Break the padded message into 512-bit chunks and compute the SHA-256 hash for each chunk
    uint32_t w[64] = {0};
    for (int i = 0; i < padded_length; i += 64) {
        for (int j = 0; j < 16; j++) {
            w[j] = (padded_message[i + (j * 4)] << 24) |
                   (padded_message[i + (j * 4) + 1] << 16) |
                   (padded_message[i + (j * 4) + 2] << 8) |
                   padded_message[i + (j * 4) + 3];
        }
        for (int j = 16; j < 64; j++) {
            w[j] = 0;
        }

        for (int j = 0; j < 64; j++) {
            sha256_round(hash, w, j);
        }
    }
}

int main() {
    // Define a message to hash
    uint8_t message[] = "this is a test message for the SHA-256 hash function";

    // Compute the SHA-256 hash of the message
    sha256(hash, message, sizeof(message) - 1);

    // Print the resulting hash value
    printf("SHA-256 hash value:");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}