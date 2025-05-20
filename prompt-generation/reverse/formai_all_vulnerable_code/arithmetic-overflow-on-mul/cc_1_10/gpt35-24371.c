//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255


// Function to flip the image horizontally
void flip_image_horizontal(int width, int height, unsigned char *image_data) {
    unsigned char temp_buffer[width];
    for (int y = 0; y < height; y++) {
        int row_start = y * width;
        int row_end = row_start + width - 1;
        for (int x = 0; x < width / 2; x++) {
            int left_index = row_start + x;
            int right_index = row_end - x;
            // Swap the pixel values of the left and right pixels
            temp_buffer[x] = image_data[left_index];
            image_data[left_index] = image_data[right_index];
            image_data[right_index] = temp_buffer[x];
        }
    }
}

// Function to adjust the brightness of the image
void adjust_brightness(int width, int height, unsigned char *image_data, int brightness_level) {
    int new_pixel_value = 0;
    for (int i = 0; i < width * height; i++) {
        new_pixel_value = (int) image_data[i] + brightness_level;
        new_pixel_value = new_pixel_value > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : new_pixel_value;
        new_pixel_value = new_pixel_value < 0 ? 0 : new_pixel_value;
        image_data[i] = (unsigned char) new_pixel_value;
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(int width, int height, unsigned char *image_data, float contrast_level) {
    float factor = (259.0 * (contrast_level + 255.0)) / (255.0 * (259.0 - contrast_level));
    int new_pixel_value = 0;
    for (int i = 0; i < width * height; i++) {
        new_pixel_value = (int) (factor * (image_data[i] - 128) + 128);
        new_pixel_value = new_pixel_value > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : new_pixel_value;
        new_pixel_value = new_pixel_value < 0 ? 0 : new_pixel_value;
        image_data[i] = (unsigned char) new_pixel_value;
    }
}

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return -1;
    }

    char *input_file_path = argv[1];
    char *output_file_path = argv[2];

    FILE *input_file = fopen(input_file_path, "rb");

    if (!input_file) {
        printf("Error: Could not open input file %s\n", input_file_path);
        return -1;
    }

    // Read the header of the input file
    char header[54];
    fread(header, sizeof(char), 54, input_file);

    int width = *(int *) &header[18];
    int height = *(int *) &header[22];

    unsigned char *image_data = (unsigned char *) malloc(width * height * sizeof(unsigned char));

    // Read the pixel data of the input file
    fread(image_data, sizeof(unsigned char), width * height, input_file);

    fclose(input_file);

    // Flip the image horizontally
    flip_image_horizontal(width, height, image_data);

    // Adjust the brightness of the image
    adjust_brightness(width, height, image_data, 50);

    // Adjust the contrast of the image
    adjust_contrast(width, height, image_data, 50.0);

    FILE *output_file = fopen(output_file_path, "wb");

    // Write the header of the output file
    fwrite(header, sizeof(char), 54, output_file);

    // Write the pixel data of the output file
    fwrite(image_data, sizeof(unsigned char), width * height, output_file);

    fclose(output_file);
    free(image_data);

    printf("Done!\n");

    return 0;
}