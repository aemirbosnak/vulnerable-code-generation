//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *original;
    char *compressed;
    int original_len;
    int compressed_len;
} compression_t;

void compress(compression_t *c) {
    char *original = c->original;
    char *compressed = c->compressed;
    int original_len = c->original_len;
    int compressed_len = c->compressed_len;

    int i, j;
    for(i = 0, j = 0; i < original_len; i++) {
        if(original[i] == compressed[j]) {
            j++;
        } else {
            compressed[j] = original[i];
            j++;
        }
    }

    compressed_len = j;
    compressed[j] = '\0';
}

void decompress(compression_t *c) {
    char *original = c->original;
    char *compressed = c->compressed;
    int original_len = c->original_len;
    int compressed_len = c->compressed_len;

    int i, j;
    for(i = 0, j = 0; i < compressed_len; i++) {
        if(compressed[i]!= '\0') {
            while(original[j]!= compressed[i]) {
                j++;
            }
            original[j] = compressed[i];
            j++;
        }
    }

    original_len = j;
    original[j] = '\0';
}

int main() {
    char input[1000];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    compression_t c;
    c.original = strdup(input);
    c.compressed = malloc(strlen(input) * 2);
    c.original_len = strlen(input);
    c.compressed_len = 0;

    compress(&c);
    printf("Compressed string: %s\n", c.compressed);

    char decompressed[1000];
    decompressed[0] = '\0';
    decompress(&c);
    strcat(decompressed, c.original);

    printf("Decompressed string: %s\n", decompressed);

    free(c.original);
    free(c.compressed);

    return 0;
}