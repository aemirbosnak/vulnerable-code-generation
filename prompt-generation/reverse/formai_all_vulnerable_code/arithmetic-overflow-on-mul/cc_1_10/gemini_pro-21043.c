//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    int i, j;
    int watermark_length = strlen(watermark);

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            int bit = (watermark[i] >> j) & 1;
            int pixel_index = i * 8 + j;
            int pixel_component = pixel_index % 3;

            image->data[pixel_index].red   ^= bit << 0;
            image->data[pixel_index].green ^= bit << 1;
            image->data[pixel_index].blue  ^= bit << 2;
        }
    }
}

char *extract_watermark(const Image *image) {
    int i, j;
    int watermark_length = (image->width * image->height) / 8;
    char *watermark = malloc(watermark_length + 1);
    if (!watermark) {
        fprintf(stderr, "Error: could not allocate memory for watermark\n");
        return NULL;
    }

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            int pixel_index = i * 8 + j;
            int pixel_component = pixel_index % 3;
            int bit = (image->data[pixel_index].red   >> 0) & 1;
            bit |= (image->data[pixel_index].green >> 1) & 1;
            bit |= (image->data[pixel_index].blue  >> 2) & 1;
            watermark[i] |= bit << j;
        }
    }

    watermark[watermark_length] = '\0';
    return watermark;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    embed_watermark(image, argv[2]);

    write_image(image, argv[3]);

    free(image->data);
    free(image);

    return EXIT_SUCCESS;
}