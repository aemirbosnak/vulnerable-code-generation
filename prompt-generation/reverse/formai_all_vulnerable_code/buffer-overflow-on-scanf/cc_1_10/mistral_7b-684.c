//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 7
#define PARITY_BITS 3

typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned char parity[PARITY_BITS];
} hamming_code_t;

void hamming_encode(hamming_code_t *code) {
    unsigned char i, p;
    for (i = 0; i < BLOCK_SIZE; i++) {
        code->parity[i] = 0;
        for (p = 0; p < PARITY_BITS && i + p < BLOCK_SIZE; p++)
            code->parity[i + p] ^= code->data[i];
    }
}

int hamming_decode(hamming_code_t *code) {
    unsigned char i, p, e;
    for (i = 0; i < BLOCK_SIZE; i++) {
        for (p = 0; p < PARITY_BITS; p++) {
            e = i + p;
            if (code->data[e] ^ code->parity[p]) {
                code->data[i] ^= (1 << (7 & (i ^ e)));
                code->data[e] ^= (1 << (7 & (i ^ e)));
            }
        }
    }
    return 0;
}

int main() {
    FILE *in, *out;
    char filename[256], buffer[BLOCK_SIZE * 2 + PARITY_BITS];
    hamming_code_t block;

    printf("Enter input file name: ");
    scanf("%s", filename);

    if ((in = fopen(filename, "rb")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    out = fopen("output.bin", "wb");

    while (fread(buffer, sizeof(char), BLOCK_SIZE * 2 + PARITY_BITS, in) > 0) {
        memcpy(block.data, buffer, BLOCK_SIZE);
        hamming_encode(&block);
        memcpy(buffer, &block, sizeof(block));
        fwrite(buffer, sizeof(char), sizeof(block), out);
    }

    fclose(in);
    fclose(out);

    printf("Data recovered successfully.\n");

    return 0;
}