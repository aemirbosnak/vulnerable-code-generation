//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32 // SHA256 outputs a 256-bit hash which is 32 bytes
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))

static const uint32_t k[64] = {
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
    0x19a4c116, 0x1e376c49, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x7760a3e4,
    0x82b2c2f9, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
    0xc67178f2
};

// Function to pad the input string for SHA-256
void pad_message(const unsigned char *msg, uint32_t msg_len, unsigned char *padded_msg, size_t *padded_len) {
    size_t original_byte_len = msg_len;
    size_t original_bit_len = original_byte_len * 8;
    size_t remainder = original_byte_len % 64;
    size_t pad_len = (remainder < 56) ? (56 - remainder) : (120 - remainder);
    
    memcpy(padded_msg, msg, original_byte_len);
    padded_msg[original_byte_len] = 0x80; // Append 1 bit (0x80)
    memset(padded_msg + original_byte_len + 1, 0, pad_len);
    
    // Append to original bit length in bits
    memcpy(padded_msg + original_byte_len + pad_len + 1, &original_bit_len, sizeof(original_bit_len));
    *padded_len = original_byte_len + pad_len + 9; // +8 for bit length (64 bits)
}

// SHA-256 implementation
void sha256(const unsigned char *msg, uint32_t msg_len, unsigned char *hash_output) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    unsigned char padded_msg[128];
    size_t padded_len;
    pad_message(msg, msg_len, padded_msg, &padded_len);

    for (size_t i = 0; i < padded_len; i += 64) {
        uint32_t w[64] = {0};
        for (size_t j = 0; j < 16; j++) {
            w[j] = (padded_msg[i + j * 4] << 24) | (padded_msg[i + j * 4 + 1] << 16) |
                   (padded_msg[i + j * 4 + 2] << 8) | (padded_msg[i + j * 4 + 3]);
        }

        for (size_t j = 16; j < 64; j++) {
            w[j] = ROTR(w[j - 2], 17) ^ ROTR(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] += w[j - 7] + ROTR(w[j - 15], 7) ^ ROTR(w[j - 15], 18) ^ (w[j - 15] >> 3);
            w[j] += w[j - 16];
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h0 = h[7];

        for (size_t j = 0; j < 64; j++) {
            uint32_t t1 = h0 + (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25)) + ((e & f) ^ (~e & g)) + k[j] + w[j];
            uint32_t t2 = (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
            h0 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }

    for (int i = 0; i < 8; i++) {
        hash_output[i * 4] = (h[i] >> 24) & 0xFF;
        hash_output[i * 4 + 1] = (h[i] >> 16) & 0xFF;
        hash_output[i * 4 + 2] = (h[i] >> 8) & 0xFF;
        hash_output[i * 4 + 3] = h[i] & 0xFF;
    }
}

// Function to convert hash output to hexadecimal format
void print_hash(unsigned char *hash_output) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");
}

int main() {
    const char *input_string = "Hello, world! This is a sample input for hashing.";
    unsigned char hash_output[SHA256_BLOCK_SIZE];

    printf("Input: %s\n", input_string);
    sha256((unsigned char *)input_string, strlen(input_string), hash_output);
    printf("SHA-256 Hash: ");
    print_hash(hash_output);

    return 0;
}