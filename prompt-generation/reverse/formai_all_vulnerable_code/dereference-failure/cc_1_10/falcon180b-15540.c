//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 10
#define WATERMARK_VALUE "ABCDEFGHIJ"

int main(int argc, char *argv[]) {
    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file %s.\n", input_file);
        exit(1);
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file %s.\n", output_file);
        fclose(input);
        exit(1);
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    char *input_buffer = malloc(input_size + 1);
    fread(input_buffer, input_size, 1, input);
    fclose(input);

    char *watermark = malloc(WATERMARK_SIZE + 1);
    memcpy(watermark, WATERMARK_VALUE, WATERMARK_SIZE);

    // Embed watermark in input data
    long watermark_offset = 0;
    while (watermark_offset < input_size) {
        long watermark_size = input_size - watermark_offset;
        if (watermark_size > WATERMARK_SIZE) {
            watermark_size = WATERMARK_SIZE;
        }

        memcpy(input_buffer + watermark_offset, watermark, watermark_size);
        watermark_offset += watermark_size;
    }

    // Write watermarked data to output file
    fwrite(input_buffer, input_size, 1, output);
    fclose(output);

    free(input_buffer);
    free(watermark);

    printf("Watermark embedded successfully.\n");
    return 0;
}