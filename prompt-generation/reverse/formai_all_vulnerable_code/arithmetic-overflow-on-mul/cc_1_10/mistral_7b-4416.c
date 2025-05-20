//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define BPP 1
#define WATERMARK_BYTE 0x55

typedef uint8_t pixel;

void read_pgm(const char *filename, pixel **data, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    int num_components;

    if (fp == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    fgets(magic_number, sizeof(magic_number), fp);
    magic_number[strlen(magic_number) - 1] = '\0';

    sscanf(magic_number, "P5", &num_components);

    *width = 0;
    *height = 0;

    fscanf(fp, "%d %d", width, height);

    *data = (pixel *) malloc(*width * *height);

    fread(*data, 1, *width * *height, fp);
    fclose(fp);
}

void write_pgm(const char *filename, const pixel *data, int width, int height) {
    FILE *fp = fopen(filename, "wb");

    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(data, 1, width * height, fp);
    fclose(fp);
}

void watermark_image(pixel *image_data, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image_data[i * width + j] += WATERMARK_BYTE / 255.0;
        }
    }
}

void extract_watermark(pixel *image_data, int width, int height) {
    int i, j, sum = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            sum += (image_data[i * width + j] > 127) ? (image_data[i * width + j] - 127) : 0;
        }
    }

    printf("Extracted watermark byte: 0x%02X\n", sum);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.pgm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel *image_data = NULL;
    int width, height;

    read_pgm(argv[1], &image_data, &width, &height);

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Input image dimensions do not match expected dimensions.\n");
        exit(EXIT_FAILURE);
    }

    watermark_image(image_data, width, height);

    char output_filename[32];
    sprintf(output_filename, "watermarked_%s.pgm", argv[1]);

    write_pgm(output_filename, image_data, width, height);

    free(image_data);

    printf("Watermarked image saved as %s.\n", output_filename);

    // Extract watermark from the image_data here
    extract_watermark(image_data, width, height);

    return EXIT_SUCCESS;
}