//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fread(&image->channels, sizeof(int), 1, file);

    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->channels, sizeof(int), 1, file);
    fwrite(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);
}

void watermark_image(Image *image, const char *watermark, int watermark_size) {
    for (int i = 0; i < watermark_size; i++) {
        for (int j = 0; j < watermark_size; j++) {
            int x = i * image->width / watermark_size;
            int y = j * image->height / watermark_size;
            int offset = (y * image->width + x) * image->channels;
            image->data[offset] = watermark[i * watermark_size + j];
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    int watermark_size = strlen(argv[2]);
    watermark_image(image, argv[2], watermark_size);

    write_image(argv[3], image);
    free(image->data);
    free(image);

    return 0;
}