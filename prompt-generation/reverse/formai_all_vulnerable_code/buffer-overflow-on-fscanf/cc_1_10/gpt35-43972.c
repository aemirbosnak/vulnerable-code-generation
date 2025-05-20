//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to read image file
void read_image_file(FILE *file, int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fscanf(file, "%d", &image[x][y]);
        }
    }
}

// Function to write image file
void write_image_file(FILE *file, int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fprintf(file, "%d ", image[x][y]);
        }
        fprintf(file, "\n");
    }
}

// Function to flip image horizontally
void flip_horizontally(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int x, y, temp;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            temp                = image[x][y];
            image[x][y]         = image[width - x - 1][y];
            image[width - x - 1][y] = temp;
        }
    }
}

// Function to change image brightness
void change_brightness(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int brightness) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            image[x][y] += brightness;
            if (image[x][y] > 255) {
                image[x][y] = 255;
            } else if (image[x][y] < 0) {
                image[x][y] = 0;
            }
        }
    }
}

// Function to change image contrast
void change_contrast(int image[MAX_WIDTH][MAX_HEIGHT], int width, int height, float contrast) {
    int x, y;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            image[x][y] = (int)(factor * (image[x][y] - 128.0) + 128.0);
            if (image[x][y] > 255) {
                image[x][y] = 255;
            } else if (image[x][y] < 0) {
                image[x][y] = 0;
            }
        }
    }
}

// Main function
int main() {
    FILE *input_file, *output_file;
    int image[MAX_WIDTH][MAX_HEIGHT];
    int width, height, brightness;
    float contrast;

    // Read input image file
    input_file = fopen("input_image.txt", "r");
    fscanf(input_file, "%d %d", &width, &height);
    read_image_file(input_file, image, width, height);
    fclose(input_file);

    // Flip image horizontally
    flip_horizontally(image, width, height);

    // Change brightness of image
    brightness = 50;
    change_brightness(image, width, height, brightness);

    // Change contrast of image
    contrast = 50.0;
    change_contrast(image, width, height, contrast);

    // Write output image file
    output_file = fopen("output_image.txt", "w");
    fprintf(output_file, "%d %d\n", width, height);
    write_image_file(output_file, image, width, height);
    fclose(output_file);

    printf("Image processing complete.\n");

    return 0;
}