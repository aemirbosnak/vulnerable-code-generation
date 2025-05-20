//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64
#define BLOCK_SIZE 16

typedef unsigned char byte;

byte digest[BLOCK_SIZE];

void initialize_digest() {
    memset(digest, 0, BLOCK_SIZE);
}

void update_digest(const byte *data, int len) {
    int i;
    for (i = 0; i < len; i++) {
        digest[i % BLOCK_SIZE] ^= data[i];
    }
}

void final_digest() {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        if (digest[i]!= 0) {
            digest[i] &= 0xff;
        }
    }
}

int main() {
    byte buffer[BUFFER_SIZE];
    int i;

    // Initialize the digest
    initialize_digest();

    // Read input from stdin
    for (i = 0; i < BUFFER_SIZE; i++) {
        scanf("%c", &buffer[i]);
    }

    // Update the digest with the input
    update_digest(buffer, BUFFER_SIZE);

    // Finalize the digest
    final_digest();

    // Print the digest
    printf("Digest: ");
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}