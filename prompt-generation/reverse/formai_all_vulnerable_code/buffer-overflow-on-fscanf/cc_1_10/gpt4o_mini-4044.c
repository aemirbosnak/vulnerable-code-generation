//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char **data;
} Image;

Image* read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P5") != 0) {
        printf("Unsupported file format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &image->width, &image->height);

    image->data = (unsigned char **)malloc(image->height * sizeof(unsigned char *));
    for (int i = 0; i < image->height; i++) {
        image->data[i] = (unsigned char *)malloc(image->width * sizeof(unsigned char));
        fread(image->data[i], sizeof(unsigned char), image->width, file);
    }

    fclose(file);
    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        fwrite(image->data[i], sizeof(unsigned char), image->width, file);
    }

    fclose(file);
}

void embed_watermark(Image *image, const unsigned char *watermark, int wm_width, int wm_height) {
    int wm_index = 0;
    for (int y = 0; y < image->height && wm_index < wm_width * wm_height; y += 2) {
        for (int x = 0; x < image->width && wm_index < wm_width * wm_height; x += 2) {
            unsigned char pixel = image->data[y][x];
            pixel = (pixel & 0xFE) | (watermark[wm_index] ? 1 : 0); // Embed watermark bit
            image->data[y][x] = pixel;
            wm_index++;
        }
    }
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

int main() {
    Image *image = read_image("input.pgm");
    if (image == NULL) {
        return 1;
    }

    // Simple binary watermark
    unsigned char watermark[] = { 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0 };
    int wm_width = 4;
    int wm_height = 4;

    embed_watermark(image, watermark, wm_width, wm_height);
    write_image("output.pgm", image);
    free_image(image);

    printf("Watermark embedded and saved to 'output.pgm'\n");
    return 0;
}