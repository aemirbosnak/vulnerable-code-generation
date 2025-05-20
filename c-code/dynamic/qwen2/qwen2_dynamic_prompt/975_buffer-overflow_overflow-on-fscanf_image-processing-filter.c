#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE * MAX_IMAGE_SIZE];
} Image;

void apply_filter(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i] = img->pixels[i] * 2;
    }
}

int main() {
    Image img;
    printf("Enter image dimensions (width height): ");
    if (fscanf(stdin, "%d %d", &img.width, &img.height) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return 1;
    }

    if (img.width <= 0 || img.height <= 0 || img.width > MAX_IMAGE_SIZE || img.height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Image dimensions out of range\n");
        return 1;
    }

    printf("Enter pixel values:\n");
    for (int i = 0; i < img.width * img.height; i++) {
        if (fscanf(stdin, "%hhu", &img.pixels[i]) != 1) {
            fprintf(stderr, "Invalid pixel value\n");
            return 1;
        }
    }

    apply_filter(&img);

    printf("Filtered image:\n");
    for (int i = 0; i < img.width * img.height; i++) {
        printf("%hhu ", img.pixels[i]);
        if ((i + 1) % img.width == 0) {
            printf("\n");
        }
    }

    return 0;
}
