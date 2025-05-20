//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Rotate left operation
#define ROTL(x,n) (((x) << (n)) | ((x) >> (32 - (n))))

// SHA-256 constants
const uint32_t k[64] = 
{
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

// SHA-256 pre-processing
void sha256_preprocess(uint8_t *data, uint64_t length, uint8_t *preprocessed_data, uint64_t *preprocessed_length)
{
    uint64_t bitlen = length * 8;
    uint32_t i, j;
    
    // Padding with 0x80 followed by 0's
    preprocessed_data[0] = 0x80;
    for (i = 1; i < 64 - (length + 9) % 64; i++) {
        preprocessed_data[i] = 0x00;
    }
    
    // Append bit length
    for (j = 0; j < 8; j++) {
        preprocessed_data[i++] = bitlen >> (56 - j * 8);
    }
    
    *preprocessed_length = i;
}

// SHA-256 hash computation
void sha256_hash(uint8_t *message, uint64_t length, uint8_t *hash)
{
    uint32_t i, j, t1, t2, m[64], h[8];
    uint8_t preprocessed_data[128];
    uint64_t preprocessed_length;
    
    // Initialize hash values
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;
    
    // Preprocess the data
    sha256_preprocess(message, length, preprocessed_data, &preprocessed_length);
    
    // Process the message in 512-bit chunks
    for (i = 0; i < preprocessed_length; i += 64) {
        // Initialize message schedule
        for (j = 0; j < 16; j++) {
            m[j] = (preprocessed_data[i + j * 4] << 24) | (preprocessed_data[i + j * 4 + 1] << 16) |
                   (preprocessed_data[i + j * 4 + 2] << 8) | (preprocessed_data[i + j * 4 + 3]);
        }
        for ( ; j < 64; j++) {
            m[j] = m[j-16] + ROTL(m[j-15], 7) + m[j-7] + ROTL(m[j-2], 15);
        }
        
        // Initialize working variables
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], htemp = h[7];
        
        // Compression loop
        for (j = 0; j < 64; j++) {
            t1 = htemp + ROTL(e, 6) + ((e & f) ^ (~e & g)) + k[j] + m[j];
            t2 = ROTL(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
            htemp = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        
        // Update hash values
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += htemp;
    }
    
    // Convert hash to little-endian format
    for (i = 0; i < 8; i++) {
        hash[i * 4] = h[i] >> 24;
        hash[i * 4 + 1] = h[i] >> 16;
        hash[i * 4 + 2] = h[i] >> 8;
        hash[i * 4 + 3] = h[i];
    }
}

int main()
{
    uint8_t message[] = "Hello, world!";
    uint8_t hash[32];
    uint32_t i;
    
    // Compute hash
    sha256_hash(message, strlen((char *) message), hash);
    
    // Output hash
    printf("Hash: ");
    for (i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}