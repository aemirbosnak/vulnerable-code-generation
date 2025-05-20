//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width, height, channels;
} Image;

Image *read_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }
    
    unsigned char header[54];
    fread(header, 54, 1, file);
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];
    image->channels = header[28] / 8;
    
    int data_size = image->width * image->height * image->channels;
    image->data = malloc(data_size);
    fread(image->data, data_size, 1, file);
    
    fclose(file);
    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }
    
    unsigned char header[54];
    memcpy(header, "BM", 2);
    *(int *)&header[2] = 54 + image->width * image->height * image->channels;
    *(int *)&header[10] = 54;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    header[28] = image->channels * 8;
    header[32] = 0;
    header[34] = 0;
    header[36] = 0;
    header[38] = 0;
    
    fwrite(header, 54, 1, file);
    fwrite(image->data, image->width * image->height * image->channels, 1, file);
    
    fclose(file);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width + j + k];
                image->data[i * image->width + j + k] = image->data[(image->height - i - 1) * image->width + j + k];
                image->data[(image->height - i - 1) * image->width + j + k] = temp;
            }
        }
    }
}

void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char value = image->data[i * image->width + j + k];
                value = value * contrast + brightness;
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                image->data[i * image->width + j + k] = value;
            }
        }
    }
}

int main() {
    Image *image = read_image("image.bmp");
    if (!image) return 1;
    
    flip_image(image);
    adjust_brightness_contrast(image, 50, 1.2);
    
    write_image(image, "image_processed.bmp");
    free(image->data);
    free(image);
    return 0;
}