//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ImageData {
    unsigned char* pixels;
    int width;
    int height;
} ImageData;

ImageData* loadImage(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read image file size
    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Allocate memory for image data
    ImageData* image = (ImageData*)malloc(sizeof(ImageData));
    image->pixels = (unsigned char*)malloc(width * height * 3);
    image->width = width;
    image->height = height;

    // Read image pixels
    fread(image->pixels, 3 * width * height, 1, file);

    fclose(file);
    return image;
}

void saveImage(ImageData* image, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write image file size
    fprintf(file, "%d %d", image->width, image->height);

    // Write image pixels
    fwrite(image->pixels, 3 * image->width * image->height, 1, file);

    fclose(file);
}

int main() {
    // Load image data
    ImageData* image = loadImage("image.jpg");

    // Modify image pixels
    image->pixels[0] = 255;

    // Save image data
    saveImage(image, "image_edited.jpg");

    return 0;
}