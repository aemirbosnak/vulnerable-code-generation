//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    float *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * sizeof(float));
    image->width = width;
    image->height = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(fp, "%f", &image->data[y * width + x]);
        }
    }

    fclose(fp);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fprintf(fp, "%d %d\n", image->width, image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(fp, "%f ", image->data[y * image->width + x]);
        }
    }

    fclose(fp);
}

Image *watermark_image(const Image *image, const char *watermark) {
    int watermark_width = strlen(watermark);
    int watermark_height = 1;

    Image *watermarked_image = malloc(sizeof(Image));
    watermarked_image->data = malloc(image->width * image->height * sizeof(float));
    watermarked_image->width = image->width;
    watermarked_image->height = image->height;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            watermarked_image->data[y * image->width + x] = image->data[y * image->width + x];

            if (x >= image->width / 2 - watermark_width / 2 && x <= image->width / 2 + watermark_width / 2 &&
                y >= image->height / 2 - watermark_height / 2 && y <= image->height / 2 + watermark_height / 2) {
                watermarked_image->data[y * image->width + x] += 0.1 * sin(2 * PI * (x - image->width / 2 + watermark_width / 2) / watermark_width) * watermark[x - image->width / 2 + watermark_width / 2];
            }
        }
    }

    return watermarked_image;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    Image *watermarked_image = watermark_image(image, argv[2]);
    if (!watermarked_image) {
        return 1;
    }

    save_image(watermarked_image, argv[3]);

    free(image->data);
    free(image);

    free(watermarked_image->data);
    free(watermarked_image);

    return 0;
}