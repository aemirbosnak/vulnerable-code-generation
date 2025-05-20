//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

#define MAX_PIXEL_VALUE 255

void flip_image(unsigned char* image_data, int width, int height) {
    unsigned char* temp_row = (unsigned char*) malloc(width * sizeof(unsigned char));
    int half_height = height / 2;
    int row_size = width * sizeof(unsigned char);

    for (int i = 0; i < half_height; i++) {
        int reflex_row = height - 1 - i;
        unsigned char* row = image_data + i * width;
        unsigned char* reflex_row_ptr = image_data + reflex_row * width;

        // Store the row that we're flipping in a temporary buffer
        memcpy(temp_row, row, row_size);

        // Replace the original row with its mirror reflection
        memcpy(row, reflex_row_ptr, row_size);

        // Override the reflection with the original row (stored in the temp buffer)
        memcpy(reflex_row_ptr, temp_row, row_size);
    }

    free(temp_row);
}

void adjust_brightness_contrast(unsigned char* image_data, int width, int height, int brightness_offset, int contrast_offset) {
    // Iterate through each pixel of the image and adjust its brightness and contrast
    for (int i = 0; i < width * height; i++) {
        int new_pixel_value = (int) image_data[i] + brightness_offset;
        new_pixel_value = (new_pixel_value - MAX_PIXEL_VALUE/2) * contrast_offset + MAX_PIXEL_VALUE/2;

        // Clamp the pixel value to the valid range [0, 255]
        if (new_pixel_value < 0) {
            new_pixel_value = 0;
        }
        if (new_pixel_value > MAX_PIXEL_VALUE) {
            new_pixel_value = MAX_PIXEL_VALUE;
        }

        // Update the pixel value in the image data buffer
        image_data[i] = (unsigned char) new_pixel_value;
    }
}

int main() {
    // Open the input file
    FILE* input_file = fopen("input.bin", "rb");
    if (input_file == NULL) {
        printf("Error: can't open input file\n");
        return 1;
    }

    // Open the output file
    FILE* output_file = fopen("output.bin", "wb");
    if (output_file == NULL) {
        fclose(input_file);
        printf("Error: can't open output file\n");
        return 1;
    }

    // Read the image dimensions from the file
    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Allocate memory for the image data
    int pixel_count = width * height;
    unsigned char* image_data = (unsigned char*) malloc(pixel_count * sizeof(unsigned char));

    // Read the image data from the file
    fread(image_data, sizeof(unsigned char), pixel_count, input_file);

    // TODO: Call functions to perform image processing tasks here
    flip_image(image_data, width, height);
    adjust_brightness_contrast(image_data, width, height, 50, 2);

    // Write the processed image to the output file
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    fwrite(image_data, sizeof(unsigned char), pixel_count, output_file);

    // Cleanup resources
    fclose(input_file);
    fclose(output_file);
    free(image_data);

    return 0;
}