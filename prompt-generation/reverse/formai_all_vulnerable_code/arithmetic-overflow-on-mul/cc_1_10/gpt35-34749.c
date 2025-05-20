//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_image_horizontal(unsigned char *image_data, int image_width, int image_height, int image_channels) {
    unsigned char temp_pixel;

    for(int y = 0; y < image_height; y++) {
        for(int x = 0; x < image_width/2; x++) {
            for(int c = 0; c < image_channels; c++) {
                temp_pixel = image_data[(y * image_width + x * image_channels) + c];
                image_data[(y * image_width + x * image_channels) + c] = image_data[(y * image_width + (image_width - x - 1) * image_channels) + c];
                image_data[(y * image_width + (image_width - x - 1) * image_channels) + c] = temp_pixel;
            }
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(unsigned char *image_data, int image_width, int image_height, int image_channels, float brightness) {
    for(int i = 0; i < image_width * image_height * image_channels; i++) {
        int new_pixel_value = image_data[i] * brightness;
        if (new_pixel_value > 255) {
            image_data[i] = 255;
        } else {
            image_data[i] = (unsigned char)new_pixel_value;
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(unsigned char *image_data, int image_width, int image_height, int image_channels, float contrast) {
    for(int i = 0; i < image_width * image_height * image_channels; i++) {
        int new_pixel_value = (image_data[i] - 128) * contrast + 128;
        if (new_pixel_value > 255) {
            image_data[i] = 255;
        } else if (new_pixel_value < 0) {
            image_data[i] = 0;
        } else {
            image_data[i] = (unsigned char)new_pixel_value;
        }
    }
}

int main(int argc, char** argv) {
    // Load the image file into memory
    FILE *image_file = fopen("input_image.bmp", "rb");
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    unsigned char *image_data = (unsigned char*)malloc(image_size);
    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    // Get the header information from the image file
    int image_width = *(int*)&image_data[18];
    int image_height = *(int*)&image_data[22];
    int image_channels = 3;

    // Do some image processing
    flip_image_horizontal(image_data, image_width, image_height, image_channels);
    adjust_brightness(image_data, image_width, image_height, image_channels, 1.5);
    adjust_contrast(image_data, image_width, image_height, image_channels, 1.2);

    // Save the modified image to file
    FILE *output_file = fopen("output_image.bmp", "wb");
    fwrite(image_data, image_size, 1, output_file);
    fclose(output_file);

    free(image_data);

    return 0;
}