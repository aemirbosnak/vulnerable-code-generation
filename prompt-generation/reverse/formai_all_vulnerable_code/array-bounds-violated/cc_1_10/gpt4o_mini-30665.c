//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 constants
static const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x27c6e4f3,
    0x6ca6351,  0x14292967, 0x27b70a85, 0x2e1b2138,
    0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb,
    0x81c2c92e, 0x27c6e4f3, 0x6ca6351,  0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x27c6e4f3
};

// Right rotate function
uint32_t right_rotate(uint32_t value, int amount) {
    return (value >> amount) | (value << (32 - amount));
}

// SHA-256 hash function
void sha256(const uint8_t *data, size_t len, uint32_t *hash) {
    uint32_t w[64];
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
   
    uint64_t bit_len = len * 8;
    
    size_t new_len = len + 1 + (56 - (len + 1) % 64) % 64;
    uint8_t *msg = malloc(new_len + 8);
    if (!msg) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    memcpy(msg, data, len);
    msg[len] = 0x80; // Append the bit '1' to the message
    memset(msg + len + 1, 0, new_len - len - 1);
    
    for (int i = 0; i < 8; i++) {
        msg[new_len + i] = (bit_len >> (56 - i * 8)) & 0xff;
    }

    for (size_t i = 0; i < new_len / 64; i++) {
        memcpy(w, msg + i * 64, 64);
        for (int j = 0; j < 16; j++) {
            w[j] = (w[j * 4] << 24) | (w[j * 4 + 1] << 16) |
                   (w[j * 4 + 2] << 8) | (w[j * 4 + 3]);
        }
        
        for (int j = 16; j < 64; j++) {
            w[j] = right_rotate(w[j - 2], 17) ^ right_rotate(w[j - 2], 19) ^ (w[j - 7]) +
                   w[j - 16] ^ right_rotate(w[j - 15], 7) ^ right_rotate(w[j - 15], 18);
        }

        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h0 = h[7];

        for (int j = 0; j < 64; j++) {
            uint32_t temp1 = h0 + (right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25)) + 
                             ((e & f) ^ (~e & g)) + K[j] + w[j];
            uint32_t temp2 = (right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22)) + 
                             ((a & b) ^ (a & c) ^ (b & c));
            
            h0 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
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
        hash[i] = h[i];
    }

    free(msg);
}

// Main function
int main(void) {
    char input[256];
    printf("Enter a message to hash: ");
    fgets(input, sizeof(input), stdin);
    
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';  // Remove newline character
        len--;
    }

    uint32_t hash[8];
    sha256((uint8_t *)input, len, hash);
    
    printf("SHA-256 hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}