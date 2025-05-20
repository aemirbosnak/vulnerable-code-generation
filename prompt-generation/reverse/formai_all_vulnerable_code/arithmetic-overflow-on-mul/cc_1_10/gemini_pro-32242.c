//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    fread(&image->channels, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height * image->channels);
    if (image->data == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(&image->channels, sizeof(int), 1, fp);

    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height * image->channels; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i * 3] + image->data[i * 3 + 1] + image->data[i * 3 + 2]) / 3;
        image->data[i * 3] = gray;
        image->data[i * 3 + 1] = gray;
        image->data[i * 3 + 2] = gray;
    }
}

void blur_image(Image *image, int radius) {
    int kernel_size = (2 * radius + 1) * (2 * radius + 1);
    int *kernel = malloc(kernel_size * sizeof(int));
    if (kernel == NULL) {
        return;
    }

    int kernel_index = 0;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            kernel[kernel_index++] = 1;
        }
    }

    Image *blurred_image = malloc(sizeof(Image));
    if (blurred_image == NULL) {
        free(kernel);
        return;
    }

    blurred_image->width = image->width;
    blurred_image->height = image->height;
    blurred_image->channels = image->channels;
    blurred_image->data = malloc(image->width * image->height * image->channels);
    if (blurred_image->data == NULL) {
        free(kernel);
        free(blurred_image);
        return;
    }

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int sum[3] = {0, 0, 0};
            for (int k = -radius; k <= radius; k++) {
                for (int l = -radius; l <= radius; l++) {
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        for (int c = 0; c < image->channels; c++) {
                            sum[c] += image->data[(y * image->width + x) * image->channels + c] * kernel[(k + radius) * (2 * radius + 1) + (l + radius)];
                        }
                    }
                }
            }

            for (int c = 0; c < image->channels; c++) {
                blurred_image->data[(j * image->width + i) * image->channels + c] = sum[c] / kernel_size;
            }
        }
    }

    memcpy(image->data, blurred_image->data, image->width * image->height * image->channels);

    free(kernel);
    free(blurred_image->data);
    free(blurred_image);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image: %s\n", argv[1]);
        return 1;
    }

    // Apply image processing operations here

    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}