//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x,r) ((x << r) | (x >> (32 - r)))

uint32_t hash(const char* key, uint32_t len) {

    uint32_t h1 = 0xDEADBEEF;
    uint32_t h2 = 0xCAFEBABE;
    uint32_t k1, k2;

    const uint32_t c1 = 0x8F1BBCDC;
    const uint32_t c2 = 0x9E3779B9;

    while (len >= 8) {
        k1 = *(uint32_t*) key;
        k1 = ROTL32(k1, 15);
        k2 = *(uint32_t*) (key + 4);

        h1 ^= k1;
        h1 = ROTL32(h1, 19);
        h1 += h2;
        h1 = h1*5 + 0x6B0D9F5A;

        h2 ^= k2;
        h2 = ROTL32(h2, 13);
        h2 += h1;
        h2 = h2 * 5 + 0x4565ABCD;

        key += 8;
        len -= 8;
    }

    k1 = 0;
    k2 = 0;

    switch(len) {
        case 7: k2 ^= (uint32_t) key[6] << 16;  
        case 6: k2 ^= (uint32_t) key[5] << 8;  
        case 5: k2 ^= (uint32_t) key[4] << 0;
                k2 = ROTL32(k2, 13);
                h2 ^= k2;

        case 4: k1 ^= *(uint32_t*) key;  
                k1 = ROTL32(k1, 15);
                h1 ^= k1;

        case 3: k2 ^= (uint32_t) key[2] << 16;  
        case 2: k2 ^= (uint32_t) key[1] << 8;  
        case 1: k2 ^= (uint32_t) key[0] << 0;
                k2 = ROTL32(k2, 13);
                h2 ^= k2;
    }

    h1 ^= (uint32_t) strlen(key);
    h2 ^= (uint32_t) strlen(key);

    h1 += h2;
    h2 += h1;

    h1 ^= h1 >> 16;
    h1 *= 0x85EBCA6B;
    h1 ^= h1 >> 13;
    h1 *= 0xC2B2AE35;
    h1 ^= h1 >> 16;

    h2 ^= h2 >> 16;
    h2 *= 0x85EBCA6B;
    h2 ^= h2 >> 13;
    h2 *= 0xC2B2AE35;
    h2 ^= h2 >> 16;

    return h1 + h2;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    uint32_t result = hash(str, strlen(str));
    printf("The hash value of %s is %u\n", str, result);

    return 0;
}