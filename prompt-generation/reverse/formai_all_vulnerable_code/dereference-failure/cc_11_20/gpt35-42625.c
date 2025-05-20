//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_LEN 10

int main(void) {
    FILE *in, *out;
    char *watermark;
    char watermark_found = 0;
    char byte, water_byte;
    int i, pos, file_len;

    // Open files for input and output
    in = fopen("input_file.txt", "rb");
    out = fopen("output_file.txt", "wb");

    if (in == NULL || out == NULL) {
        printf("Error: could not open files\n");
        return 1;
    }

    // Allocate memory for watermark string
    watermark = malloc(WATERMARK_LEN + 1);
    if (watermark == NULL) {
        printf("Error: could not allocate watermark\n");
        return 1;
    }

    // Generate random watermark
    srand(time(NULL));
    for (i = 0; i < WATERMARK_LEN; i++) {
        watermark[i] = rand() % 256;
    }
    watermark[WATERMARK_LEN] = '\0';

    // Write watermark to output file
    fwrite(watermark, 1, WATERMARK_LEN, out);

    // Copy input file content to output file
    fseek(in, 0L, SEEK_END);
    file_len = ftell(in);
    fseek(in, 0L, SEEK_SET);
    for (i = 0; i < file_len; i++) {
        fread(&byte, 1, 1, in);
        fwrite(&byte, 1, 1, out);
    }

    fclose(in);
    fclose(out);

    // Open output file for reading watermark
    out = fopen("output_file.txt", "rb");
    if (out == NULL) {
        printf("Error: could not open output file for reading watermark\n");
        return 1;
    }

    // Search for watermark in output file
    pos = 0;
    while (!watermark_found && pos < file_len) {
        fread(&water_byte, 1, 1, out);
        for (i = 0; i < WATERMARK_LEN && pos < file_len; i++, pos++) {
            fread(&byte, 1, 1, out);
            if (byte != watermark[i]) {
                break;
            }
        }
        if (i == WATERMARK_LEN) {
            watermark_found = 1;
        }
    }

    if (watermark_found) {
        printf("Watermark found at position %d\n", pos - WATERMARK_LEN);
    } else {
        printf("Watermark not found\n");
    }

    // Free memory and close files
    free(watermark);
    fclose(out);

    return 0;
}