//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char* image;
} Image;

void load_image(const char* filename, Image* image) {
    // Open file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    // Get image dimensions
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Allocate image memory
    image->width = (int)strtol(buffer, NULL, 16);
    image->height = (int)strtol(strstr(buffer, " ") + 1, NULL, 16);
    image->image = (unsigned char*)malloc(image->width * image->height * 3);

    // Read image data
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = (y * image->width + x) * 3;
            image->image[index] = buffer[index];
            image->image[index + 1] = buffer[index + 1];
            image->image[index + 2] = buffer[index + 2];
        }
    }

    free(buffer);
}

void save_image(const char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = (y * image->width + x) * 3;
            fwrite(&image->image[index], sizeof(unsigned char), 1, file);
            fwrite(&image->image[index + 1], sizeof(unsigned char), 1, file);
            fwrite(&image->image[index + 2], sizeof(unsigned char), 1, file);
        }
    }

    fclose(file);
}

int main() {
    Image image;
    load_image("image.raw", &image);
    printf("Image loaded: %dx%d\n", image.width, image.height);

    // Edit image here

    save_image("image_edited.raw", &image);
    printf("Image saved: %dx%d\n", image.width, image.height);

    return 0;
}