//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

// Function to flip an image
void flip_image(int width, int height, int channels, unsigned char *image)
{
    int i, j;
    unsigned char *temp;

    temp = (unsigned char*)malloc(sizeof(unsigned char) * width * height * channels);
    if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                temp[(height - 1 - i) * width * channels + (width - 1 - j) * channels + k] = image[i * width * channels + j * channels + k];
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                image[i * width * channels + j * channels + k] = temp[(height - 1 - i) * width * channels + (width - 1 - j) * channels + k];
            }
        }
    }

    free(temp);
}

// Function to change brightness and contrast
void change_brightness_contrast(int width, int height, int channels, unsigned char *image, float brightness, float contrast)
{
    int i, j;
    unsigned char *temp;

    temp = (unsigned char*)malloc(sizeof(unsigned char) * width * height * channels);
    if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                int r = (int)((image[i * width * channels + j * channels + k] * contrast) + brightness);
                if (r > 255) {
                    r = 255;
                } else if (r < 0) {
                    r = 0;
                }
                temp[(height - 1 - i) * width * channels + (width - 1 - j) * channels + k] = (unsigned char)r;
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                image[i * width * channels + j * channels + k] = temp[(height - 1 - i) * width * channels + (width - 1 - j) * channels + k];
            }
        }
    }

    free(temp);
}

// Function to change color levels
void change_color_levels(int width, int height, int channels, unsigned char *image, float low_level, float high_level)
{
    int i, j;
    unsigned char *temp;

    temp = (unsigned char*)malloc(sizeof(unsigned char) * width * height * channels);
    if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                if (image[i * width * channels + j * channels + k] < low_level) {
                    image[i * width * channels + j * channels + k] = 0;
                } else if (image[i * width * channels + j * channels + k] > high_level) {
                    image[i * width * channels + j * channels + k] = 255;
                } else {
                    image[i * width * channels + j * channels + k] = (unsigned char)(image[i * width * channels + j * channels + k] * (high_level - low_level) + low_level);
                }
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                temp[(height - 1 - i) * width * channels + (width - 1 - j) * channels + k] = (unsigned char)image[i * width * channels + j * channels + k];
            }
        }
    }

    free(temp);
}

int main()
{
    // Read image from file
    FILE *file = fopen("image.jpg", "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open image file\n");
        exit(1);
    }

    int width, height, channels;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&channels, sizeof(int), 1, file);
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height * channels);
    fread(image, sizeof(unsigned char), width * height * channels, file);
    fclose(file);

    // Flip image
    flip_image(width, height, channels, image);

    // Change brightness and contrast
    float brightness = 0.5;
    float contrast = 1.5;
    change_brightness_contrast(width, height, channels, image, brightness, contrast);

    // Change color levels
    float low_level = 0.5;
    float high_level = 0.8;
    change_color_levels(width, height, channels, image, low_level, high_level);

    // Write image to file
    FILE *file2 = fopen("output.jpg", "w");
    if (file2 == NULL) {
        fprintf(stderr, "Unable to open output file\n");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, file2);
    fwrite(&height, sizeof(int), 1, file2);
    fwrite(&channels, sizeof(int), 1, file2);
    fwrite(image, sizeof(unsigned char), width * height * channels, file2);
    fclose(file2);

    printf("Image processed successfully!\n");

    return 0;
}