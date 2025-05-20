//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

unsigned char *image;
int width, height, channels;

void load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s", filename);
        exit(1);
    }
    fscanf(file, "P%d %d %d\n", &channels, &width, &height);
    image = malloc(width * height * channels);
    fread(image, width * height * channels, 1, file);
    fclose(file);
}

void save_image(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s", filename);
        exit(1);
    }
    fprintf(file, "P%d %d %d\n", channels, width, height);
    fwrite(image, width * height * channels, 1, file);
    fclose(file);
}

void flip_image_horizontal() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int k = 0; k < channels; k++) {
                unsigned char temp = image[i * width * channels + j * channels + k];
                image[i * width * channels + j * channels + k] = image[i * width * channels + (width - j - 1) * channels + k];
                image[i * width * channels + (width - j - 1) * channels + k] = temp;
            }
        }
    }
}

void flip_image_vertical() {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                unsigned char temp = image[i * width * channels + j * channels + k];
                image[i * width * channels + j * channels + k] = image[(height - i - 1) * width * channels + j * channels + k];
                image[(height - i - 1) * width * channels + j * channels + k] = temp;
            }
        }
    }
}

void adjust_brightness(int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                int pixel = image[i * width * channels + j * channels + k] + value;
                if (pixel < 0) {
                    pixel = 0;
                } else if (pixel > 255) {
                    pixel = 255;
                }
                image[i * width * channels + j * channels + k] = pixel;
            }
        }
    }
}

void adjust_contrast(int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                int pixel = (image[i * width * channels + j * channels + k] - 128) * value + 128;
                if (pixel < 0) {
                    pixel = 0;
                } else if (pixel > 255) {
                    pixel = 255;
                }
                image[i * width * channels + j * channels + k] = pixel;
            }
        }
    }
}

int main() {
    load_image("input.ppm");
    flip_image_horizontal();
    adjust_brightness(50);
    adjust_contrast(1.2);
    save_image("output.ppm");
    return 0;
}