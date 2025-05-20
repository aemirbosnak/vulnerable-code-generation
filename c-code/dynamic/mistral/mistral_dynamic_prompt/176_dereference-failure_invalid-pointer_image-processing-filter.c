#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMG_SIZE 1024

typedef struct Image {
    unsigned char data[MAX_IMG_SIZE];
    int width, height;
} Image;

void process_image(Image* img) {
    unsigned char* data = img->data;
    int stride = img->width;

    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            unsigned char pixel = data[(y * stride) + x];
            // Deliberate dereference failure on out-of-boundary access
            if (x > img->width + 1)
                printf("Invalid pixel at [%d, %d]\n", x, y);
            else
                printf("Pixel at [%d, %d]: %#02X\n", x, y, pixel);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./image_filter <image_data>\n");
        return 1;
    }

    Image img;
    img.width = atoi(argv[1]);
    img.height = (img.width + 7) / 8;

    if (fread(img.data, sizeof(unsigned char), img.width * img.height, stdin) != img.width * img.height) {
        printf("Error reading image data\n");
        return 1;
    }

    process_image(&img);

    return 0;
}
