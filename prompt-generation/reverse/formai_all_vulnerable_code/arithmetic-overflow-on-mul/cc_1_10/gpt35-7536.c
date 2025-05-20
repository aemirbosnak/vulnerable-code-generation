//FormAI DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define COLOR_DEPTH     3

// Function that applies grayscale filter to RGB pixel
void grayscale(unsigned char* pixel) {
    unsigned char gray = (0.3 * pixel[2]) + (0.59 * pixel[1]) + (0.11 * pixel[0]);
    pixel[0] = gray;
    pixel[1] = gray;
    pixel[2] = gray;
}

// Function that reads BMP image file
unsigned char* read_bmp_image(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open image file\n");
        exit(1);
    }

    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);

    // Check if file is BMP format
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: file is not BMP format\n");
        exit(1);
    }

    // Extract image dimensions
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Allocate memory for image data
    int img_size = (*width) * (*height) * COLOR_DEPTH;
    unsigned char* img_data = (unsigned char*) malloc(img_size * sizeof(unsigned char));
    if (!img_data) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    // Read image data
    fread(img_data, sizeof(unsigned char), img_size, file);
    fclose(file);

    return img_data;
}

// Function that writes BMP image file
void write_bmp_image(char* filename, unsigned char* img_data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not create image file\n");
        exit(1);
    }

    // Write BMP header
    unsigned char header[BMP_HEADER_SIZE];
    for (int i = 0; i < BMP_HEADER_SIZE; i++) {
        header[i] = 0;
    }
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = BMP_HEADER_SIZE + (width * height * COLOR_DEPTH);
    *(int*)&header[10] = BMP_HEADER_SIZE;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    *(int*)&header[34] = (width * height * COLOR_DEPTH);
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);

    // Write image data
    fwrite(img_data, sizeof(unsigned char), width * height * COLOR_DEPTH, file);
    fclose(file);
}

int main() {
    int width, height;
    unsigned char* img_data = read_bmp_image("sample_image.bmp", &width, &height);

    // Apply grayscale filter
    int img_size = width * height * COLOR_DEPTH;
    for (int i = 0; i < img_size; i += COLOR_DEPTH) {
        grayscale(&img_data[i]);
    }

    write_bmp_image("grayscale_image.bmp", img_data, width, height);
    free(img_data);
    
    return 0;
}