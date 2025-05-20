#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Compressor {
    char *input_data;
    int input_length;
    char *compressed_data;
    int compressed_length;
} Compressor;

void compress(Compressor *compressor) {
    int i, j, k;
    for (i = 0; i < compressor->input_length; i++) {
        j = i + 1;
        while (j < compressor->input_length && compressor->input_data[i] == compressor->input_data[j]) {
            j++;
        }
        compressor->compressed_data[k++] = compressor->input_data[i];
        compressor->compressed_data[k++] = j - i > 9 ? ('0' + (j - i) / 10) : ('A' + (j - i) % 10);
        if (j < compressor->input_length) {
            compressor->compressed_data[k++] = compressor->input_data[j];
        }
    }
    compressor->compressed_length = k;
}

int main() {
    Compressor compressor;
    char input_data[] = "aaabbbcccaaaa";

    compressor.input_data = input_data;
    compressor.input_length = sizeof(input_data) - 1;
    compressor.compressed_data = (char *) malloc(compressor.input_length * 2);
    compress( &compressor );

    printf("Compressed data: %s\n", compressor.compressed_data);

    return 0;
}
