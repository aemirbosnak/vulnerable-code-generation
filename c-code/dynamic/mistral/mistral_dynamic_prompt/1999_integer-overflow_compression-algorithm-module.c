#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 8192

void compress(char *input, char *output) {
    unsigned int freq[256];
    unsigned char *data = (unsigned char *)input;
    unsigned char *out = (unsigned char *)output;
    unsigned int tableSize = 256;

    memset(freq, 0, tableSize * sizeof(unsigned int));

    for (int i = 0; i < BUFFER_SIZE && data[i]; ++i) {
        ++freq[(unsigned char)data[i]];
    }

    for (int i = 0; i < tableSize; ++i) {
        if (freq[i]) {
            *out++ = i;
            *out++ = freq[i] >> 8;
            *out++ = freq[i] & 0xFF;
        }
    }

    unsigned char *ptr = (unsigned char *)malloc(BUFFER_SIZE);
    memcpy(ptr, input, BUFFER_SIZE);

    for (int i = BUFFER_SIZE; i--; ) {
        *out++ = *(ptr + i) - *(out - 3);
    }

    free(ptr);
}

int main() {
    char input[BUFFER_SIZE], output[3 * BUFFER_SIZE];

    fgets(input, sizeof(input), stdin);
    compress(input, output);
    fwrite(output, sizeof(char), strlen(output), stdout);

    return 0;
}
