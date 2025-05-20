//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function to compress a string using the Run-Length Encoding (RLE) algorithm
 * Input: uncompressed string
 * Output: compressed string
 */
char* rle_compress(char* uncompressed) {
    int i, j, count = 1;
    char* compressed = NULL;

    for (i = 0; uncompressed[i]!= '\0'; i++) {
        if (uncompressed[i] == uncompressed[i+1]) {
            count++;
        } else {
            if (count > 1) {
                sprintf(&compressed[strlen(compressed)], "%d%c", count, uncompressed[i]);
            } else {
                sprintf(&compressed[strlen(compressed)], "%c", uncompressed[i]);
            }
            count = 1;
        }
    }

    if (count > 1) {
        sprintf(&compressed[strlen(compressed)], "%d%c", count, uncompressed[i-1]);
    } else {
        sprintf(&compressed[strlen(compressed)], "%c", uncompressed[i-1]);
    }

    return compressed;
}

/*
 * Function to decompress a string using the Run-Length Encoding (RLE) algorithm
 * Input: compressed string
 * Output: uncompressed string
 */
char* rle_decompress(char* compressed) {
    int i, j, count = 0;
    char* uncompressed = NULL;

    for (i = 0; compressed[i]!= '\0'; i++) {
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            count = compressed[i] - '0';
            i++;
        } else if (compressed[i] == '%') {
            count = 1;
        } else {
            fprintf(stderr, "Invalid compressed string\n");
            exit(1);
        }

        for (j = 0; j < count; j++) {
            if (compressed[i] == '%') {
                strcat(uncompressed, &compressed[i+1]);
            } else {
                strcat(uncompressed, &compressed[i]);
            }
        }
    }

    return uncompressed;
}

int main() {
    char* uncompressed = "aaabbbbbcccddddeeeeeefffffgggg";
    char* compressed = rle_compress(uncompressed);
    char* decompressed = rle_decompress(compressed);

    printf("Uncompressed string: %s\n", uncompressed);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}