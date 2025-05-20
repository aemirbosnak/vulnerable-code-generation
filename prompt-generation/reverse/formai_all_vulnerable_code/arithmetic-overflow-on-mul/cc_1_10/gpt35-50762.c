//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants to define maximum image width and height
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Function to read a BMP file
void read_bmp(FILE *fp, uint8_t *image, int width, int height) {
    int row_size = width * 3;
    uint8_t padding = 0;
    if ((row_size % 4) != 0) {
        padding = 4 - (row_size % 4);
        row_size += padding;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pos = (y * row_size) + (x * 3);
            fread(&image[pos + 2], 1, 1, fp);
            fread(&image[pos + 1], 1, 1, fp);
            fread(&image[pos], 1, 1, fp);
        }
        fread(&image[y * row_size], 1, padding, fp);
    }
}

// Function to write a BMP file
void write_bmp(FILE *fp, uint8_t *image, int width, int height) {
    int row_size = width * 3;
    uint8_t padding = 0;
    if ((row_size % 4) != 0) {
        padding = 4 - (row_size % 4);
        row_size += padding;
    }
    uint8_t header[54] = {0};
    header[0] = 'B';
    header[1] = 'M';
    header[2] = 54 + (row_size * height);
    header[10] = 54;
    header[14] = 40;
    header[18] = width & 0xff;
    header[19] = (width >> 8) & 0xff;
    header[20] = (width >> 16) & 0xff;
    header[21] = (width >> 24) & 0xff;
    header[22] = height & 0xff;
    header[23] = (height >> 8) & 0xff;
    header[24] = (height >> 16) & 0xff;
    header[25] = (height >> 24) & 0xff;
    header[26] = 1;
    header[28] = 24;
    fwrite(header, 1, 54, fp);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pos = (y * row_size) + (x * 3);
            fwrite(&image[pos + 2], 1, 1, fp);
            fwrite(&image[pos + 1], 1, 1, fp);
            fwrite(&image[pos], 1, 1, fp);
        }
        fwrite(&image[y * row_size], 1, padding, fp);
    }
}

// Function to flip the image horizontally
void flip_horizontal(uint8_t *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int pos1 = (y * width * 3) + (x * 3);
            int pos2 = (y * width * 3) + ((width - x - 1) * 3);
            uint8_t tempR = image[pos1];
            uint8_t tempG = image[pos1 + 1];
            uint8_t tempB = image[pos1 + 2];
            image[pos1] = image[pos2];
            image[pos1 + 1] = image[pos2 + 1];
            image[pos1 + 2] = image[pos2 + 2];
            image[pos2] = tempR;
            image[pos2 + 1] = tempG;
            image[pos2 + 2] = tempB;
        }
    }
}

// Main function
int main() {
    // Open the input file
    FILE *in_file = fopen("input.bmp", "rb");
    if (!in_file) {
        printf("Error: Unable to open input file\n");
        return 1;
    }
    // Read the input file header
    uint8_t header[54];
    fread(header, 1, 54, in_file);
    // Parse the image width and height from the header
    int width = header[18] + (header[19] << 8) + (header[20] << 16) + (header[21] << 24);
    int height = header[22] + (header[23] << 8) + (header[24] << 16) + (header[25] << 24);
    // Validate the image width and height
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image too large\n");
        return 1;
    }
    // Allocate memory for the image
    uint8_t *image = (uint8_t*)malloc(width * height * 3);
    if (!image) {
        printf("Error: Out of memory\n");
        return 1;
    }
    // Read the image data from the input file
    read_bmp(in_file, image, width, height);
    // Close the input file
    fclose(in_file);
    // Perform image manipulation
    flip_horizontal(image, width, height);
    // Open the output file
    FILE *out_file = fopen("output.bmp", "wb");
    if (!out_file) {
        printf("Error: Unable to open output file\n");
        return 1;
    }
    // Write the output file header
    fwrite(header, 1, 54, out_file);
    // Write the image data to the output file
    write_bmp(out_file, image, width, height);
    // Close the output file
    fclose(out_file);
    // Free the memory allocated for the image
    free(image);
    return 0;
}