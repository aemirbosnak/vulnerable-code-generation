//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
// C Modern Encryption Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32
#define ROUNDS 20

typedef unsigned char byte;
typedef unsigned int uint;

// Constants for key expansion
const uint rcon[ROUNDS] = {
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1B000000, 0x36000000,
    0x6C000000, 0xD8000000, 0xAB000000, 0x4D000000, 0x9A000000, 0x2F000000, 0x5E000000, 0xBC000000, 0x63000000, 0xC6000000
};
const byte sbox[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    /* Rest of the sbox */
    0x9E, 0xFA, 0xEC, 0x0D, 0x6D, 0x45, 0x9A, 0xE3, 0xAA, 0xF1, 0x25, 0x8F, 0xF8, 0x80, 0x0F, 0x8D,
};
const byte invsbox[256] = {
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    /* Rest of the invsbox */
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
};

// Functions for encryption and decryption
void encrypt(byte *plaintext, byte *key, byte *ciphertext) {
    uint i, j, round = 0;
    uint w[4 * (ROUNDS + 1)];

    // Key expansion
    for (i = 0; i < KEY_SIZE / 8; i++)
        w[i] = (key[4 * i] << 24) | (key[4 * i + 1] << 16) | (key[4 * i + 2] << 8) | key[4 * i + 3];

    for (i = 4; i < 4 * (ROUNDS + 1); i++) {
        uint temp = w[i - 1];
        if (i % 4 == 0) {
            temp = (sbox[(temp >> 8) & 0xff] << 24) | (sbox[(temp >> 16) & 0xff] << 16)
                 | (sbox[(temp >> 24) & 0xff] << 8)  | sbox[temp & 0xff];
            temp ^= rcon[i / 4 - 1];
        }
        w[i] = w[i - 4] ^ temp;
    }

    // Initial round
    for (i = 0; i < BLOCK_SIZE / 4; i++)
        ((uint *)ciphertext)[i] = ((uint *)plaintext)[i] ^ w[i];

    // Main rounds
    for (i = BLOCK_SIZE / 4; i < 4 * (ROUNDS - 1) + BLOCK_SIZE / 4; i++) {
        byte state[4];
        for (j = 0; j < 4; j++)
            state[j] = (ciphertext[4 * i - 15 + j] << 24 >> 24);
        state[0] = sbox[state[0] & 0xff];
        state[1] = sbox[state[1] & 0xff];
        state[2] = sbox[state[2] & 0xff];
        state[3] = sbox[state[3] & 0xff];
        for (j = 0; j < 4; j++)
            ((uint *)ciphertext)[i] ^= state[j] << (24 - 8 * j);

        ((uint *)ciphertext)[i] ^= ((uint *)ciphertext)[i - BLOCK_SIZE / 4] ^ w[i];
    }

    // Final round
    for (i = 0; i < BLOCK_SIZE / 4; i++)
        ((uint *)ciphertext)[4 * ROUNDS - BLOCK_SIZE / 4 + i] = ((uint *)ciphertext)[4 * ROUNDS - BLOCK_SIZE / 4 + i - BLOCK_SIZE / 4] ^ w[4 * ROUNDS - BLOCK_SIZE / 4 + i];

}

void decrypt(byte *ciphertext, byte *key, byte *plaintext) {
    uint i, j, round = 0;
    uint w[4 * (ROUNDS + 1)];

    // Key expansion
    for (i = 0; i < KEY_SIZE / 8; i++)
        w[i] = (key[4 * i] << 24) | (key[4 * i + 1] << 16) | (key[4 * i + 2] << 8) | key[4 * i + 3];

    for (i = 4; i < 4 * (ROUNDS + 1); i++) {
        uint temp = w[i - 1];
        if (i % 4 == 0) {
            temp = (sbox[(temp >> 8) & 0xff] << 24) | (sbox[(temp >> 16) & 0xff] << 16)
                 | (sbox[(temp >> 24) & 0xff] << 8)  | sbox[temp & 0xff];
            temp ^= rcon[i / 4 - 1];
        }
        w[i] = w[i - 4] ^ temp;
    }

    // Initial round
    for (i = 0; i < BLOCK_SIZE / 4; i++)
        ((uint *)plaintext)[i] = ((uint *)ciphertext)[i] ^ w[4 * ROUNDS - BLOCK_SIZE / 4 + i];

    // Main rounds
    for (i = BLOCK_SIZE / 4; i < 4 * (ROUNDS - 1) + BLOCK_SIZE / 4; i++) {
        byte state[4];
        for (j = 0; j < 4; j++)
            state[j] = (plaintext[4 * i - 15 + j] << 24 >> 24);
        state[0] = invsbox[state[0] & 0xff];
        state[1] = invsbox[state[1] & 0xff];
        state[2] = invsbox[state[2] & 0xff];
        state[3] = invsbox[state[3] & 0xff];
        for (j = 0; j < 4; j++)
            ((uint *)plaintext)[i] ^= state[j] << (24 - 8 * j);

        ((uint *)plaintext)[i] ^= ((uint *)ciphertext)[i - BLOCK_SIZE / 4] ^ w[i];
    }

    // Final round
    for (i = 0; i < BLOCK_SIZE / 4; i++)
        ((uint *)plaintext)[4 * ROUNDS - BLOCK_SIZE / 4 + i] = ((uint *)plaintext)[4 * ROUNDS - BLOCK_SIZE / 4 + i - BLOCK_SIZE / 4] ^ w[i];

}

int main() {
    byte key[KEY_SIZE / 8] = {0};
    byte plaintext[BLOCK_SIZE] = {0};
    byte ciphertext[BLOCK_SIZE] = {0};
    byte decryptedtext[BLOCK_SIZE] = {0};
    uint i;

    srand(time(NULL));

    // Generate random key and plaintext
    for (i = 0; i < KEY_SIZE / 8; i++)
        key[i] = rand() % 256;
    for (i = 0; i < BLOCK_SIZE; i++)
        plaintext[i] = rand() % 256;

    // Encrypt and decrypt
    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decryptedtext);

    // Print results
    printf("Key:\n");
    for (i = 0; i < KEY_SIZE / 8; i++)
        printf("%02X ", key[i]);
    printf("\n\nPlaintext:\n");
    for (i = 0; i < BLOCK_SIZE; i++)
        printf("%02X ", plaintext[i]);
    printf("\n\nCiphertext:\n");
    for (i = 0; i < BLOCK_SIZE; i++)
        printf("%02X ", ciphertext[i]);
    printf("\n\nDecryptedtext:\n");
    for (i = 0; i < BLOCK_SIZE; i++)
        printf("%02X ", decryptedtext[i]);
    printf("\n");

    return 0;
}