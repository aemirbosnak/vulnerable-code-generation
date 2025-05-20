//FormAI DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define constants for image width and height
#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256

// Declare function for loading image from file
void load_image(char *filename, int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    FILE *f;
    f = fopen(filename, "rb");
    fseek(f, 54, SEEK_SET);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            int r = fgetc(f);
            int g = fgetc(f);
            int b = fgetc(f);
            int brightness = (r + g + b) / 3;
            image[i][j] = brightness;
        }
    }
    fclose(f);
}

// Declare function for saving image to file
void save_image(char *filename, int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    FILE *f;
    f = fopen(filename, "wb");
    // Write BMP header
    unsigned char bmp_file_header[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    unsigned char bmp_info_header[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int file_size = IMAGE_WIDTH * IMAGE_HEIGHT + 54;
    bmp_file_header[2] = (unsigned char)(file_size);
    bmp_file_header[3] = (unsigned char)(file_size >> 8);
    bmp_file_header[4] = (unsigned char)(file_size >> 16);
    bmp_file_header[5] = (unsigned char)(file_size >> 24);
    fwrite(bmp_file_header, 1, 14, f);
    fwrite(bmp_info_header, 1, 40, f);
    // Write image data
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            unsigned char b = (unsigned char)(image[i][j]);
            fwrite(&b, 1, 1, f);
        }
    }
    fclose(f);
}

// Declare function for applying a box filter to the image
void apply_box_filter(int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    int temp_image[IMAGE_HEIGHT][IMAGE_WIDTH];
    for (int i = 1; i < IMAGE_HEIGHT - 1; i++) {
        for (int j = 1; j < IMAGE_WIDTH - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[i + k][j + l];
                }
            }
            temp_image[i][j] = sum / 9;
        }
    }
    for (int i = 1; i < IMAGE_HEIGHT - 1; i++) {
        for (int j = 1; j < IMAGE_WIDTH - 1; j++) {
            image[i][j] = temp_image[i][j];
        }
    }
}

int main() {
    // Load input image
    int input_image[IMAGE_HEIGHT][IMAGE_WIDTH];
    load_image("input.bmp", input_image);

    // Apply box filter to input image
    apply_box_filter(input_image);

    // Save output image
    save_image("output.bmp", input_image);

    return 0;
}