//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 8

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

typedef struct {
    image_t *image;
    int start_row;
    int end_row;
} thread_data_t;

void *flip_image_horizontally(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    image_t *image = data->image;
    int width = image->width;
    int height = image->height;

    for (int row = data->start_row; row < data->end_row; row++) {
        for (int col = 0; col < width / 2; col++) {
            unsigned char temp = image->data[row * width + col];
            image->data[row * width + col] = image->data[row * width + width - col - 1];
            image->data[row * width + width - col - 1] = temp;
        }
    }

    return NULL;
}

void *flip_image_vertically(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    image_t *image = data->image;
    int width = image->width;
    int height = image->height;

    for (int row = data->start_row; row < data->end_row; row++) {
        for (int col = 0; col < height / 2; col++) {
            unsigned char temp = image->data[(row + col) * width];
            image->data[(row + col) * width] = image->data[(height - col - 1) * width + row];
            image->data[(height - col - 1) * width + row] = temp;
        }
    }

    return NULL;
}

void *change_brightness_contrast(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    image_t *image = data->image;
    int width = image->width;
    int height = image->height;
    float brightness = 0.5;
    float contrast = 1.5;

    for (int row = data->start_row; row < data->end_row; row++) {
        for (int col = 0; col < width; col++) {
            unsigned char pixel = image->data[row * width + col];
            pixel = (pixel - 128) * contrast + 128;
            pixel = pixel + brightness;
            if (pixel < 0) pixel = 0;
            if (pixel > 255) pixel = 255;
            image->data[row * width + col] = pixel;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return -1;
    }

    image_t image;
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening image file");
        return -1;
    }

    // Read the image header
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image.data = (unsigned char *)malloc(image.width * image.height);
    if (!image.data) {
        perror("Error allocating memory for image data");
        fclose(fp);
        return -1;
    }

    // Read the image data
    fread(image.data, 1, image.width * image.height, fp);
    fclose(fp);

    // Create thread data structures
    thread_data_t thread_data[MAX_THREADS];

    // Create threads to flip the image horizontally and vertically
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS / 2; i++) {
        thread_data[i].image = &image;
        thread_data[i].start_row = i * image.height / MAX_THREADS;
        thread_data[i].end_row = (i + 1) * image.height / MAX_THREADS;
        pthread_create(&threads[i], NULL, flip_image_horizontally, &thread_data[i]);
    }
    for (int i = MAX_THREADS / 2; i < MAX_THREADS; i++) {
        thread_data[i].image = &image;
        thread_data[i].start_row = i * image.height / MAX_THREADS;
        thread_data[i].end_row = (i + 1) * image.height / MAX_THREADS;
        pthread_create(&threads[i], NULL, flip_image_vertically, &thread_data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads to change the brightness and contrast of the image
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].image = &image;
        thread_data[i].start_row = i * image.height / MAX_THREADS;
        thread_data[i].end_row = (i + 1) * image.height / MAX_THREADS;
        pthread_create(&threads[i], NULL, change_brightness_contrast, &thread_data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write the modified image to a file
    fp = fopen("output.bmp", "wb");
    if (!fp) {
        perror("Error opening output image file");
        free(image.data);
        return -1;
    }

    // Write the image header
    fwrite(&image.width, sizeof(int), 1, fp);
    fwrite(&image.height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image.data, 1, image.width * image.height, fp);
    fclose(fp);

    // Free the memory allocated for the image data
    free(image.data);

    return 0;
}