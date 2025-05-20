//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 16
#define WATERMARK_DATA "This is a watermark"

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_buffer = (unsigned char *) malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Error allocating memory for input buffer.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fread(input_buffer, input_file_size, 1, input_file);
    fclose(input_file);

    int watermark_size_bytes = strlen(WATERMARK_DATA) * sizeof(char);

    unsigned char *watermark_buffer = (unsigned char *) malloc(watermark_size_bytes);
    if (watermark_buffer == NULL) {
        printf("Error allocating memory for watermark buffer.\n");
        free(input_buffer);
        fclose(output_file);
        return 1;
    }

    strcpy((char *) watermark_buffer, WATERMARK_DATA);

    int watermark_position = (int) (input_file_size - watermark_size_bytes);
    int watermark_offset = 0;

    for (int i = 0; i < watermark_size_bytes; i++) {
        input_buffer[watermark_position + i] ^= watermark_buffer[i];
    }

    fwrite(input_buffer, input_file_size, 1, output_file);
    fclose(output_file);

    free(input_buffer);
    free(watermark_buffer);

    printf("Watermarking completed successfully.\n");

    return 0;
}