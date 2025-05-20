//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 100

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("ERROR: No image file provided.\n");
        return 1;
    }

    char filepath[MAX_FILENAME];
    strcpy(filepath, argv[1]);

    FILE *image_file = fopen(filepath, "rb");
    if (image_file == NULL) {
        printf("ERROR: Could not open file %s.\n", filepath);
        return 1;
    }

    // Parse image header
    char header[55];
    fread(header, sizeof(char), 54, image_file);

    // Extract image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Extract image offset
    int offset = *(int*)&header[10];

    // Calculate padding
    int padding = 4 - (width * 3) % 4;
    if (padding == 4) {
        padding = 0;
    }

    // Calculate image size
    int image_size = width * height * 3 + height * padding;

    // Load image
    char *image_buffer = (char*)malloc(image_size);
    fread(image_buffer, sizeof(char), image_size, image_file);
    fclose(image_file);

    // Flip image vertically
    char *top_row = image_buffer + offset;
    char *bottom_row = image_buffer + offset + (height - 1) * (width * 3 + padding);
    char row_buffer[width * 3 + padding];
    for (int i = 0; i < height / 2; i++) {
        memcpy(row_buffer, top_row + i * (width * 3 + padding), width * 3 + padding);
        memcpy(top_row + i * (width * 3 + padding), bottom_row - i * (width * 3 + padding), width * 3 + padding);
        memcpy(bottom_row - i * (width * 3 + padding), row_buffer, width * 3 + padding);
    }

    // Adjust brightness and contrast
    int brightness = 50;
    int contrast = 25;
    char *pixel;
    int value;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = image_buffer + offset + (y * width + x) * 3;
            value = (*pixel) + brightness;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *pixel = value;

            value = (*(pixel+1)) + brightness;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *(pixel+1) = value;

            value = (*(pixel+2)) + brightness;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *(pixel+2) = value;

            value = ((contrast + 100) * (*pixel - 128)) / 100 + 128;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *pixel = value;

            value = ((contrast + 100) * (*(pixel+1) - 128)) / 100 + 128;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *(pixel+1) = value;

            value = ((contrast + 100) * (*(pixel+2) - 128)) / 100 + 128;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            *(pixel+2) = value;
        }
    }

    // Save image
    char new_filename[MAX_FILENAME];
    sprintf(new_filename, "processed_%s", filepath);
    image_file = fopen(new_filename, "wb");
    fwrite(header, sizeof(char), 54, image_file);
    fwrite(image_buffer, sizeof(char), image_size, image_file);
    fclose(image_file);
    free(image_buffer);

    printf("Image processing complete. Saved to %s\n", new_filename);

    return 0;
}