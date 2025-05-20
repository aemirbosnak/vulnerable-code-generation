//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50

void flip_image_horizontally(unsigned char *image, int height, int width, int channels) {
    unsigned char *temp_row = malloc(width * channels);
    for (int i = 0; i < height/2; i++) {
        memcpy(temp_row, image + i * width * channels, width * channels);
        memcpy(image + i * width * channels, image + (height - i - 1) * width * channels, width * channels);
        memcpy(image + (height - i - 1) * width * channels, temp_row, width * channels);
    }
    free(temp_row);
}

void flip_image_vertically(unsigned char *image, int height, int width, int channels) {
    unsigned char *temp_row = malloc(width * channels);
    for (int i = 0; i < width/2; i++) {
        for (int j = 0; j < height; j++) {
            memcpy(temp_row, image + j * width * channels + i * channels, channels);
            memcpy(image + j * width * channels + i * channels, image + j * width * channels + (width - i - 1) * channels, channels);
            memcpy(image + j * width * channels + (width - i - 1) * channels, temp_row, channels);
        }
    }
    free(temp_row);
}

void adjust_brightness(unsigned char *image, int size, int adjustment) {
    for (int i = 0; i < size; i++) {
        int value = (int)image[i] + adjustment;
        if (value > 255) {
            image[i] = 255;
        } else if (value < 0) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)value;
        }
    }
}

void adjust_contrast(unsigned char *image, int size, float factor) {
    for (int i = 0; i < size; i++) {
        int value = (int)(factor * (int)image[i] + 0.5);
        if (value > 255) {
            image[i] = 255;
        } else if (value < 0) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)value;
        }
    }
}

void read_image_data(char *filename, unsigned char **image, int *height, int *width, int *channels) {
    char header[4];
    int max_value;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return;
    }
    fscanf(fp, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        printf("Error: Unsupported file format\n");
        fclose(fp);
        return;
    }
    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &max_value);
    if (max_value != 255) {
        printf("Error: Unsupported pixel format\n");
        fclose(fp);
        return;
    }
    *channels = 3;
    int size = (*height) * (*width) * (*channels);
    *image = malloc(size);
    fread(*image, sizeof(unsigned char), size, fp);
    fclose(fp);
}

void write_image_data(char *filename, unsigned char *image, int height, int width, int channels) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");
    fwrite(image, sizeof(unsigned char), height * width * channels, fp);
    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter filename with extension: ");
    scanf("%s", filename);
    unsigned char *image;
    int height, width, channels;
    read_image_data(filename, &image, &height, &width, &channels);
    printf("Image loaded successfully\n");

    // Flip image horizontally
    flip_image_horizontally(image, height, width, channels);
    printf("Image flipped horizontally\n");
    write_image_data("horizontal_flip.ppm", image, height, width, channels);

    // Flip image vertically
    flip_image_vertically(image, height, width, channels);
    printf("Image flipped vertically\n");
    write_image_data("vertical_flip.ppm", image, height, width, channels);

    // Adjust brightness
    int adjustment;
    printf("Enter brightness adjustment (-255 to 255): ");
    scanf("%d", &adjustment);
    adjust_brightness(image, height * width * channels, adjustment);
    printf("Brightness adjusted\n");
    write_image_data("brightness_adjust.ppm", image, height, width, channels);

    // Adjust contrast
    float factor;
    printf("Enter contrast adjustment (0 to 10): ");
    scanf("%f", &factor);
    adjust_contrast(image, height * width * channels, factor);
    printf("Contrast adjusted\n");
    write_image_data("contrast_adjust.ppm", image, height, width, channels);

    free(image);
    return 0;
}