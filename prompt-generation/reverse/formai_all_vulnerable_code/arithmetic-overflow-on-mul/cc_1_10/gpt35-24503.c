//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

// Function to flip an image horizontally
void flip_horizontally(byte *img_data, int width, int height) {
    byte temp;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width/2; col++) {
            temp = img_data[row * width + col];
            img_data[row * width + col] = img_data[row * width + (width - col - 1)];
            img_data[row * width + (width - col - 1)] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(byte *img_data, int width, int height, int brightness) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int new_value = img_data[row * width + col] + brightness;
            if (new_value < 0) {
                img_data[row * width + col] = 0;
            } else if (new_value > 255) {
                img_data[row * width + col] = 255;
            } else {
                img_data[row * width + col] = (byte)new_value;   
            } 
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(byte *img_data, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int new_value = factor * (img_data[row * width + col] - 128) + 128;
            if (new_value < 0) {
                img_data[row * width + col] = 0;
            } else if (new_value > 255) {
                img_data[row * width + col] = 255;
            } else {
                img_data[row * width + col] = (byte)new_value;   
            } 
        }
    }
}

int main() {
    // Read image file
    FILE *fp = fopen("input_image.bin", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return 1;
    }
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    byte *img_data = (byte*)malloc(width * height * sizeof(byte));
    fread(img_data, sizeof(byte), width * height, fp);
    fclose(fp);

    // Flip the image horizontally
    flip_horizontally(img_data, width, height);

    // Adjust brightness by a value of 50
    adjust_brightness(img_data, width, height, 50);

    // Adjust contrast by a factor of 1.5
    adjust_contrast(img_data, width, height, 1.5);

    // Save the modified image to a file
    fp = fopen("output_image.bin", "wb");
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(img_data, sizeof(byte), width * height, fp);
    fclose(fp);

    free(img_data);
    return 0;
}