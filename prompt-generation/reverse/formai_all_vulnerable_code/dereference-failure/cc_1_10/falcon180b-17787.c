//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *original;
    char *compressed;
    int original_length;
    int compressed_length;
} CompressionResult;

CompressionResult compress(char *input) {
    int input_length = strlen(input);
    int i, j;
    char *compressed = malloc(input_length + 1);
    compressed[input_length] = '\0';
    for (i = 0, j = 0; i < input_length; i++) {
        if (i == 0 || input[i]!= input[i-1]) {
            compressed[j++] = input[i];
        }
    }
    CompressionResult result = {input, compressed, input_length, j};
    return result;
}

void decompress(char *compressed, char *output) {
    int compressed_length = strlen(compressed);
    int i = 0, j = 0;
    while (i < compressed_length) {
        int count = 1;
        while (i < compressed_length && compressed[i] == compressed[i-1]) {
            count++;
            i++;
        }
        for (int k = 0; k < count; k++) {
            output[j++] = compressed[i];
            i++;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1000];
    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    CompressionResult result = compress(input);
    printf("Original string: %s\n", result.original);
    printf("Compressed string: %s\n", result.compressed);
    printf("Compression ratio: %.2f\n", (float)result.original_length / result.compressed_length);

    char output[1000];
    decompress(result.compressed, output);
    printf("Decompressed string: %s\n", output);

    return 0;
}