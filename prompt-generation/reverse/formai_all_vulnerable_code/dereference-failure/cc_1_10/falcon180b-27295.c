//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 32

typedef struct {
    char* input;
    char hash[HASH_SIZE];
} Hash;

void hash_init(Hash* h) {
    h->input = NULL;
    memset(h->hash, 0, HASH_SIZE);
}

void hash_update(Hash* h, const char* input) {
    size_t input_len = strlen(input);
    if(h->input == NULL) {
        h->input = malloc(input_len + 1);
        memcpy(h->input, input, input_len);
        h->input[input_len] = '\0';
    } else {
        h->input = realloc(h->input, strlen(h->input) + input_len + 1);
        strcat(h->input, input);
    }
}

void hash_final(Hash* h, char* output) {
    unsigned int hash[5];
    unsigned int a, b, c, d, e;
    unsigned int temp;
    size_t input_len = strlen(h->input);

    a = 0x67452301;
    b = 0xefcdab89;
    c = 0x98badcfe;
    d = 0x10325476;
    e = 0xc3d2e1f0;

    for(int i = 0; i < input_len; i += 64) {
        memcpy(&temp, h->input + i, 64);
        temp = temp << 24 | temp >> 8;
        a += temp;
        temp = temp << 16 | temp >> 16;
        b += temp;
        temp = temp << 8 | temp >> 24;
        c += temp;
        temp = temp << 24 | temp >> 8;
        d += temp;
        temp = temp << 16 | temp >> 16;
        e += temp;
    }

    hash[0] = a;
    hash[1] = b;
    hash[2] = c;
    hash[3] = d;
    hash[4] = e;

    for(int i = 0; i < HASH_SIZE; i++) {
        sprintf(output + i*2, "%02x", hash[i]);
    }
}

int main() {
    Hash h;
    char* input = "Hello, world!";
    char hash[HASH_SIZE*2+1];

    hash_init(&h);
    hash_update(&h, input);
    hash_final(&h, hash);

    printf("Input: %s\n", input);
    printf("Hash: %s\n", hash);

    return 0;
}