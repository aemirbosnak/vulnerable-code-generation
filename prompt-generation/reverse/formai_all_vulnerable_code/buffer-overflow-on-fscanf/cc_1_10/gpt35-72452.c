//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function to flip an image
void flip_image(unsigned char *image, int width, int height) 
{
    for(int row = 0; row < height; row++) 
    {
        for(int col = 0; col < width / 2; col++) 
        {
            // Swap values of left and right pixels horizontally
            unsigned char temp = image[row * width + col];
            image[row * width + col] = image[row * width + (width - col - 1)];
            image[row * width + (width - col - 1)] = temp;
        }
    }
}

// Function to change the brightness and contrast of an image
void change_brightness_contrast(unsigned char *image, int width, int height, int brightness, int contrast)
{
    // Adjust brightness of each pixel
    for(int row = 0; row < height; row++) 
    {
        for(int col = 0; col < width; col++) 
        {
            int pixel = image[row * width + col];
            int adjusted_pixel = pixel + brightness;
            
            // Make sure pixel value is within 0-255 range
            if (adjusted_pixel < 0) adjusted_pixel = 0;
            if (adjusted_pixel > 255) adjusted_pixel = 255;

            // Adjust contrast of each pixel
            adjusted_pixel = (adjusted_pixel - 127) * contrast + 127;

            // Make sure pixel value is within 0-255 range
            if (adjusted_pixel < 0) adjusted_pixel = 0;
            if (adjusted_pixel > 255) adjusted_pixel = 255;
            
            image[row * width + col] = adjusted_pixel;
        }
    }
}

// Main function
int main(int argc, char *argv[]) 
{
    // Read input parameters from command line
    if (argc != 5) 
    {
        printf("Usage: %s input_file output_file brightness contrast\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);

    // Open input file and read image dimensions
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) 
    {
        printf("Error opening file %s\n", input_file);
        return 1;
    }

    int width, height;
    fscanf(fp, "P5\n%d %d\n255\n", &width, &height);

    // Allocate memory for input and output image
    unsigned char *input_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    fread(input_image, sizeof(unsigned char), width * height, fp);

    fclose(fp);

    // Flip the image horizontally
    flip_image(input_image, width, height);

    // Adjust brightness and contrast of the image
    change_brightness_contrast(input_image, width, height, brightness, contrast);

    // Write the output image to file
    fp = fopen(output_file, "wb");
    if (fp == NULL) 
    {
        printf("Error opening file %s\n", output_file);
        return 1;
    }

    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(input_image, sizeof(unsigned char), width * height, fp);

    fclose(fp);

    // Free memory
    free(input_image);

    return 0;
}