//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scientific
// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void flip_horizontal(unsigned char* image, int width, int height);
void flip_vertical(unsigned char* image, int width, int height);
void adjust_brightness(unsigned char* image, int width, int height, int value);
void adjust_contrast(unsigned char* image, int width, int height, int value);

int main()
{
    // Read image file
    FILE* fp = fopen("sample_image.bmp", "rb");
    if (!fp) {
        printf("Error opening image file!\n");
        return 0;
    }
    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    // Allocate memory for image data
    int size = 3 * width * height;
    unsigned char* image = (unsigned char*)malloc(size);
    fread(image, sizeof(unsigned char), size, fp);
    fclose(fp);

    // Perform image processing tasks
    flip_horizontal(image, width, height);
    flip_vertical(image, width, height);
    adjust_brightness(image, width, height, 50);
    adjust_contrast(image, width, height, 30);

    // Write processed image to file
    FILE* fp_out = fopen("processed_image.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, fp_out);
    fwrite(image, sizeof(unsigned char), size, fp_out);
    fclose(fp_out);

    // Free allocated memory
    free(image);

    return 0;
}

// Flip image horizontally
void flip_horizontal(unsigned char* image, int width, int height)
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            for (int channel = 0; channel < 3; channel++) {
                int index1 = 3 * (row * width + col) + channel;
                int index2 = 3 * (row * width + (width - col - 1)) + channel;
                unsigned char temp = image[index1];
                image[index1] = image[index2];
                image[index2] = temp;
            }
        }
    }
}

// Flip image vertically
void flip_vertical(unsigned char* image, int width, int height)
{
    for (int row = 0; row < height / 2; row++) {
        for (int col = 0; col < width; col++) {
            for (int channel = 0; channel < 3; channel++) {
                int index1 = 3 * (row * width + col) + channel;
                int index2 = 3 * ((height - row - 1) * width + col) + channel;
                unsigned char temp = image[index1];
                image[index1] = image[index2];
                image[index2] = temp;
            }
        }
    }
}

// Adjust image brightness
void adjust_brightness(unsigned char* image, int width, int height, int value)
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int channel = 0; channel < 3; channel++) {
                int index = 3 * (row * width + col) + channel;
                int pixel = image[index] + value;
                if (pixel > 255) {
                    pixel = 255;
                }
                else if (pixel < 0) {
                    pixel = 0;
                }
                image[index] = (unsigned char)pixel;
            }
        }
    }
}

// Adjust image contrast
void adjust_contrast(unsigned char* image, int width, int height, int value)
{
    float factor = ((float)(259 * (value + 255))) / ((float)(255 * (259 - value)));
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int channel = 0; channel < 3; channel++) {
                int index = 3 * (row * width + col) + channel;
                int pixel = (int)(factor * (image[index] - 128) + 128);
                if (pixel > 255) {
                    pixel = 255;
                }
                else if (pixel < 0) {
                    pixel = 0;
                }
                image[index] = (unsigned char)pixel;
            }
        }
    }
}