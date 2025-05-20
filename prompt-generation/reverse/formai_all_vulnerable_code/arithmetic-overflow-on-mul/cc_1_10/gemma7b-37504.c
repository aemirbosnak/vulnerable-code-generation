//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(char *filename) {
    Image *image = malloc(sizeof(Image));

    // Read image file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Get image size
    image->width = fread(file, 1, sizeof(int), file);
    image->height = fread(file, 1, sizeof(int), file);

    // Allocate image data
    image->data = malloc(image->width * image->height * 3);

    // Read image data
    fread(image->data, image->width * image->height * 3, 1, file);

    fclose(file);

    return image;
}

void save_image(Image *image, char *filename) {
    // Write image file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write image size
    fwrite(&image->width, 1, sizeof(int), file);
    fwrite(&image->height, 1, sizeof(int), file);

    // Write image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    fclose(file);
}

int main() {
    Image *image = load_image("image.jpg");
    save_image(image, "image_edited.jpg");

    free(image->data);
    free(image);

    return 0;
}