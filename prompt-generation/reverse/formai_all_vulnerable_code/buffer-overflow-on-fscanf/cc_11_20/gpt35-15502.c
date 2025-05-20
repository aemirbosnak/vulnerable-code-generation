//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int width, height, maxval;
    char format[3];

    // Open input PPM file
    fptr = fopen("input.ppm", "rb");

    // Read file header
    fscanf(fptr, "%s\n%d %d\n%d\n", format, &width, &height, &maxval);

    // Allocate memory for image data
    unsigned char *data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    // Read image data
    fread(data, sizeof(unsigned char), width * height * 3, fptr);

    // Close input file
    fclose(fptr);

    // Create output file
    fptr = fopen("output.ppm", "wb");

    // Write file header
    fprintf(fptr, "%s\n%d %d\n%d\n", format, width, height, maxval);

    // Task1: Flip image horizontally
    unsigned char temp;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width/2; j++) {
            for(int k = 0; k < 3; k++) {
                temp = data[i*width*3 + j*3 + k];
                data[i*width*3 + j*3 + k] = data[i*width*3 + (width-j-1)*3 + k];
                data[i*width*3 + (width-j-1)*3 + k] = temp;
            }
        }
    }

    // Task2: Change brightness
    int brightness = 50;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
                int value = data[i*width*3 + j*3 + k] + brightness;
                if(value > maxval) value = maxval;
                if(value < 0) value = 0;
                data[i*width*3 + j*3 + k] = (unsigned char)value;
            }
        }
    }

    // Task3: Change contrast
    float contrast = 2.0;
    float factor = (259 * (contrast * maxval - maxval)) / (255 * (maxval - contrast * maxval));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
                int value = factor * (data[i*width*3 + j*3 + k] - 128) + 128;
                if(value > maxval) value = maxval;
                if(value < 0) value = 0;
                data[i*width*3 + j*3 + k] = (unsigned char)value;
            }
        }
    }

    // Write image data to output file
    fwrite(data, sizeof(unsigned char), width * height * 3, fptr);

    // Close output file
    fclose(fptr);

    // Free memory
    free(data);

    return 0;
}