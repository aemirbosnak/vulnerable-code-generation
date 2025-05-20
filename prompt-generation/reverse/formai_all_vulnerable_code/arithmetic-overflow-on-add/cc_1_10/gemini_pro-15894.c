//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

void *flip_image(void *arg) {
    image_t *image = (image_t *)arg;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }

    return NULL;
}

void *adjust_brightness(void *arg) {
    image_t *image = (image_t *)arg;
    int brightness = *(int *)arg;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = image->data[y * image->width + x] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }

    return NULL;
}

void *adjust_contrast(void *arg) {
    image_t *image = (image_t *)arg;
    int contrast = *(int *)arg;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = image->data[y * image->width + x] * contrast / 100;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }

    return NULL;
}

int main() {
    // Load the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    image_t image;
    image.width = WIDTH;
    image.height = HEIGHT;
    image.data = (unsigned char *)malloc(image.width * image.height);
    if (!image.data) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(image.data, 1, image.width * image.height, fp);
    fclose(fp);

    // Create threads to perform the image processing tasks
    pthread_t flip_thread, brightness_thread, contrast_thread;

    pthread_create(&flip_thread, NULL, flip_image, &image);
    pthread_create(&brightness_thread, NULL, adjust_brightness, &image);
    pthread_create(&contrast_thread, NULL, adjust_contrast, &image);

    // Wait for the threads to finish
    pthread_join(flip_thread, NULL);
    pthread_join(brightness_thread, NULL);
    pthread_join(contrast_thread, NULL);

    // Save the processed image to a file
    fp = fopen("processed_image.bmp", "wb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fwrite(image.data, 1, image.width * image.height, fp);
    fclose(fp);

    // Free the image data
    free(image.data);

    return EXIT_SUCCESS;
}