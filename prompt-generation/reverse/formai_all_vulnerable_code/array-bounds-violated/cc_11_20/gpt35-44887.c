//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define rotate_left(x, n) ((x << n) | (x >> (64 - n)))

// Here is a custom cryptographic hash function example program.

void sha3_512(const uint8_t *input, size_t len, uint8_t output[64]) {
    // Constants for SHA-3
    const uint64_t RC[24] = {
        0x0000000000000001, 0x0000000000008082, 0x800000000000808A, 0x8000000080008000,
        0x000000000000808B, 0x0000000080000001, 0x8000000080008081, 0x8000000000008009,
        0x000000000000008A, 0x0000000000000088, 0x0000000080008009, 0x000000008000000A,
        0x000000008000808B, 0x800000000000008B, 0x8000000000008089, 0x8000000000008003,
        0x8000000000008002, 0x8000000000000080, 0x000000000000800A, 0x800000008000000A,
        0x8000000080008081, 0x8000000000008080, 0x0000000080000001, 0x8000000080008008
    };

    // State variables for SHA-3
    uint64_t state[25] = {0};
    uint64_t message[24] = {0};

    // Temporary variables for SHA-3
    uint64_t temp[5] = {0};

    // Constants for SHA-3
    const uint8_t R[5][5] = {{0, 36, 3, 41, 18},
                             {1, 44, 10, 45, 2},
                             {62, 6, 43, 15, 61},
                             {28, 55, 25, 21, 56},
                             {27, 20, 39, 8, 14}};

    const size_t block_size = 72;
    const size_t num_rounds = 24;

    // Absorb phase
    size_t i;
    uint64_t pos;
    while (len >= block_size) {
        for (i = 0; i < 24; ++i) {
            message[i] = (uint64_t)input[8*i + 0] <<  0
                       | (uint64_t)input[8*i + 1] <<  8
                       | (uint64_t)input[8*i + 2] << 16
                       | (uint64_t)input[8*i + 3] << 24
                       | (uint64_t)input[8*i + 4] << 32
                       | (uint64_t)input[8*i + 5] << 40
                       | (uint64_t)input[8*i + 6] << 48
                       | (uint64_t)input[8*i + 7] << 56;
        }

        for (i = 0; i < 17; ++i) {
            temp[i%5] ^= message[i];
        }

        for (i = 0; i < num_rounds; ++i) {
            pos = R[i%5][0];
            for (size_t j = 0; j < 5; ++j) {
                temp[j] ^= RC[pos];
                pos = R[i%5][(j+1)%5];
            }

            // Theta step
            for (size_t j = 0; j < 5; ++j) {
                state[j] = temp[j]
                         ^ temp[(j+1)%5]
                         ^ temp[(j+2)%5]
                         ^ temp[(j+3)%5]
                         ^ temp[(j+4)%5];
            }

            // Rho and Pi steps
            uint64_t curr = state[1];
            for (size_t j = 0; j < 24; ++j) {
                pos = R[j/5][j%5];
                uint64_t next = state[pos];
                state[pos] = rotate_left(curr, (j + 1) * (j + 2) / 2);
                curr = next;
            }

            // Chi step
            for (size_t j = 0; j < 25; j += 5) {
                for (size_t k = 0; k < 5; ++k) {
                    temp[k] = state[j + k];
                }
                for (size_t k = 0; k < 5; ++k) {
                    state[j + k] ^= (~temp[(k+1)%5]) & temp[(k+2)%5];
                }
            }
            
            // Iota step
            state[0] ^= RC[i];
        }

        input += block_size;
        len -= block_size;
    }

    // Padding
    size_t num_bytes_to_pad = block_size - len;
    uint8_t padded[block_size];
    for (i = 0; i < len; ++i) {
        padded[i] = input[i];
    }
    padded[len] = 0x06;
    memset(&padded[len+1], 0x00, num_bytes_to_pad - 2);
    padded[block_size - 1] = 0x80;

    for (i = 0; i < 24; ++i) {
        message[i] = (uint64_t)padded[8*i + 0] <<  0
                   | (uint64_t)padded[8*i + 1] <<  8
                   | (uint64_t)padded[8*i + 2] << 16
                   | (uint64_t)padded[8*i + 3] << 24
                   | (uint64_t)padded[8*i + 4] << 32
                   | (uint64_t)padded[8*i + 5] << 40
                   | (uint64_t)padded[8*i + 6] << 48
                   | (uint64_t)padded[8*i + 7] << 56;
    }

    for (i = 0; i < 17; ++i) {
        temp[i%5] ^= message[i];
    }

    for (i = 0; i < num_rounds; ++i) {
        pos = R[i%5][0];
        for (size_t j = 0; j < 5; ++j) {
            temp[j] ^= RC[pos];
            pos = R[i%5][(j+1)%5];
        }

        // Theta step
        for (size_t j = 0; j < 5; ++j) {
            state[j] = temp[j]
                     ^ temp[(j+1)%5]
                     ^ temp[(j+2)%5]
                     ^ temp[(j+3)%5]
                     ^ temp[(j+4)%5];
        }

        // Rho and Pi steps
        uint64_t curr = state[1];
        for (size_t j = 0; j < 24; ++j) {
            pos = R[j/5][j%5];
            uint64_t next = state[pos];
            state[pos] = rotate_left(curr, (j + 1) * (j + 2) / 2);
            curr = next;
        }

        // Chi step
        for (size_t j = 0; j < 25; j += 5) {
            for (size_t k = 0; k < 5; ++k) {
                temp[k] = state[j + k];
            }
            for (size_t k = 0; k < 5; ++k) {
                state[j + k] ^= (~temp[(k+1)%5]) & temp[(k+2)%5];
            }
        }

        // Iota step
        state[0] ^= RC[i];
    }

    // Output
    for (i = 0; i < 8; ++i) {
        output[8*i + 0] = (uint8_t)(state[i] >>  0);
        output[8*i + 1] = (uint8_t)(state[i] >>  8);
        output[8*i + 2] = (uint8_t)(state[i] >> 16);
        output[8*i + 3] = (uint8_t)(state[i] >> 24);
        output[8*i + 4] = (uint8_t)(state[i] >> 32);
        output[8*i + 5] = (uint8_t)(state[i] >> 40);
        output[8*i + 6] = (uint8_t)(state[i] >> 48);
        output[8*i + 7] = (uint8_t)(state[i] >> 56);
    }
}

int main() {
    // Test the custom cryptographic hash function
    uint8_t input[10] = "Hello";
    uint8_t output[64] = {0};
    sha3_512(input, 5, output);
    for (int i = 0; i < 64; ++i) {
        printf("%02x ", output[i]);
    }
    printf("\n");

    return 0;
}