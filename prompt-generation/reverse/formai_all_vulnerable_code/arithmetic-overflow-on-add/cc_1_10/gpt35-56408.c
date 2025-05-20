//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BMP_HEADER_SIZE 54 // BMP header size is fixed at 54 bytes

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

// Function to read BMP file header
void read_bmp_header(FILE* input_file, int* width, int* height) {
    // Read BMP header information
    BYTE header[BMP_HEADER_SIZE];
    fread(header, sizeof(BYTE), BMP_HEADER_SIZE, input_file);
    
    // Extract image width and height from the header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
}

// Function to flip the BMP image horizontally
void flip_horizontal(BYTE* image_data, int width, int height) {
    // Calculate byte per row (BMP images are padded to be a multiple of 4 bytes)
    int row_size = width * 3;
    int padding = 0;
    if (row_size % 4 != 0) {
        padding = 4 - (row_size % 4);
        row_size += padding;
    }
    
    // Allocate memory for a row of pixels
    BYTE* row = (BYTE*)malloc(sizeof(BYTE) * row_size);

    // For each row, flip the pixels horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            // Calculate the corresponding pixel positions to swap
            int x1 = j * 3;
            int y1 = i * row_size;
            int x2 = (width - j - 1) * 3;
            int y2 = i * row_size;

            // Swap corresponding pixels using temporary pixel
            memcpy(row, &image_data[y1 + x1], 3 * sizeof(BYTE));
            memcpy(&image_data[y1 + x1], &image_data[y2 + x2], 3 * sizeof(BYTE));
            memcpy(&image_data[y2 + x2], row, 3 * sizeof(BYTE));
        }
    }

    // Free allocated memory
    free(row);
}

// Function to adjust the brightness of the BMP image
void adjust_brightness(BYTE* image_data, int width, int height, int brightness_level) {
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate the corresponding position in the image array
            int pos = i * width * 3 + j * 3;

            // Adjust the brightness of each color channel (R,G,B)
            for (int k = 0; k < 3; k++) {
                int val = (int)image_data[pos + k] + brightness_level;
                if (val > 255) {
                    val = 255;
                }
                else if (val < 0) {
                    val = 0;
                }
                image_data[pos + k] = (BYTE)val;
            }
        }
    }
}

// Function to adjust the contrast of the BMP image
void adjust_contrast(BYTE* image_data, int width, int height, float contrast_level) {
    // Calculate the scaling factor based on the contrast level, which is a float between -1 and 1
    float scaling_factor = (259.0 * (contrast_level + 255.0)) / (255.0 * (259.0 - contrast_level));

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate the corresponding position in the image array
            int pos = i * width * 3 + j * 3;

            // Adjust the contrast of each color channel (R,G,B)
            for (int k = 0; k < 3; k++) {
                float val = scaling_factor * ((int)image_data[pos + k] - 128.0) + 128.0;
                if (val > 255.0) {
                    val = 255.0;
                }
                else if (val < 0.0) {
                    val = 0.0;
                }
                image_data[pos + k] = (BYTE)val;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Check for valid input arguments
    if (argc != 4) {
        printf("Usage: %s <input_bmp_file> <output_bmp_file> <brightness_level>\n", argv[0]);
        return 1;
    }

    // Read input arguments
    char* input_file_name = argv[1];
    char* output_file_name = argv[2];
    int brightness_level = atoi(argv[3]);

    // Open input BMP file
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Cannot open input BMP file.\n");
        return 1;
    }

    // Read BMP file header
    int width, height;
    read_bmp_header(input_file, &width, &height);

    // Allocate memory for the image data
    BYTE* image_data = (BYTE*)malloc(sizeof(BYTE) * width * height * 3);

    // Read image data from input file
    fread(image_data, sizeof(BYTE), width * height * 3, input_file);
    fclose(input_file);

    // Flip the image horizontally
    flip_horizontal(image_data, width, height);

    // Adjust the brightness of the image
    adjust_brightness(image_data, width, height, brightness_level);

    // Adjust the contrast of the image
    adjust_contrast(image_data, width, height, 0.5);

    // Open output BMP file
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Cannot open output BMP file.\n");
        return 1;
    }

    // Write BMP header to output file
    BYTE header[BMP_HEADER_SIZE];
    memset(header, 0, BMP_HEADER_SIZE);
    memcpy(header, "BM", 2);
    *(int*)&header[0x1E] = 0;
    *(int*)&header[0x22] = 0;
    *(int*)&header[0x12] = width;
    *(int*)&header[0x16] = height;
    *(short int*)&header[0x1A] = 24;
    *(int*)&header[0x0A] = BMP_HEADER_SIZE + width * height * 3;
    fwrite(header, sizeof(BYTE), BMP_HEADER_SIZE, output_file);

    // Write image data to output file
    fwrite(image_data, sizeof(BYTE), width * height * 3, output_file);
    fclose(output_file);

    // Free allocated memory
    free(image_data);

    return 0;
}