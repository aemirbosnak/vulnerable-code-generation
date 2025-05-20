//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *original;
    char *compressed;
    int original_length;
    int compressed_length;
} CompressionResult;

CompressionResult compress(char *input) {
    int i, j, run_length = 1;
    char *output = malloc(MAX_LENGTH * sizeof(char));
    int output_length = 0;

    for (i = 0; input[i]!= '\0'; i++) {
        if (input[i] == input[i + 1]) {
            run_length++;
        } else {
            sprintf(&output[output_length], "%d%c", run_length, input[i]);
            output_length += strlen(&output[output_length]);
            run_length = 1;
        }
    }

    sprintf(&output[output_length], "%d%c", run_length, input[i - 1]);
    output_length += strlen(&output[output_length]);

    CompressionResult result = {input, output, strlen(input), output_length};
    return result;
}

void decompress(CompressionResult result) {
    int i = 0, j = 0;

    while (i < result.original_length && j < result.compressed_length) {
        int run_length = result.compressed[j] - '0';
        while (run_length-- > 0 && i < result.original_length) {
            result.original[i++] = result.original[j++];
        }
        if (result.original[i - 1]!= result.compressed[j]) {
            result.original[i++] = result.compressed[j++];
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    CompressionResult result = compress(input);
    printf("Compressed string: %s\n", result.compressed);
    printf("Compression ratio: %.2f\n", (float)result.original_length / result.compressed_length);

    char decompressed[MAX_LENGTH];
    decompress(result);
    printf("Decompressed string: %s\n", decompressed);

    free(result.compressed);
    free(result.original);

    return 0;
}