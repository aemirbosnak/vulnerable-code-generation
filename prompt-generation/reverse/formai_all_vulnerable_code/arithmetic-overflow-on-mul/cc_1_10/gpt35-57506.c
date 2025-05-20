//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void flip_image(unsigned char *image, int width, int height) {
    unsigned char *temp = (unsigned char*) malloc(sizeof(unsigned char) * width * 3);
    int half_height = height / 2;

    for(int row = 0; row < half_height; row++) {
        int opposite_row = height - row - 1;
        int row_start = row * width * 3;
        int opposite_row_start = opposite_row * width * 3;

        memcpy(temp, image + row_start, sizeof(unsigned char) * width * 3);
        memcpy(image + row_start, image + opposite_row_start, sizeof(unsigned char) * width * 3);
        memcpy(image + opposite_row_start, temp, sizeof(unsigned char) * width * 3);
    }

    free(temp);
}

void adjust_brightness_contrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    float contrast_factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    float brightness_factor = brightness / 255.0f;

    for(int i = 0; i < width * height * 3; i++) {
        float pixel_value = image[i];

        // Adjust brightness
        pixel_value += brightness_factor;

        // Adjust contrast
        pixel_value = contrast_factor * (pixel_value - 128.0f) + 128.0f;

        if(pixel_value < 0) {
            pixel_value = 0;
        } else if(pixel_value > 255) {
            pixel_value = 255;
        }

        image[i] = (unsigned char) pixel_value;
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_file_path = argv[1];
    FILE *input_file = fopen(input_file_path, "rb");

    if(input_file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", input_file_path);
        return EXIT_FAILURE;
    }

    int width, height;
    fscanf(input_file, "P6\n%d %d\n255\n", &width, &height);
    unsigned char *image = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);

    fread(image, sizeof(unsigned char), width * height * 3, input_file);
    fclose(input_file);

    // Flip the image
    flip_image(image, width, height);

    // Adjust the brightness and contrast
    adjust_brightness_contrast(image, width, height, 50, 100);

    // Save the modified image to a new file
    FILE *output_file = fopen("output.ppm", "wb");
    fprintf(output_file, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height * 3, output_file);
    fclose(output_file);

    free(image);

    return EXIT_SUCCESS;
}