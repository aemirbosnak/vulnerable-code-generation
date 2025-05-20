//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct Image {
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *image_load(char *filename) {
    Image *image = malloc(sizeof(Image));
    image->width = 0;
    image->height = 0;
    image->pixels = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read image dimensions
    fscanf(file, "%d %d", &image->width, &image->height);

    // Allocate pixels
    image->pixels = malloc(image->width * image->height * 3);

    // Read pixel data
    fread(image->pixels, image->width * image->height * 3, 1, file);

    fclose(file);
    return image;
}

void image_save(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    // Write image dimensions
    fprintf(file, "%d %d", image->width, image->height);

    // Write pixel data
    fwrite(image->pixels, image->width * image->height * 3, 1, file);

    fclose(file);
}

int main() {
    Image *image = image_load("image.jpg");
    image_save(image, "image_edited.jpg");

    free(image->pixels);
    free(image);

    return 0;
}