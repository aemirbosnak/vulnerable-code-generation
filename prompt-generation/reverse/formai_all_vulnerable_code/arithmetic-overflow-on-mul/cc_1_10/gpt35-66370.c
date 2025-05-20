//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PIXEL_VALUE 255

/* Function prototypes */
void flip_image(char *filename, int width, int height, int channels, unsigned char *pixels);
void adjust_brightness(char *filename, int width, int height, int channels, unsigned char *pixels, int brightness);
void adjust_contrast(char *filename, int width, int height, int channels, unsigned char *pixels, float contrast);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    int width, height, channels, brightness;
    float contrast;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the width, height and number of channels: ");
    scanf("%d %d %d", &width, &height, &channels);

    /* Allocate memory for the pixel array */
    unsigned char *pixels = (unsigned char *) malloc(width * height * channels * sizeof(unsigned char));

    /* Read in the image data */
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open %s\n", filename);
        exit(1);
    }
    fread(pixels, sizeof(unsigned char), width * height * channels, file);
    fclose(file);

    /* Flip the image horizontally */
    flip_image(filename, width, height, channels, pixels);

    /* Adjust the brightness of the image */
    printf("Enter the brightness adjustment value (between -255 and 255): ");
    scanf("%d", &brightness);
    adjust_brightness(filename, width, height, channels, pixels, brightness);

    /* Adjust the contrast of the image */
    printf("Enter the contrast adjustment value (between 0.0 and 3.0): ");
    scanf("%f", &contrast);
    adjust_contrast(filename, width, height, channels, pixels, contrast);

    /* Free the memory allocated for the pixel array */
    free(pixels);

    return 0;
}

void flip_image(char *filename, int width, int height, int channels, unsigned char *pixels)
{
    /* Allocate memory for the flipped pixel array */
    unsigned char *flipped_pixels = (unsigned char *) malloc(width * height * channels * sizeof(unsigned char));

    /* Flip the image horizontally */
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int channel = 0; channel < channels; channel++) {
                flipped_pixels[(row * width + (width - col - 1)) * channels + channel] = pixels[(row * width + col) * channels + channel];
            }
        }
    }

    /* Write the flipped image data to a new file */
    char new_filename[MAX_FILENAME_LENGTH];
    char *dot_pointer = strrchr(filename, '.');
    if (dot_pointer) {
        strncpy(new_filename, filename, dot_pointer - filename);
        strncpy(new_filename + (dot_pointer - filename), "_flipped", MAX_FILENAME_LENGTH - (dot_pointer - filename));
    } else {
        strncpy(new_filename, filename, MAX_FILENAME_LENGTH - 8);
        strcat(new_filename, "_flipped");
    }
    FILE *file = fopen(new_filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not create %s\n", new_filename);
        exit(1);
    }
    fwrite(flipped_pixels, sizeof(unsigned char), width * height * channels, file);
    fclose(file);

    /* Free the memory allocated for the flipped pixel array */
    free(flipped_pixels);
}

void adjust_brightness(char *filename, int width, int height, int channels, unsigned char *pixels, int brightness)
{
    /* Adjust the brightness of the image */
    for (int i = 0; i < width * height * channels; i++) {
        int new_value = pixels[i] + brightness;
        if (new_value < 0) {
            pixels[i] = 0;
        } else if (new_value > MAX_PIXEL_VALUE) {
            pixels[i] = MAX_PIXEL_VALUE;
        } else {
            pixels[i] = new_value;
        }
    }

    /* Write the adjusted image data to a new file */
    char new_filename[MAX_FILENAME_LENGTH];
    char *dot_pointer = strrchr(filename, '.');
    if (dot_pointer) {
        strncpy(new_filename, filename, dot_pointer - filename);
        strncpy(new_filename + (dot_pointer - filename), "_brightness", MAX_FILENAME_LENGTH - (dot_pointer - filename));
    } else {
        strncpy(new_filename, filename, MAX_FILENAME_LENGTH - 12);
        strcat(new_filename, "_brightness");
    }
    FILE *file = fopen(new_filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not create %s\n", new_filename);
        exit(1);
    }
    fwrite(pixels, sizeof(unsigned char), width * height * channels, file);
    fclose(file);
}

void adjust_contrast(char *filename, int width, int height, int channels, unsigned char *pixels, float contrast)
{
    /* Calculate the scale factor for the contrast adjustment */
    float scale_factor = (contrast * MAX_PIXEL_VALUE) / (MAX_PIXEL_VALUE - contrast);

    /* Adjust the contrast of the image */
    for (int i = 0; i < width * height * channels; i++) {
        int new_value = pixels[i] * scale_factor - contrast * (scale_factor - 1);
        if (new_value < 0) {
            pixels[i] = 0;
        } else if (new_value > MAX_PIXEL_VALUE) {
            pixels[i] = MAX_PIXEL_VALUE;
        } else {
            pixels[i] = new_value;
        }
    }

    /* Write the adjusted image data to a new file */
    char new_filename[MAX_FILENAME_LENGTH];
    char *dot_pointer = strrchr(filename, '.');
    if (dot_pointer) {
        strncpy(new_filename, filename, dot_pointer - filename);
        strncpy(new_filename + (dot_pointer - filename), "_contrast", MAX_FILENAME_LENGTH - (dot_pointer - filename));
    } else {
        strncpy(new_filename, filename, MAX_FILENAME_LENGTH - 10);
        strcat(new_filename, "_contrast");
    }
    FILE *file = fopen(new_filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not create %s\n", new_filename);
        exit(1);
    }
    fwrite(pixels, sizeof(unsigned char), width * height * channels, file);
    fclose(file);
}