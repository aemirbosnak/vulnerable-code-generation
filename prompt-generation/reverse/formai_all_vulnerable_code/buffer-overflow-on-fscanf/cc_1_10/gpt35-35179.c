//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define an image file structure to hold file data
struct image_file {
    char* file_name;
    int width;
    int height;
    unsigned char* pixels;
};

// Helper function to read a PGM image file
struct image_file read_pgm_image(char *file_name) {
    FILE *image_file = fopen(file_name, "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file\n");
        exit(1);
    }
    char image_format[3];
    fscanf(image_file, "%s", image_format);
    if (image_format[0] != 'P' || image_format[1] != '5' || image_format[2] != '\n') {
        printf("Error: Invalid PGM format\n");
        exit(1);
    }
    int width, height, maxval;
    fscanf(image_file, "%d %d %d\n", &width, &height, &maxval);
    if (maxval > 255) {
        printf("Error: Only 8-bit PGM images are supported\n");
        exit(1);
    }
    unsigned char *pixels = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    fread(pixels, sizeof(unsigned char), width * height, image_file);
    fclose(image_file);
    struct image_file image = {file_name, width, height, pixels};
    return image;
}

// Helper function to write a PGM image file
void write_pgm_image(struct image_file image) {
    FILE *output_file = fopen("compressed_image.pgm", "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }
    fprintf(output_file, "P5\n%d %d\n255\n", image.width, image.height);
    fwrite(image.pixels, sizeof(unsigned char), image.width * image.height, output_file);
    fclose(output_file);
}

// Helper function to compress an image
struct image_file compress_image(struct image_file image, int compression_factor) {
    if (compression_factor <= 0) {
        printf("Error: Compression factor must be greater than 0\n");
        exit(1);
    }
    int compressed_width = (int)ceil((double)image.width / compression_factor);
    int compressed_height = (int)ceil((double)image.height / compression_factor);
    unsigned char *compressed_pixels = (unsigned char*)malloc(sizeof(unsigned char) * compressed_width * compressed_height);
    int i, j, k, l, pixel_avg;
    for (i = 0; i < compressed_height; i++) {
        for (j = 0; j < compressed_width; j++) {
            k = i * compression_factor; // Starting row of block
            l = j * compression_factor; // Starting column of block
            int sum = 0;
            int num_pixels = 0;
            // Compute average pixel value of the block
            for (int m = k; m < k + compression_factor && m < image.height; m++) {
                for (int n = l; n < l + compression_factor && n < image.width; n++) {
                    sum += (int)image.pixels[m * image.width + n];
                    num_pixels++;
                }
            }
            pixel_avg = (int)round((double)sum / num_pixels);
            compressed_pixels[i * compressed_width + j] = (unsigned char)pixel_avg;
        }
    }
    struct image_file compressed_image = {"compressed.pgm", compressed_width, compressed_height, compressed_pixels};
    return compressed_image;
}

int main() {
    struct image_file image = read_pgm_image("lena.pgm");
    printf("Compressing image...\n");
    struct image_file compressed_image = compress_image(image, 2);
    printf("Writing compressed image to file...\n");
    write_pgm_image(compressed_image);
    printf("Compression complete\n");
    return 0;
}