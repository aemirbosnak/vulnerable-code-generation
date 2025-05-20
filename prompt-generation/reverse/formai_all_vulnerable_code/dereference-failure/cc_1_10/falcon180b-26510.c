//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Open the input image file
    FILE *input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read the BMP file header
    int file_header_size = 0;
    fread(&file_header_size, sizeof(int), 1, input_file);
    printf("File header size: %d\n", file_header_size);

    int image_width, image_height;
    fread(&image_width, sizeof(int), 1, input_file);
    fread(&image_height, sizeof(int), 1, input_file);
    printf("Image size: %dx%d\n", image_width, image_height);

    int bit_depth, compression_method;
    fread(&bit_depth, sizeof(int), 1, input_file);
    fread(&compression_method, sizeof(int), 1, input_file);
    printf("Bit depth: %d\n", bit_depth);
    printf("Compression method: %d\n", compression_method);

    // Read the pixel data
    int image_size = image_width * image_height;
    unsigned char *pixels = (unsigned char *) malloc(image_size * sizeof(unsigned char));
    fread(pixels, sizeof(unsigned char), image_size, input_file);

    // Flip the image horizontally
    for (int i = 0; i < image_height / 2; i++) {
        for (int j = 0; j < image_width; j++) {
            int index1 = i * image_width + j;
            int index2 = (image_height - i - 1) * image_width + j;
            unsigned char temp = pixels[index1];
            pixels[index1] = pixels[index2];
            pixels[index2] = temp;
        }
    }

    // Change the brightness and contrast of the image
    int brightness = 50;
    int contrast = 10;
    for (int i = 0; i < image_size; i++) {
        int value = pixels[i];
        int new_value = (int) (value * (1 + ((double) brightness / 100.0)) * (1 + ((double) contrast / 100.0)));
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        pixels[i] = (unsigned char) new_value;
    }

    // Write the modified pixel data to a new BMP file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    fwrite(&file_header_size, sizeof(int), 1, output_file);
    fwrite(&image_width, sizeof(int), 1, output_file);
    fwrite(&image_height, sizeof(int), 1, output_file);
    fwrite(&bit_depth, sizeof(int), 1, output_file);
    fwrite(&compression_method, sizeof(int), 1, output_file);

    fwrite(pixels, sizeof(unsigned char), image_size, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Done!\n");

    return 0;
}