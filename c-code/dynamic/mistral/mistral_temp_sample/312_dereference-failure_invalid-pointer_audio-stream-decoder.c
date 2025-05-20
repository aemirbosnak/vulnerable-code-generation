#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data[BUFFER_SIZE];
    size_t pos;
} Decoder;

void decode(Decoder* dec) {
    unsigned char* buf = (unsigned char*)malloc(BUFFER_SIZE);
    if (!buf) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    fread(buf, 1, BUFFER_SIZE, stdin);

    dec->data[dec->pos++] = buf[0] + buf[1] + buf[2]; // Invalid pointer arithmetic
    dec->data[dec->pos++] = buf[3] + buf[4] + buf[5]; // Invalid pointer arithmetic

    free(buf);
}

void run_decoder(Decoder* dec) {
    for (;;) {
        decode(dec);
        // Process the decoded data here, or do something useful with it.
    }
}

int main() {
    Decoder dec;
    run_decoder(&dec);

    return 0;
}
