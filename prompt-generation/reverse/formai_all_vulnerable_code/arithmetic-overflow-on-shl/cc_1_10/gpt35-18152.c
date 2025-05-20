//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define ROTR(x, y) (((x) >> (y)) | ((x) << (32 - (y))))
#define SWAP(a, b) { a ^= b; b ^= a; a ^= b; }

void sha256_transform(uint32_t *state, const uint8_t *data) {
    uint32_t w[64];
    uint32_t wv[8];
    uint32_t t1, t2;
    const uint8_t *pData = data;

    for (int i = 0; i < 16; ++i) {
        w[i] = (pData[0] << 24) | (pData[1] << 16) | (pData[2] << 8) | pData[3];
        pData += 4;
    }

    for (int i = 16; i < 64; ++i) {
        w[i] = ROTL(w[i - 2], 17) ^ ROTL(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] += w[i - 7];
        w[i] += ROTL(w[i - 15], 7) ^ ROTL(w[i - 15], 18) ^ (w[i - 15] >> 3);
        w[i] += w[i - 16];
    }

    for (int i = 0; i < 8; ++i) {
        wv[i] = state[i];
    }

    for (int i = 0; i < 64; ++i) {
        t1 = wv[7] + (ROTR(wv[4], 6) ^ ROTR(wv[4], 11) ^ ROTR(wv[4], 25)) + ((wv[4] & wv[5]) ^ (~wv[4] & wv[6])) + 0x428a2f98 + w[i];
        t2 = (ROTR(wv[0], 2) ^ ROTR(wv[0], 13) ^ ROTR(wv[0], 22)) + ((wv[0] & wv[1]) ^ (wv[0] & wv[2]) ^ (wv[1] & wv[2]));

        SWAP(wv[7], wv[6]);
        SWAP(wv[6], wv[5]);
        SWAP(wv[5], wv[4]);
        wv[4] += t1;
        SWAP(wv[3], wv[2]);
        SWAP(wv[2], wv[1]);
        SWAP(wv[1], wv[0]);
        wv[0] = t1 + t2;
    }

    for (int i = 0; i < 8; ++i) {
        state[i] += wv[i];
    }
}

void sha256(const uint8_t *data, size_t length, uint8_t *hash) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint8_t buffer[64];
    const uint8_t *pData = data;
    uint32_t size = length, idx;

    while (size > 64) {
        sha256_transform(state, pData);
        pData += 64;
        size -= 64;
    }

    memcpy(buffer, pData, size);

    idx = size;
    buffer[idx++] = 0x80;

    if (idx > 56) {
        memset(&buffer[idx], 0, 64 - idx);
        sha256_transform(state, buffer);
        idx = 0;
    }

    memset(&buffer[idx], 0, 56 - idx);
    buffer[60] = (length >> 24) & 0xff;
    buffer[61] = (length >> 16) & 0xff;
    buffer[62] = (length >> 8) & 0xff;
    buffer[63] = length & 0xff;
    sha256_transform(state, buffer);

    for (int i = 0; i < 8; ++i) {
        hash[i * 4] = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = state[i] & 0xff;
    }
}

int main(int argc, char **argv) {
    uint8_t hash[32] = {0};
    uint8_t data[] = "Hello World!";

    sha256(data, strlen(data), hash);

    printf("Hash: ");
    for (int i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}