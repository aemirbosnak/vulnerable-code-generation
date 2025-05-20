//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <fftw3.h>

#define PI 3.14159265358979323846
#define WATERMARK_SIZE 256
#define WATERMARK_VALUE 128

typedef struct {
    int watermark;
    int *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->watermark = WATERMARK_VALUE;
    image->data = (int *)malloc(sizeof(int) * width * height);
    for (int i = 0; i < width * height; i++) {
        image->data[i] = rand() % 256;
    }
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

Image *embed_watermark(Image *image, int watermark) {
    Image *watermarked_image = create_image(image->data[0], image->data[1]);
    for (int i = 0; i < image->data[0]; i++) {
        for (int j = 0; j < image->data[1]; j++) {
            int pixel_value = image->data[(i * image->data[1]) + j];
            int watermark_value = (pixel_value + (watermark - WATERMARK_VALUE)) % 256;
            watermarked_image->data[(i * watermarked_image->data[1]) + j] = watermark_value;
        }
    }
    return watermarked_image;
}

void print_image(Image *image) {
    for (int i = 0; i < image->data[0]; i++) {
        for (int j = 0; j < image->data[1]; j++) {
            printf("%d ", image->data[(i * image->data[1]) + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Image *image = create_image(WATERMARK_SIZE, WATERMARK_SIZE);
    Image *watermarked_image = embed_watermark(image, WATERMARK_VALUE);
    print_image(image);
    print_image(watermarked_image);
    destroy_image(image);
    destroy_image(watermarked_image);
    return 0;
}