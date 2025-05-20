//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    unsigned int width, height;
    if (fscanf(file, "P5\n%u %u\n255\n", &width, &height) != 2) {
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (image->data == NULL) {
        free(image);
        fclose(file);
        return NULL;
    }

    if (fread(image->data, width * height, 1, file) != 1) {
        free(image->data);
        free(image);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return image;
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    fprintf(file, "P5\n%u %u\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, file);

    fclose(file);
}

void invert_image(Image *image) {
    for (unsigned int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void blur_image(Image *image) {
    unsigned char *new_data = malloc(image->width * image->height);
    if (new_data == NULL) {
        return;
    }

    for (unsigned int i = 0; i < image->width * image->height; i++) {
        int sum = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                int x = i % image->width + j;
                int y = i / image->width + k;
                if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                    sum += image->data[y * image->width + x];
                }
            }
        }
        new_data[i] = sum / 9;
    }

    free(image->data);
    image->data = new_data;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image %s\n", argv[1]);
        return 1;
    }

    invert_image(image);
    blur_image(image);

    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}