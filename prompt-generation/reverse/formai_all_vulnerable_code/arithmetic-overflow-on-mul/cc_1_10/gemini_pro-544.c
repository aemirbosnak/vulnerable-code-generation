//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    int width, height, channels;
} Image;

void *flip_image(void *arg) {
    Image *image = (Image *)arg;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            for (int c = 0; c < image->channels; c++) {
                int i = (y * image->width + x) * image->channels + c;
                int j = (y * image->width + image->width - x - 1) * image->channels + c;
                uint8_t temp = image->data[i];
                image->data[i] = image->data[j];
                image->data[j] = temp;
            }
        }
    }

    return NULL;
}

void *adjust_brightness(void *arg) {
    Image *image = (Image *)arg;

    int brightness = 50;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                int i = (y * image->width + x) * image->channels + c;
                int adjusted = image->data[i] + brightness;
                if (adjusted < 0) adjusted = 0;
                if (adjusted > 255) adjusted = 255;
                image->data[i] = adjusted;
            }
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    Image image;

    // Load the image from a file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    // Read the image header
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);
    fread(&image.channels, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image.data = (uint8_t *)malloc(image.width * image.height * image.channels);
    if (image.data == NULL) {
        printf("Error allocating memory for image data\n");
        return 1;
    }

    // Read the image data from the file
    fread(image.data, image.width * image.height * image.channels, 1, fp);
    fclose(fp);

    // Create threads to flip and adjust the brightness of the image
    pthread_t flip_thread, brightness_thread;
    pthread_create(&flip_thread, NULL, flip_image, &image);
    pthread_create(&brightness_thread, NULL, adjust_brightness, &image);

    // Wait for the threads to finish
    pthread_join(flip_thread, NULL);
    pthread_join(brightness_thread, NULL);

    // Save the modified image to a file
    fp = fopen("modified_image.jpg", "wb");
    if (fp == NULL) {
        printf("Error opening output image file\n");
        return 1;
    }

    // Write the image header to the file
    fwrite(&image.width, sizeof(int), 1, fp);
    fwrite(&image.height, sizeof(int), 1, fp);
    fwrite(&image.channels, sizeof(int), 1, fp);

    // Write the image data to the file
    fwrite(image.data, image.width * image.height * image.channels, 1, fp);
    fclose(fp);

    // Free the memory allocated for the image data
    free(image.data);

    return 0;
}