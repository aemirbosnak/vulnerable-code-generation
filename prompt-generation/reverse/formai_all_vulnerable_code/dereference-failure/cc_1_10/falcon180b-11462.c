//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255

int main() {
    // Load image file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error loading image file\n");
        return 1;
    }

    // Read header information
    int header_size = 0;
    fread(&header_size, sizeof(int), 1, fp);
    char *header = malloc(header_size);
    fread(header, sizeof(char), header_size, fp);

    // Read image data
    int image_size = WIDTH * HEIGHT * 3;
    int row_size = WIDTH * 3;
    unsigned char *image_data = malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, fp);

    // Flip image horizontally
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int x = j;
            int y = HEIGHT - i - 1;
            int index = y * WIDTH + x;
            int new_index = i * WIDTH + j;
            unsigned char temp = image_data[index];
            image_data[index] = image_data[new_index];
            image_data[new_index] = temp;
        }
    }

    // Change brightness and contrast
    int brightness = 50;
    int contrast = 50;
    for (i = 0; i < image_size; i += 3) {
        int r = image_data[i] + brightness;
        int g = image_data[i + 1] + brightness;
        int b = image_data[i + 2] + brightness;
        int max_value = MAX_VALUE * contrast / 100;
        if (r > max_value) r = max_value;
        if (g > max_value) g = max_value;
        if (b > max_value) b = max_value;
        image_data[i] = r;
        image_data[i + 1] = g;
        image_data[i + 2] = b;
    }

    // Save modified image
    FILE *fp_out = fopen("modified_image.bmp", "wb");
    if (fp_out == NULL) {
        printf("Error saving modified image\n");
        return 1;
    }
    fwrite(header, sizeof(char), header_size, fp_out);
    fwrite(image_data, sizeof(unsigned char), image_size, fp_out);
    fclose(fp_out);
    fclose(fp);

    return 0;
}