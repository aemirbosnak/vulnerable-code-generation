//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    int max_val;
    unsigned char *data;
} Image;

Image* read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P5\n%d %d\n%d\n", &image->width, &image->height, &image->max_val);

    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, 1, image->width * image->height, fp);

    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "P5\n%d %d\n%d\n", image->width, image->height, image->max_val);

    fwrite(image->data, 1, image->width * image->height, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *input_image = read_image(argv[1]);
    if (input_image == NULL) {
        return 1;
    }

    Image *watermark_image = read_image(argv[2]);
    if (watermark_image == NULL) {
        free(input_image);
        return 1;
    }

    if (input_image->width != watermark_image->width || input_image->height != watermark_image->height) {
        fprintf(stderr, "Error: input image and watermark image must have the same dimensions\n");
        free(input_image);
        free(watermark_image);
        return 1;
    }

    // embed the watermark in the input image
    for (int i = 0; i < input_image->width * input_image->height; i++) {
        input_image->data[i] = input_image->data[i] & watermark_image->data[i];
    }

    write_image(argv[3], input_image);

    free(input_image);
    free(watermark_image);

    return 0;
}