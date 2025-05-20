//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIZE 512
#define WATERMARK_SIZE 64
#define KEY 0xdeadbeef

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <watermark_file>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: could not open image file.\n");
        return 1;
    }

    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        printf("Error: could not open watermark file.\n");
        return 1;
    }

    unsigned char *image_data = (unsigned char *) malloc(IMAGE_SIZE * IMAGE_SIZE * 3);
    if (image_data == NULL) {
        printf("Error: could not allocate memory for image data.\n");
        return 1;
    }

    unsigned char *watermark_data = (unsigned char *) malloc(WATERMARK_SIZE * WATERMARK_SIZE * 3);
    if (watermark_data == NULL) {
        printf("Error: could not allocate memory for watermark data.\n");
        return 1;
    }

    fread(image_data, IMAGE_SIZE * IMAGE_SIZE * 3, 1, image_file);
    fread(watermark_data, WATERMARK_SIZE * WATERMARK_SIZE * 3, 1, watermark_file);

    fclose(image_file);
    fclose(watermark_file);

    int i, j, k;
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            int x = (i / (IMAGE_SIZE / WATERMARK_SIZE)) * WATERMARK_SIZE;
            int y = (j / (IMAGE_SIZE / WATERMARK_SIZE)) * WATERMARK_SIZE;

            if ((i % (IMAGE_SIZE / WATERMARK_SIZE)) == 0 && (j % (IMAGE_SIZE / WATERMARK_SIZE)) == 0) {
                for (k = 0; k < 3; k++) {
                    image_data[(i * IMAGE_SIZE + j) * 3 + k] = watermark_data[x * WATERMARK_SIZE + y * 3 + k];
                }
            }
        }
    }

    FILE *output_file = fopen("watermarked_image.bmp", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    fwrite(image_data, IMAGE_SIZE * IMAGE_SIZE * 3, 1, output_file);

    fclose(output_file);

    free(image_data);
    free(watermark_data);

    return 0;
}