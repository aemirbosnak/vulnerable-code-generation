//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int height = 0, width = 0, max_val = 0;

    // Open input file
    FILE *input_file = fopen("input.pgm", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Cannot open input file.\n");
        exit(EXIT_FAILURE);
    }

    // Read magic number
    char magic_num[3];
    fscanf(input_file, "%2s", magic_num);
    if (magic_num[0] != 'P' || magic_num[1] != '5') {
        fprintf(stderr, "Unsupported file format.\n");
        exit(EXIT_FAILURE);
    }

    // Read image dimensions
    fscanf(input_file, "%d %d", &width, &height);

    // Read max gray value
    fscanf(input_file, "%d", &max_val);
    if (max_val > 255) {
        fprintf(stderr, "Unsupported max gray value.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char *) malloc(height * width);

    // Read image data
    fread(image_data, sizeof(unsigned char), height * width, input_file);

    // Close input file
    fclose(input_file);

    // Flip image
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image_data[i*width + j];
            image_data[i*width + j] = image_data[(height-i-1)*width + j];
            image_data[(height-i-1)*width + j] = temp;
        }
    }

    // Adjust brightness and contrast
    float brightness = 0.5;
    float contrast = 0.8;
    for (int i = 0; i < height * width; i++) {
        int val = (int) image_data[i] * contrast + 255 * (brightness - 0.5);
        if (val < 0) val = 0;
        if (val > 255) val = 255;
        image_data[i] = (unsigned char) val;
    }

    // Open output file
    FILE *output_file = fopen("output.pgm", "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Cannot open output file.\n");
        exit(EXIT_FAILURE);
    }

    // Write magic number
    fprintf(output_file, "P5\n");

    // Write image dimensions
    fprintf(output_file, "%d %d\n", width, height);

    // Write max gray value
    fprintf(output_file, "%d\n", max_val);

    // Write image data
    fwrite(image_data, sizeof(unsigned char), height * width, output_file);

    // Close output file
    fclose(output_file);

    // Free memory
    free(image_data);

    return 0;
}