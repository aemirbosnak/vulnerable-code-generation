//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *original;
    char *compressed;
    int original_length;
    int compressed_length;
} compression_result;

compression_result compress(char *input) {
    int i, j;
    char *output = malloc(strlen(input) * 2 + 1);
    int output_length = 0;
    int count = 1;

    for (i = 0; input[i]!= '\0'; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            count++;
        } else {
            sprintf(&output[output_length], "%d%c", count, input[i]);
            output_length += strlen(&output[output_length]);
            count = 1;
        }
    }

    compression_result result;
    result.original = input;
    result.compressed = output;
    result.original_length = strlen(input);
    result.compressed_length = output_length;

    return result;
}

void decompress(compression_result result) {
    int i, j;
    char *output = malloc(result.original_length + 1);
    int output_length = 0;

    for (i = 0; result.compressed[i]!= '\0'; i += 2) {
        int count = result.compressed[i] - '0';
        strncat(output, &result.compressed[i + 1], count);
        output_length += count;
    }

    printf("Original: %s\n", result.original);
    printf("Compressed: %s\n", result.compressed);
    printf("Decompressed: %s\n", output);
    printf("Original length: %d\n", result.original_length);
    printf("Compressed length: %d\n", result.compressed_length);
    printf("Decompressed length: %d\n", output_length);
}

int main() {
    char input[1000];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    compression_result result = compress(input);
    decompress(result);

    return 0;
}