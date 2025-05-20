//FormAI DATASET v1.0 Category: Image compression ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

/*
* This program demonstrates a simple image compression algorithm. 
* It reads in an image file called "input.ppm", converts it to grayscale, 
* then compresses it by only storing the difference between consecutive pixels.
* Finally, it saves the compressed image to a file called "output.dat".
*
* Author: [Your name here]
*/

int main(void) {
    FILE *input_file, *output_file;
    char format[3];
    int width, height, max_val, pixel_val, prev_val, diff_val;
    int i, j;
    
    // Open the input file
    input_file = fopen("input.ppm", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    // Read in the format of the image (P3 for ASCII, P6 for binary)
    fscanf(input_file, "%s", format);
    
    // Read in the width, height, and maximum pixel value of the image
    fscanf(input_file, "%d %d %d", &width, &height, &max_val);
    
    // Open the output file
    output_file = fopen("output.dat", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    
    // Write the width and height of the compressed image to the output file
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    
    // Read in each pixel of the image, convert it to grayscale, and compress it
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (strcmp(format, "P3") == 0) {
                // Read in the pixel value as RGB
                fscanf(input_file, "%d", &pixel_val);
                fscanf(input_file, "%d", &pixel_val);
                fscanf(input_file, "%d", &pixel_val);
            } else if (strcmp(format, "P6") == 0) {
                // Read in the pixel value as binary RGB
                fread(&pixel_val, sizeof(char), 3, input_file);
            }
            
            // Convert the pixel to grayscale
            pixel_val = (int)(0.2989 * (pixel_val >> 16) + 0.5870 * ((pixel_val >> 8) & 0xFF) + 0.1140 * (pixel_val & 0xFF));
            
            // Compress the pixel by storing the difference between it and the previous pixel
            if (j == 0) {
                // For the first pixel of each row, store the absolute value of the pixel value
                fwrite(&pixel_val, sizeof(char), 1, output_file);
            } else {
                // For subsequent pixels, store the difference between the current and previous pixel
                diff_val = abs(pixel_val - prev_val);
                fwrite(&diff_val, sizeof(char), 1, output_file);
            }
            
            // Update the previous pixel value
            prev_val = pixel_val;
        }
    }
    
    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}