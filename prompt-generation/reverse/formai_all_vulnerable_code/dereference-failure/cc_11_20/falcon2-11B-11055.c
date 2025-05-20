//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define WATERMARK_SIZE 10
#define WATERMARK_VALUE 0xFF

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");

    if (infile == NULL || outfile == NULL) {
        fprintf(stderr, "Could not open files\n");
        return 1;
    }

    unsigned char watermark[WATERMARK_SIZE];
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = (unsigned char) (rand() % 256);
    }

    fseek(infile, 0, SEEK_END);
    long file_size = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    unsigned char* data = malloc(file_size);
    if (data == NULL) {
        fprintf(stderr, "Could not allocate memory\n");
        return 1;
    }

    long bytes_read = fread(data, 1, file_size, infile);
    if (bytes_read!= file_size) {
        fprintf(stderr, "Could not read entire file\n");
        free(data);
        return 1;
    }

    for (int i = 0; i < file_size; i += WATERMARK_SIZE) {
        if (i + WATERMARK_SIZE > file_size) {
            break;
        }

        memcpy(data + i, watermark, WATERMARK_SIZE);
    }

    fseek(outfile, 0, SEEK_END);
    long watermark_size = ftell(outfile);
    fseek(outfile, 0, SEEK_SET);

    unsigned char watermark_data[watermark_size];
    fread(watermark_data, 1, watermark_size, outfile);

    unsigned char* watermark_copy = malloc(watermark_size);
    if (watermark_copy == NULL) {
        fprintf(stderr, "Could not allocate memory\n");
        return 1;
    }

    memcpy(watermark_copy, watermark_data, watermark_size);

    if (memcmp(watermark, watermark_copy, WATERMARK_SIZE)!= 0) {
        fprintf(stderr, "Watermark verification failed\n");
        free(watermark_copy);
        free(data);
        return 1;
    }

    free(watermark_copy);
    free(data);

    fclose(infile);
    fclose(outfile);

    return 0;
}