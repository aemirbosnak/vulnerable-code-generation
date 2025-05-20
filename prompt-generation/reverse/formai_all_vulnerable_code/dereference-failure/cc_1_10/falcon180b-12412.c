//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: watermark <input_file> <output_file>\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error opening input file %s\n", input_file);
        return 1;
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error opening output file %s\n", output_file);
        fclose(input_fp);
        return 1;
    }

    fseek(input_fp, 0, SEEK_END);
    long input_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    char *input_buffer = malloc(input_size + 1);
    fread(input_buffer, input_size, 1, input_fp);
    fclose(input_fp);

    char *watermark = "Digital Watermarking";
    int watermark_size = strlen(watermark);

    char *output_buffer = malloc(input_size + watermark_size + 1);
    int watermark_index = 0;
    int output_index = 0;

    for (int i = 0; i < input_size; i++) {
        if (i % (MAX_SIZE / 2) == 0) {
            output_buffer[output_index++] = 'W';
        }
        output_buffer[output_index++] = input_buffer[i];

        if (i % (MAX_SIZE / 2) == MAX_SIZE / 2 - 1) {
            output_buffer[output_index++] = 'W';
        }
    }

    for (int i = 0; i < watermark_size; i++) {
        output_buffer[output_index++] = watermark[i];
    }

    output_buffer[output_index] = '\0';

    fwrite(output_buffer, output_index, 1, output_fp);
    fclose(output_fp);

    printf("Watermarking completed successfully!\n");

    return 0;
}