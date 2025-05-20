//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define COLOR_CHANNELS 3

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} image_t;

image_t *create_image(int width, int height, int channels) {
    image_t *image = (image_t *) malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = (unsigned char *) malloc(width * height * channels);
    return image;
}

void destroy_image(image_t *image) {
    free(image->data);
    free(image);
}

void set_pixel(image_t *image, int x, int y, int channel, int value) {
    int offset = (y * image->width + x) * image->channels + channel;
    image->data[offset] = value;
}

int get_pixel(image_t *image, int x, int y, int channel) {
    int offset = (y * image->width + x) * image->channels + channel;
    return image->data[offset];
}

void save_image(image_t *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not save image to file.\n");
        return;
    }
    fwrite(image->data, 1, image->width * image->height * image->channels, file);
    fclose(file);
}

int main() {
    image_t *image = create_image(IMAGE_WIDTH, IMAGE_HEIGHT, COLOR_CHANNELS);
    int x, y;
    for (y = 0; y < IMAGE_HEIGHT; y++) {
        for (x = 0; x < IMAGE_WIDTH; x++) {
            int value = (int) (255 * (float) y / IMAGE_HEIGHT);
            set_pixel(image, x, y, 0, value);
            set_pixel(image, x, y, 1, value);
            set_pixel(image, x, y, 2, value);
        }
    }
    save_image(image, "gradient.png");
    destroy_image(image);
    return 0;
}