//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

void shimmer_hash(const void *key, int len, uint32_t seed, void *out)
{
    const uint8_t *data = (const uint8_t *)key;
    const int nblocks = len / 4;

    uint32_t hash = seed;
    uint32_t block;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    const uint32_t *blocks = (const uint32_t *)(data + nblocks * 4);
    for (int i = -nblocks; i; i++) {
        block = (i < 0) ? seed : blocks[i];
        block = block ^ ROTL(block, 15);
        block = block * c1;
        block = block ^ ROTL(block, 13);
        block = block * c2;
        hash = hash ^ block;
        hash = ROTL(hash, 7);
        hash = hash * 5 + 0xe6546b64;
    }

    const uint8_t *tail = (const uint8_t *)(data + nblocks * 4);
    uint32_t k1 = 0;
    switch (len & 3) {
      case 3: k1 ^= tail[2] << 16;
      case 2: k1 ^= tail[1] << 8;
      case 1: k1 ^= tail[0];
              k1 *= c1;
              k1 = ROTL(k1, 15);
              k1 *= c2;
              hash ^= k1;
    }

    hash ^= len;
    hash ^= hash >> 16;
    hash *= 0x85ebca6b;
    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;
    hash ^= hash >> 16;

    *(uint32_t *)out = hash;
}

int main()
{
    char message[100];
    uint32_t hash_result;

    printf("Enter message to hash: ");
    fgets(message, 100, stdin);
    message[strlen(message) - 1] = '\0';

    shimmer_hash(message, strlen(message), 0, &hash_result);

    printf("Hash result: %x\n", hash_result);

    return 0;
}