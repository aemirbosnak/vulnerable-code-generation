//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_WATERMARK_SIZE 256

// Function to read an image from a file
unsigned char* read_image(char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        exit(1);
    }

    // Read the header of the image
    unsigned char header[14];
    fread(header, 1, 14, fp);

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid image file format: %s\n", filename);
        exit(1);
    }

    // Get the width and height of the image
    *width = *(int*)(header + 18);
    *height = *(int*)(header + 22);

    // Check if the image is too large
    if (*width > MAX_IMAGE_SIZE || *height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: Image is too large: %dx%d\n", *width, *height);
        exit(1);
    }

    // Allocate memory for the image data
    unsigned char* image_data = (unsigned char*)malloc(*width * *height * 3);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        exit(1);
    }

    // Read the image data
    fread(image_data, 1, *width * *height * 3, fp);

    // Close the file
    fclose(fp);

    return image_data;
}

// Function to write an image to a file
void write_image(char* filename, unsigned char* image_data, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        exit(1);
    }

    // Write the header of the image
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(int*)(header + 2) = 54 + width * height * 3;
    *(int*)(header + 10) = 54;
    *(int*)(header + 14) = 40;
    *(int*)(header + 18) = width;
    *(int*)(header + 22) = height;
    *(short*)(header + 26) = 1;
    *(short*)(header + 28) = 24;
    *(int*)(header + 30) = 0;
    *(int*)(header + 34) = 0;
    *(int*)(header + 38) = 0;
    *(int*)(header + 42) = 0;
    fwrite(header, 1, 14, fp);

    // Write the image data
    fwrite(image_data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);
}

// Function to embed a watermark in an image
void embed_watermark(unsigned char* image_data, int width, int height, unsigned char* watermark_data, int watermark_width, int watermark_height) {
    // Check if the watermark is too large
    if (watermark_width > width || watermark_height > height) {
        fprintf(stderr, "Error: Watermark is too large: %dx%d\n", watermark_width, watermark_height);
        exit(1);
    }

    // Embed the watermark in the image
    for (int i = 0; i < watermark_height; i++) {
        for (int j = 0; j < watermark_width; j++) {
            // Get the pixel value at the current position
            unsigned char pixel_value = image_data[(i * width + j) * 3];

            // Get the watermark value at the current position
            unsigned char watermark_value = watermark_data[(i * watermark_width + j) * 3];

            // Embed the watermark value in the pixel value
            pixel_value = (pixel_value & 0xF8) | (watermark_value >> 3);

            // Set the pixel value at the current position
            image_data[(i * width + j) * 3] = pixel_value;
        }
    }
}

// Function to extract a watermark from an image
unsigned char* extract_watermark(unsigned char* image_data, int width, int height, int watermark_width, int watermark_height) {
    // Allocate memory for the watermark data
    unsigned char* watermark_data = (unsigned char*)malloc(watermark_width * watermark_height * 3);
    if (watermark_data == NULL) {
        fprintf(stderr, "Error allocating memory for watermark data\n");
        exit(1);
    }

    // Extract the watermark from the image
    for (int i = 0; i < watermark_height; i++) {
        for (int j = 0; j < watermark_width; j++) {
            // Get the pixel value at the current position
            unsigned char pixel_value = image_data[(i * width + j) * 3];

            // Extract the watermark value from the pixel value
            unsigned char watermark_value = (pixel_value & 0x07) << 3;

            // Set the watermark value at the current position
            watermark_data[(i * watermark_width + j) * 3] = watermark_value;
        }
    }

    return watermark_data;
}

int main(int argc, char** argv) {
    // Check if the user has provided enough arguments
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <image_file> <watermark_file> <output_image_file> <output_watermark_file>\n", argv[0]);
        exit(1);
    }

    // Read the image file
    int image_width, image_height;
    unsigned char* image_data = read_image(argv[1], &image_width, &image_height);

    // Read the watermark file
    int watermark_width, watermark_height;
    unsigned char* watermark_data = read_image(argv[2], &watermark_width, &watermark_height);

    // Embed the watermark in the image
    embed_watermark(image_data, image_width, image_height, watermark_data, watermark_width, watermark_height);

    // Write the watermarked image to a file
    write_image(argv[3], image_data, image_width, image_height);

    // Extract the watermark from the watermarked image
    unsigned char* extracted_watermark_data = extract_watermark(image_data, image_width, image_height, watermark_width, watermark_height);

    // Write the extracted watermark to a file
    write_image(argv[4], extracted_watermark_data, watermark_width, watermark_height);

    // Free the memory allocated for the image data and watermark data
    free(image_data);
    free(watermark_data);
    free(extracted_watermark_data);

    return 0;
}