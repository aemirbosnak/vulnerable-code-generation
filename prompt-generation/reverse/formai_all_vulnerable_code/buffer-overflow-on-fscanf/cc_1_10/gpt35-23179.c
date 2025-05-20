//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

void flip_image(unsigned char* image_data, int width, int height) {
    unsigned char* temp_row = (unsigned char*)malloc(sizeof(unsigned char) * width * 3);

    for (int row = 0; row < height / 2; row++) {
        int opposite_row = height - row - 1;
        unsigned char* current_row_ptr = image_data + row * width * 3;
        unsigned char* opposite_row_ptr = image_data + opposite_row * width * 3;

        // Swap rows using temp_row as buffer
        memcpy(temp_row, current_row_ptr, sizeof(unsigned char) * width * 3);
        memcpy(current_row_ptr, opposite_row_ptr, sizeof(unsigned char) * width * 3);
        memcpy(opposite_row_ptr, temp_row, sizeof(unsigned char) * width * 3);
    }

    free(temp_row);
}

void adjust_contrast(unsigned char* image_data, int width, int height, float contrast_adjustment) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width * 3; col++) {
            int current_pixel_value = image_data[row * width * 3 + col];
            float new_pixel_value = (current_pixel_value - 128.0) * contrast_adjustment + 128.0;
            new_pixel_value = new_pixel_value < 0 ? 0 : new_pixel_value;
            new_pixel_value = new_pixel_value > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : new_pixel_value;
            image_data[row * width * 3 + col] = (unsigned char)new_pixel_value;
        }
    }
}

void adjust_brightness(unsigned char* image_data, int width, int height, float brightness_adjustment) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width * 3; col++) {
            int current_pixel_value = image_data[row * width * 3 + col];
            float new_pixel_value = current_pixel_value + brightness_adjustment;
            new_pixel_value = new_pixel_value < 0 ? 0 : new_pixel_value;
            new_pixel_value = new_pixel_value > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : new_pixel_value;
            image_data[row * width * 3 + col] = (unsigned char)new_pixel_value;
        }
    }
}

int main() {
    // Open image file
    FILE* image_file = fopen("example_image.ppm", "rb");
    if (!image_file) {
        fprintf(stderr, "Error: Failed to open image file.\n");
        return 1;
    }

    // Read image data and header
    char header[3];
    int width, height, max_color_value;
    unsigned char* image_data;
    if (fscanf(image_file, "%s\n%d %d\n%d\n", header, &width, &height, &max_color_value) == 4) {
        if (strcmp(header, "P6")) {
            fprintf(stderr, "Error: Invalid image format. Expected P6.\n");
            return 1;
        }
        image_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
        fread(image_data, sizeof(unsigned char), width * height * 3, image_file);
    } else {
        fprintf(stderr, "Error: Invalid image header.\n");
        return 1;
    }
    fclose(image_file);

    // Flip image and adjust contrast/brightness
    flip_image(image_data, width, height);
    adjust_contrast(image_data, width, height, 2.0);
    adjust_brightness(image_data, width, height, -50.0);

    // Save new image file
    FILE* new_image_file = fopen("new_image.ppm", "wb");
    if (!new_image_file) {
        fprintf(stderr, "Error: Failed to create new image file.\n");
        return 1;
    }
    fprintf(new_image_file, "P6\n%d %d\n%d\n", width, height, MAX_PIXEL_VALUE);
    fwrite(image_data, sizeof(unsigned char), width * height * 3, new_image_file);
    fclose(new_image_file);

    // Free allocated memory
    free(image_data);

    return 0;
}